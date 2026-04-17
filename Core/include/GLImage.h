#ifndef RAYTRACINGPROJECT_GLIMAGE_H
#define RAYTRACINGPROJECT_GLIMAGE_H

#include "IImage.h"

namespace Core {
    class GLImage : public IImage {
    public:
        GLImage(uint32_t width, uint32_t height);
        ~GLImage();

        void resize(std::uint32_t width, uint32_t height) override;

        void set_data(const void *data) override;

        uint32_t get_width() const override { return m_width; }

        uint32_t get_height() const override { return m_height; }

        void * get_imgui_texture_id() const override { return (void*)(intptr_t) m_texture_id; };
    private:
        void create_texture();
        void destroy_texture();
    private:
        uint32_t m_texture_id = 0;
        uint32_t m_width = 0, m_height = 0;
    };
}

#endif //RAYTRACINGPROJECT_GLIMAGE_H
