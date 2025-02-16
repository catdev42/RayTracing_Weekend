#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

// LERP:
// blendedValue=(1−a)⋅startValue+a⋅endValue,

color ray_color(const ray &r)
{
	vec3 unit_direction = unit_vector(r.direction());
	auto a = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main()
{
	auto aspect_ration = 16.0 / 9.0;
	int image_width = 400;

	int image_height = int(image_width / aspect_ration);
	image_height = (image_height < 1 ) ? 1 :image_height;

	auto focal_length = 1.0;
	auto viewport_height = 2.0;
	auto viewport_width = viewport_height *(double(image_width)/ image_height);
	auto camera_center = point3(0, 0, 0);

	auto viewport_u = vec3(viewport_width, 0,0);
	auto viewport_v = vec3(0, -viewport_height, 0);

	auto pixel_delta_u = viewport_u / image_width;
	auto pixe_delta_v = viewport_v / image_height;

	

}
