#include "utils.h"

#include "Camera.h"
#include "hittable_list.h"
#include "Sphere.h"

#include <chrono>
#include <iostream>

#include "Application.h"
#include "material.h"
#include "layers/VoidLayer.h"

int main(int argc, char *argv[]) {

    Core::ApplicationSpecification appSpec;
    appSpec.name                    = "RayTracer";
    appSpec.settings.width          = 1280;
    appSpec.settings.height         = 720;
    appSpec.settings.is_resizable   = false;

    Core::Application app(appSpec);
    app.push_layer<VoidLayer>();
    app.run();





    const auto start = std::chrono::high_resolution_clock::now();

    hittable_list world;

    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<Sphere>(point3(0,-1000,0), 1000, ground_material));
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
                    world.add(make_shared<Sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    // metal
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_real(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<Sphere>(center, 0.2, sphere_material));
                } else {
                    // glass
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<Sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }
    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<Sphere>(point3(0, 1, 0), 1.0, material1));
    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<Sphere>(point3(-4, 1, 0), 1.0, material2));
    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<Sphere>(point3(4, 1, 0), 1.0, material3));

    Camera cam;

    cam.aspect_ratio        = 16.0 / 9.0;
    cam.image_width         = 1280;
    cam.samples_per_pixel   = 100;
    cam.max_depth           = 50;

    cam.vfov        = 20;
    cam.lookfrom    = point3(13,2,3);
    cam.lookat      = point3(0,0,0);
    cam.vup         = vec3(0,1,0);

    cam.defocus_angle   = 0.6;
    cam.focus_dist      = 10.0;

    cam.render(world);

    const auto end = std::chrono::high_resolution_clock::now();

    /* Compute duration in seconds */
    const std::chrono::duration<double> elapsed = end - start;
    std::cout << "Total Render Time: " << elapsed.count() << " seconds\n";

    return 0;
}
