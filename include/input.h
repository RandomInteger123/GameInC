#pragma once
#include <common.h>

#define setKeyCallback(window, key_callback); glfwSetKeyCallback(window, key_callback);
#define setCursorPositionCallback(window, cursor_position_callback); glfwSetCursorPosCallback(window, cursor_position_callback);

struct keyboard
{
    int key;
    int scancode;
    int action;
    int mods;
};
struct mouse
{
    double xpos;
    double ypos;
};

struct InputStruct
{
    struct keyboard keyboard;
    struct mouse mouse;
};

extern struct InputStruct Input;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);