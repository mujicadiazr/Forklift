#ifndef TGA_H
#define TGA_H
#include "texture.h"

class TGA
{
public:
    TGA();
    Texture textures[1];
    bool LoadTGA(Texture*, char*);
};

#endif // TGA_H
