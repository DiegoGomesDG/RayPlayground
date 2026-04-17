#include "layers/VoidLayer.h"

#include "layers/AppLayer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Application.h"

void VoidLayer::on_update(float timestamp) {
    // transition_to<AppLayer>();
}

void VoidLayer::on_render() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

