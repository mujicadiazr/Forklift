#ifndef TEXTURE_H
#define TEXTURE_H

#ifdef WIN32
#include "includeWin32/glut.h"
#else
#include "includeUnix/glut.h"
#endif

class Texture
{
public:
    Texture();
    GLubyte	*imageData;		// Image Data (Up To 32 Bits)
    GLuint	bpp;			// Image Color Depth In Bits Per Pixel.
    GLuint	width;			// Image Width
    GLuint	height;                 // Image Height
    GLuint	texID;                  // Id
};

#endif // TEXTURE_H
