#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <glad/glad.h>  // Include GLAD to get the OpenGL headers
#include <iostream>

class Texture {
public:
    Texture(const std::string& filePath);
    ~Texture();
    void bind(int offset) const;
    void unbind() const;
    unsigned int getID() const;

private:
    unsigned int textureID;
    std::string filePath;
    void loadTexture();
};

#endif
