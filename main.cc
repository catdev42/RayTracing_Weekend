#include "rtweekend.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

int main()
{
	hittable_list world;

	// auto material_left = make_shared<metal>(color(0.8, 0.8, 0.8));
	// // auto material_right = make_shared<metal>(color(0.8, 0.6, 0.2));
	// auto material_right = make_shared<metal>(color(0.0, 0.1, 0.1));

	auto material_ground = make_shared<lambertian>(color(0.5, 0.5, 0.5));
	auto material_center = make_shared<lambertian>(color(0.5, 0.5, 0.5));

	// auto material_left = make_shared<metal>(color(0.8, 0.8, 0.8), 2.3);
	// auto material_right = make_shared<metal>(color(0.8, 0.6, 0.2), 1.0);

	world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
	world.add(make_shared<sphere>(point3(0.0, 0.0, -1), 0.5, material_center));
	// world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
	// world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, material_right));

	// world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
	// world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

	camera cam;

	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 800;
	cam.samples_per_pixel = 100;
	cam.max_depth = 50;

	cam.render(world);
}