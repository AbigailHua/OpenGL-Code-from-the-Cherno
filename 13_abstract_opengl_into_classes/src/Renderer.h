#pragma once
#include <GL/glew.h>
#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
void GLCheckError();
bool GLLogCall(const char* function, const char* file, int line);
