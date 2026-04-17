#ifndef RAYTRACINGPROJECT_IIMAGE_H
#define RAYTRACINGPROJECT_IIMAGE_H

#include <cstdint>

namespace Core {
    class IImage {
    public:
        virtual ~IImage() = default;

        virtual void resize(std::uint32_t width, uint32_t height) = 0;
        virtual void set_data(const void* data) = 0;

        virtual uint32_t get_width() const = 0;
        virtual uint32_t get_height() const = 0;

        // ImGui Binding
        virtual void* get_imgui_texture_id() const = 0;
    };
}

#endif //RAYTRACINGPROJECT_IIMAGE_H
