#pragma once
#include <GL/glew.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
void GLCheckError();
bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{
public:
    void Clear() const;

    /* If we want to eliminate setUniform in main(),
       we need to replace shader with material.
       In a traditional view, material = shader + data,
       so that we can set uniforms here.
    */
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;

};