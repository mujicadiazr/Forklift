#ifndef OBJSCENE_H
#define OBJSCENE_H
#include <GL/gl.h>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QVector>
#include <QDebug>


class ObjScene  {
public:
    ObjScene(): m_dlistBase(0), m_dlistCount(0)
    {}

    ~ObjScene()
    {
        if (m_dlistBase)
            glDeleteLists(m_dlistBase, m_dlistCount);
    }

    virtual void transform() const
    {
        glScalef(m_scale, m_scale, m_scale);
        glTranslatef(-m_center.x, -m_center.y, -m_center.z);
    }

    virtual void draw() const
    {
        GLuint lastList = m_dlistBase + m_dlistCount;
        for (GLuint n = m_dlistBase; n < lastList; n++) {
            glCallList(n);
        }
    }

private:
    struct vec4 {
        vec4() { }
        vec4(float _x, float _y, float _z, float _w = 1.0f): x(_x), y(_y), z(_z), w(_w) { }

        float x, y, z, w;
    };

    struct vec3 {
        vec3() { }
        vec3(float _x, float _y, float _z): x(_x), y(_y), z(_z) { }

        float x, y, z;
    };

    struct vec2 {
        vec2() { }
        vec2(float _s, float _t): s(_s), t(_t) { }

        float s, t;
    };

    struct Material
    {
        QString name;
        vec4 ka, kd, ks;
        float ns;

        Material(): ka(0.1f, 0.1f, 0.1f, 1.0f), kd(1.0f, 1.0f, 1.0f, 1.0f), ks(0.0f, 0.0f, 0.0f, 0.0f), ns(20.0f)
        { }

        void bind()
        {
            glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat*)&ka);
            glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat*)&kd);
            glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat*)&ks);
            glMaterialf(GL_FRONT, GL_SHININESS, (GLfloat)ns);
        }
    };

    class MaterialLib
    {
        public:
            ~MaterialLib()
            {
                qDeleteAll(m_materials);
            }

            QString name() const
            {
                return m_name;
            }

            bool load(const QString& name, const QString& fileName)
            {
                QFile file(fileName);

                if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    return false;

                m_name = name;

                QRegExp newmtlPattern("^newmtl\\s(.*)(\\#.*)?");
                QRegExp kaPattern("^Ka\\s(.*)\\s(.*)\\s(.*)");
                QRegExp kdPattern("^Kd\\s(.*)\\s(.*)\\s(.*)");
                QRegExp ksPattern("^Ks\\s(.*)\\s(.*)\\s(.*)");
                QRegExp nsPattern("^Ns\\s(.*)");

                if (!m_materials.isEmpty()) {
                    qDeleteAll(m_materials);
                    m_materials.clear();
                }

                Material* current = NULL;
                while (!file.atEnd()) {
                    QString line = file.readLine().simplified();

                    if (line.contains(newmtlPattern)) {
                        current = new Material;
                        m_materials.append(current);
                        current->name = newmtlPattern.cap(1);
                    }
                    else if (line.contains(kaPattern)) {
                        Q_ASSERT(current);
                        current->ka = vec4(kaPattern.cap(1).toFloat(), kaPattern.cap(2).toFloat(), kaPattern.cap(3).toFloat());
                        qDebug()<<current->ka.x;
                    }
                    else if (line.contains(kdPattern)) {
                        Q_ASSERT(current);
                        current->kd = vec4(kdPattern.cap(1).toFloat(), kdPattern.cap(2).toFloat(), kdPattern.cap(3).toFloat());
                    }
                    else if (line.contains(ksPattern)) {
                        Q_ASSERT(current);
                        current->ks = vec4(ksPattern.cap(1).toFloat(), ksPattern.cap(2).toFloat(), ksPattern.cap(3).toFloat());
                    }
                    else if (line.contains(nsPattern)) {
                        Q_ASSERT(current);
                        current->ns = nsPattern.cap(1).toFloat();
                    }
                }

                return true;
            }

            Material* material(const QString& name)
            {
                foreach (Material* mat, m_materials) {
                    if (mat->name == name)
                        return mat;
                }
                return NULL;
            }

        private:
            QString m_name;
            QVector<Material*> m_materials;
    };

    struct Vertex
    {
        int pos;
        int normal;
        int texcoord;
    };

    struct Surface
    {
        Material* material;
        QVector< QVector<Vertex> > faces;
    };

    static float min(float a, float b)
    {
        return a < b ? a : b;
    }

    static float max(float a, float b)
    {
        return a > b ? a : b;
    }

    vec3 m_center;
    float m_scale;

    GLuint m_dlistBase, m_dlistCount;
