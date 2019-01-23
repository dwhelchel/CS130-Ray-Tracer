#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{

    Hit intersected;

    double a = dot(ray.direction, ray.direction);
    double b = 2 * dot(ray.direction, ray.endpoint - center);
    double c = dot(ray.endpoint - center, ray.endpoint - center) - (radius * radius);
    double discriminant = sqrt((b*b) - 4*a*c);
    double t1 = (-b + discriminant) / 2*a;
    double t2 = (-b - discriminant) / 2*a;

    if (discriminant >= 0 && t >= small_t) {
        if (t1 > t2) {
            intersected.object = this;
            intersected.dist = t2;
            intersected.part = part;
        }
        else if (t1 < t2) {
            intersected.object = this;
            intersected.dist = t1;
            intersected.part = part;
        }
    }
    else {
        intersected.object = NULL;
        intersected.dist = 0;
        intersected.part = part;
    }

    return intersected;
}

vec3 Sphere::Normal(const vec3& point, int part) const
{
    vec3 normal;
    TODO; // compute the normal direction
    return normal;
}

Box Sphere::Bounding_Box(int part) const
{
    Box box;
    TODO; // calculate bounding box
    return box;
}
