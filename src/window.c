#include <window.h>
#include <renderer.h>

GLFWwindow* window;
int windowWidth;
int windowHeight;


int initWindow(int major, int minor)
{
    if(glfwInit() != GLFW_TRUE)
    {
        Log("Error while initializing GLFW");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return 0;
}

int createWindow(int height, int width, const char* name)
{
    windowHeight = height;
    windowWidth = width;
    window  = glfwCreateWindow(width, height, name, NULL, NULL);
    if(window == NULL)
    {
        Log("Error while creating GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    return 0;
}

int initGlad()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Log("Error while initializing GLAD");
        return -1;
    }

    glViewport(0, 0, windowWidth, windowHeight);

}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    windowHeight = height;
    windowWidth = windowWidth;
    glViewport(0, 0, width, height);
} 







void Cleanup()
{
    glfwTerminate();
    glfwDestroyWindow(window);
    free(Renderer.vertecies);
    Log("Exiting... ");
}

void resizeScreenOnActionSet()
{
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
}

int getWindowHeight()
{
    return windowHeight;
}
int getWindowWidth()
{
    return windowWidth;
}
GLFWwindow* getWindowPtr()
{
    return window;
}



