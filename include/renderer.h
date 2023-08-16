#pragma once
#include <common.h>


#define bindVBO(VBO); glBindBuffer(GL_ARRAY_BUFFER, VBO);
#define bindVAO(VAO); glBindVertexArray(VAO);

#define copyInVBO(size, vertices, flag); glBufferData(GL_ARRAY_BUFFER, size, vertices, flag);

#define vertexAttribPointerF(index, sizeOfAttribute, isNormalized, stride, offset ); glVertexAttribPointer(index, sizeOfAttribute, GL_FLOAT, isNormalized, stride, offset);

struct Renderer
{
    u4 size;
    unsigned int* VBO;
    unsigned int* VAO;
    float* vertecies;
};

extern struct Renderer Renderer;

void submit(float* verticies, u4 size);
void loadVerticies(u4 copyFlag, int VBOindex, int VAOindex);
void genVBO(int number);
void genVAO(int number);
void clearRendererData();





