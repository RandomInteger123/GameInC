#include <input.h>
#include <window.h>

struct InputStruct Input;

void key_callback(GLFWwindow* window, int fkey, int fscancode, int faction, int fmods)
{
    //DEBUG
    printf("%d\n", fkey);
    //DEBUG
    Input.keyboard.key = fkey;
    Input.keyboard.action = faction;
    Input.keyboard.scancode = fscancode;
    Input.keyboard.mods = fmods;

    if(Input.keyboard.action == GLFW_RELEASE)
    {
        Input.keyboard.key = -1;
        printf("Key released\n");
    }
}
 
 void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
 {
    Input.mouse.xpos = xpos;
    Input.mouse.ypos = ypos;
    printf("X:%lf\nY:%lf\n", xpos, ypos);
 }
