#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();
    void use();

private:
    unsigned int ID;
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif
