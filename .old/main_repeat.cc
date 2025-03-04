#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

// LERP:
// blendedValue=(1−a)⋅startValue+a⋅endValue,

// color ray_color(const ray &r)
// {
// 	vec3 unit_direction = unit_vector(r.direction());
// 	auto a = 0.5 * (unit_direction.y() + 1.0);
// 	return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
// }

/* Finding solution for quadratic function
How does (C-P) * (C-P) = (Cx−x)^2+(Cy−y)^2+(Cz−z)^2 == r^2
turn into
become this:
a=d⋅d 
b=−2d⋅(C−Q)
c=(C−Q)⋅(C−Q)−r^2
ok
*/
bool hit_sphere(const point3 &center, double radius, const ray &r)
{
	// vector from origin to center of sphere
	vec3 oc = center - r.origin();
	//SCALAR get squared len of vector - dot product
	/*Doct porduct of two vectors  ==
	  length^2 of the length of the vector ==

	  */
	auto a = dot(r.direction(), r.direction()); 
	//SCALAR effect of direction vector on vector from ray origin to sphere center 
	auto b = -2.0 * dot(r.direction(), oc);
	//SCALAR radius * radius gives a vector that is
			// (0,0,-2)
	auto c = dot(oc, oc) - radius * radius;
	//this tells us if there are any solutions cause
	//if the value is negative, there are none.
	auto discriminant = b*b + 4*a*c; //if b is bigger, will circle be smaller
	return (discriminant >= 0);
}

color ray_color(const ray &r)
{
	// gives squere dimentions center and radius, + ray info
	if (hit_sphere(point3(0, 0, -1), 0.5, r))
		return color(1, 0, 0);
		
	vec3 unit_direction = unit_vector(r.direction());
	auto a = 0.5 * (unit_direction.y + 1.0);
	return (1.0 - a) * color(1, 1, 1) + a * color(0.5, 0.7, 1.0);
}

int main()
{

	// Image

	auto aspect_ratio = 16.0 / 9.0;
	int image_width = 1000;

	// Calculate the image height, and ensure that it's at least 1.
	int image_height = int(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;

	// Camera

	auto focal_length = 1.0;
	auto viewport_height = 2.0;
	auto viewport_width = viewport_height * (double(image_width) / image_height);
	auto camera_center = point3(0, 0, 0);

	// Calculate the vectors across the horizontal and down the vertical viewport edges.
	auto viewport_u = vec3(viewport_width, 0, 0);
	auto viewport_v = vec3(0, -viewport_height, 0);

	// Calculate the horizontal and vertical delta vectors from pixel to pixel.
	auto pixel_delta_u = viewport_u / image_width;
	auto pixel_delta_v = viewport_v / image_height;

	// Calculate the location of the upper left pixel.
	auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
	auto viewport_upper_lef2 = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
	//                           vec3(0,0,0) - vec3(0,0,1)            - 3.55/2, 0, 0   - (0, -2/2, 0);
	//							 (-1.775, 1, -1)
	auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

	// Render

	std::cout << "P3\n"
			  << image_width << " " << image_height << "\n255\n";

	for (int j = 0; j < image_height; j++)
	{
		std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
		for (int i = 0; i < image_width; i++)
		{
			auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
			auto ray_direction = pixel_center - camera_center;
			ray r(camera_center, ray_direction);

			color pixel_color = ray_color(r);
			write_color(std::cout, pixel_color);
		}
	}

	std::clog << "\rDone.                 \n";
}