public:
    void load(const QString & fileName)
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        if (m_dlistBase)
            glDeleteLists(m_dlistBase, m_dlistCount);

        QRegExp vertexPattern("^v\\s+(.*)\\s+(.*)\\s+(.*)");
        QRegExp normalPattern("^vn\\s+(.*)\\s+(.*)\\s+(.*)");
        QRegExp texcoordPattern("^vt\\s+(.*)\\s+(.*)(\\s+.*)?");
        QRegExp mtllibPattern("^mtllib\\s+(.*\\.mtl)");
        QRegExp usemtlPattern("^usemtl\\s+(.*)(\\#.*)?");

        QVector<vec3> vertices, normals;
        QVector<vec2> texcoords;
        QVector<MaterialLib*> materialLibs;
        QVector<Surface*> surfaces;

        vec3 vmin(1e10, 1e10, 1e10), vmax(-1e10, -1e10, -1e10);

        Material * defaultMaterial = new Material;
        MaterialLib * currentMaterialLib = NULL;
        Surface * currentSurface = new Surface;
        currentSurface->material = defaultMaterial;
        surfaces.append(currentSurface);

        while (!file.atEnd()) {
            QString line = file.readLine().simplified();

            if (line.isEmpty() || line.startsWith('#'))
                continue;

            if (line.contains(vertexPattern)) {
                vec3 v(vertexPattern.cap(1).toFloat(), vertexPattern.cap(2).toFloat(), vertexPattern.cap(3).toFloat());
                vertices.append(v);
                vmin.x = min(v.x, vmin.x);
                vmin.y = min(v.y, vmin.y);
                vmin.z = min(v.z, vmin.z);

                vmax.x = max(v.x, vmax.x);
                vmax.y = max(v.y, vmax.y);
                vmax.z = max(v.z, vmax.z);
            }

            else if (line.contains(normalPattern))
                normals.append(vec3(normalPattern.cap(1).toFloat(), normalPattern.cap(2).toFloat(), normalPattern.cap(3).toFloat()));

            else if (line.contains(texcoordPattern))
                texcoords.append(vec2(texcoordPattern.cap(1).toFloat(), texcoordPattern.cap(2).toFloat()));

            else if (line.startsWith("f ")) {
                QStringList faces = line.split(' ');

                QVector<Vertex> face;

                for (int i = 1; i < faces.size(); i++) {
                    QStringList indices = faces[i].split('/');

                    Vertex v;

                    v.pos = indices[0].toInt() -1;
                    if (v.pos < 0) v.pos += vertices.size() +1;
                    Q_ASSERT(v.pos >= 0 && v.pos < vertices.size());

                    if (indices.size() > 1 && !indices[1].isEmpty()) {
                        v.texcoord = indices[1].toInt() -1;
                        if (v.texcoord < 0) v.texcoord += texcoords.size() +1;
                        Q_ASSERT(v.texcoord >= 0 && v.texcoord < texcoords.size());
                    }
                    else
                        v.texcoord = -1;

                    if (indices.size() > 2) {
                        v.normal = indices[2].toInt() -1;
                        if (v.normal < 0) v.normal += normals.size() +1;
                        Q_ASSERT(v.normal >= 0 && v.normal < normals.size());
                    }
                    else
                        v.normal = -1;

                    face.append(v);
                }

                currentSurface->faces.append(face);
            }

            else if (line.contains(usemtlPattern)) {
                QString name = usemtlPattern.cap(1);

                Material* material = NULL;
                if (currentMaterialLib)
                    material = currentMaterialLib->material(name);

                if (!material) {
                    currentSurface = surfaces[0]; // default material
                }
                else {
                    currentSurface = NULL;
                    foreach (Surface* surf, surfaces) {
                        Q_ASSERT(surf != NULL);
                        Q_ASSERT(surf->material != NULL);

                        if (surf->material->name == name) {
                            currentSurface = surf;
                            break;
                        }
                    }

                    if (!currentSurface) {
                        currentSurface = new Surface;
                        currentSurface->material = material;
                        surfaces.append(currentSurface);
                    }
                }
            }

            else if (line.contains(mtllibPattern)) {
                QString name = mtllibPattern.cap(1);
                currentMaterialLib = NULL;
                foreach (MaterialLib* mtlLib, materialLibs) {
                    if (mtlLib->name() == name) {
                        currentMaterialLib = mtlLib;
                        break;
                    }
                }

                if (!currentMaterialLib) {
                    QFileInfo info(fileName);
                    QString mtlLibFileName = info.dir().filePath(name);

                    MaterialLib* mtlLib = new MaterialLib;
                    if (!mtlLib->load(name, mtlLibFileName)) {
                        qWarning("Could not open material file: %s", qPrintable(mtlLibFileName));
                        delete mtlLib;
                        continue;
                    }
                    materialLibs.append(mtlLib);
                    currentMaterialLib = mtlLib;
                }
            }
        }


        m_center.x = (vmax.x + vmin.x) * 0.5;
        m_center.y = (vmax.y + vmin.y) * 0.5;
        m_center.z = (vmax.z + vmin.z) * 0.5;

        m_scale = 1.0f / max(vmax.x - m_center.x, max(vmax.y - m_center.y, vmax.z - m_center.z));


        // create display lists
        if (surfaces[0]->faces.isEmpty())
            surfaces.remove(0);
        m_dlistCount = surfaces.size();
        m_dlistBase = glGenLists(m_dlistCount);

        for (GLuint n = 0; n < m_dlistCount; n++) {
            glNewList(m_dlistBase + n, GL_COMPILE);
            Surface* surf = surfaces[n];
            surf->material->bind();

            for (int face = 0; face < surf->faces.count(); face++) {
                QVector<Vertex> verts = surf->faces[face];

                glBegin(GL_POLYGON);
                for (int vert = 0; vert < verts.count(); vert++) {

                    if (verts[vert].texcoord >= 0)
                        glTexCoord2fv((GLfloat*)&texcoords[verts[vert].texcoord]);

                    if (verts[vert].normal >= 0)
                        glNormal3fv((GLfloat*)&normals[verts[vert].normal]);

                    glVertex3fv((GLfloat*)&vertices[verts[vert].pos]);
                }
                glEnd();
            }

            glEndList();
        }

        delete defaultMaterial;
        qDeleteAll(materialLibs);
        qDeleteAll(surfaces);
    }


};

#endif // OBJSCENE_H
