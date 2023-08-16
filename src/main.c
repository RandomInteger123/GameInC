#include <window.h>
#include <input.h>
#include <compileShader.h>
#include <renderer.h>


void Log(char* x){printf("%s", x);} // Logs x to the console

float vertecies[] = {
    -0.5f, 0.5f, 0.0f,
    0.5f, 0.0f, 0.0f,
    -0.5f, 0.0f, 0.0f
};

float vertecies2[] = {
    -0.5f, 0.5f, 0.0f,
    0.5f, 0.0f, 0.0f,
    0.5f,  0.5f, 0.0f
}; 

int main()
{
    initWindow(3,3);
    createWindow(800, 800, "Learn OpenGL");
    initGlad();

    resizeScreenOnActionSet();

    setKeyCallback(getWindowPtr(), key_callback);
    setCursorPositionCallback(getWindowPtr(), cursor_position_callback);

    compileVertexShader("C:\\Programming\\C\\GameInC\\shaders\\vertexShader.glsl");
    compileFragmentShader("C:\\Programming\\C\\GameInC\\shaders\\fragmentShader.glsl");
    linkShaders();

    genVBO(1);
    genVAO(1);

    submit(vertecies, sizeof(vertecies));
    submit(vertecies2, sizeof(vertecies2));

    loadVerticies(GL_STATIC_DRAW, 0, 0);

    

    while(!glfwWindowShouldClose(getWindowPtr()))
    {
        glClearColor(1.00f, 1.00f, 1.00f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);


        glUseProgram(Shaders.program);
        bindVAO(*(Renderer.VAO))
        glDrawArrays(GL_TRIANGLES, 0, ((Renderer.size/4)/3));






        glfwSwapBuffers(getWindowPtr());
        glfwPollEvents();    
    }

    return 0;
}

