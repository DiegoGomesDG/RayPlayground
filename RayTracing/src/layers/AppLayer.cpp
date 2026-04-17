#include "layers/AppLayer.h"

#include "Application.h"
#include "imgui.h"
#include "material.h"
#include "Sphere.h"

AppLayer::AppLayer() {
    init_scene();
}

void AppLayer::on_event(Core::Event &event) {
    // Layer::on_event(event);
}

void AppLayer::on_update(float timestamp) {
    // Layer::on_update(timestamp);
}

void AppLayer::on_render() {

    // Render ImGui
    ImGui::Begin("Ray Tracer");

    ImGui::Text("Ray Tracer");

    ImGui::End();


}

void AppLayer::init_scene() {

    m_world = hittable_list();

    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    m_world.add(make_shared<Sphere>(point3(0,-1000,0), 1000, ground_material));
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_real();
            point3 center(a + 0.9*random_real(), 0.2, b + 0.9*random_real());
            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;
                if (choose_mat < 0.8) {
                    // diffuse
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<lambertian>(albedo);
                    m_world.add(make_shared<Sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    // metal
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_real(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    m_world.add(make_shared<Sphere>(center, 0.2, sphere_material));
                } else {
                    // glass
                    sphere_material = make_shared<dielectric>(1.5);
                    m_world.add(make_shared<Sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }
    auto material1 = make_shared<dielectric>(1.5);
    m_world.add(make_shared<Sphere>(point3(0, 1, 0), 1.0, material1));
    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    m_world.add(make_shared<Sphere>(point3(-4, 1, 0), 1.0, material2));
    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    m_world.add(make_shared<Sphere>(point3(4, 1, 0), 1.0, material3));

    m_camera = Camera();

    m_camera.aspect_ratio        = 16.0 / 9.0;
    m_camera.image_width         = 1280;
    m_camera.samples_per_pixel   = 10;
    m_camera.max_depth           = 5;

    m_camera.vfov        = 20;
    m_camera.lookfrom    = point3(13,2,3);
    m_camera.lookat      = point3(0,0,0);
    m_camera.vup         = vec3(0,1,0);

    m_camera.defocus_angle   = 0.6;
    m_camera.focus_dist      = 10.0;
}
