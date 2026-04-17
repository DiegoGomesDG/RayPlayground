#include "GLImage.h"

#include <glad/glad.h>

Core::GLImage::GLImage(uint32_t width, uint32_t height) {
    m_width = width;
    m_height = height;

    create_texture();
}

Core::GLImage::~GLImage() {
    destroy_texture();
}

void Core::GLImage::create_texture() {
    glGenTextures(1, &m_texture_id);
    glBindTexture(GL_TEXTURE_2D, m_texture_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA8,
        m_width,
        m_height,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        nullptr
    );

    glBindTexture(GL_TEXTURE_2D, 0);

}

void Core::GLImage::destroy_texture() {
    if (m_texture_id) {
        glDeleteTextures(1, &m_texture_id);
    }
    m_texture_id = 0;
}

void Core::GLImage::resize(std::uint32_t width, uint32_t height) {
    if (width == m_width && height == m_height)
        return;

    m_width = width;
    m_height = height;

    destroy_texture();
    create_texture();
}

void Core::GLImage::set_data(const void *data) {

    glBindTexture(GL_TEXTURE_2D, m_texture_id);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexSubImage2D(
        GL_TEXTURE_2D,
        0,
        0,
        0,
        m_width,
        m_height,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        data
    );

    glBindTexture(GL_TEXTURE_2D, 0);
}


