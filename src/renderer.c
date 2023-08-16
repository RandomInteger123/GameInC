#include <renderer.h>
#include <compileShader.h>
#include <cglm\cglm.h>

struct Renderer Renderer;


// NO ERROR CHECKING, DO NOT SET SIZE = 0   !!!!!!!!!!!!!!!\

void submit(float* vertecies, u4 size)
{
    if(Renderer.size == 0)
    {
        Renderer.vertecies = (float* )malloc(size);
        for(int i = 1; i <= (size/4); i++)
        {
            Renderer.vertecies[i-1] = (vertecies[i-1]);
            printf("Catting vertecies: %d\n", i - 1);
        }
    }else
    {
        for(int i = 1; i <= (size/4); i++)
        {
            Renderer.vertecies = (float* )realloc(Renderer.vertecies ,size + Renderer.size);
            Renderer.vertecies[((Renderer.size)/4) + i - 1] = vertecies[i-1];
            printf("Catting vertecies2: %d\n", (((Renderer.size)/4) + i - 1));
        }
    }

    Renderer.size += size; 
    printf("Renderer.size: %d\n", Renderer.size);
}


void loadVerticies(u4 copyFlag, int VBOindex, int VAOindex)
{
    bindVAO(*(Renderer.VAO + VAOindex));
    bindVBO(*(Renderer.VBO + VBOindex));

    copyInVBO(Renderer.size, Renderer.vertecies, copyFlag);

            //USER DEFINED

    vertexAttribPointerF(0, 3, GL_FALSE, sizeof(float) * 3, NULL);
    glEnableVertexAttribArray(0);

            //USER DEFINED
    bindVAO(0);
    bindVBO(0);

}






void genVBO(int number)
{
    Renderer.VBO = (unsigned int*)malloc(number * sizeof(unsigned int));
    glGenBuffers(number, Renderer.VBO);
}

void genVAO(int number)
{
    Renderer.VAO = (unsigned int*)malloc(number * sizeof(unsigned int));
    glGenVertexArrays(number, Renderer.VAO);
}

void clearRendererData()
{
    Renderer.size = 0;
}
