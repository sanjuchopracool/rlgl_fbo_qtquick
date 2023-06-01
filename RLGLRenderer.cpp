#include "RLGLRenderer.h"

#include <iostream>
#include <mutex>
#include <rlgl.h>

std::once_flag flag;
RLGLRenderer::RLGLRenderer()
{

}

void RLGLRenderer::initialize(int width, int height)
{
    std::cout << width << "x" << height << std::endl; //dpi is handled by qt
    std::call_once(flag, [=](){
        rlLoadExtensions(nullptr);
    });
    rlglInit(width, height);
}

void RLGLRenderer::render()
{
    rlClearColor(255, 255, 0, 255);
    rlClearScreenBuffers();             // Clear current framebuffer
}
