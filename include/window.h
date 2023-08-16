#pragma once
#include <common.h>
// Major and minor version of OpenGL
int initWindow(int major, int minor);
int createWindow(int height, int width, const char* name);
int initGlad();
void resizeScreenOnActionSet();
int getWindowHeight();
int getWindowWidth();
GLFWwindow* getWindowPtr();
void Cleanup();





