#pragma once
#include <common.h>

struct Shaders
{
    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int program;
};

extern struct Shaders Shaders;

int compileVertexShader(const char* shaderSourcePath);
int compileFragmentShader(const char* ShaderSourcePath);
void linkShaders();

