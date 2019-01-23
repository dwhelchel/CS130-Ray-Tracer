#include "sphere.h"
#include "ray.h"

// Determine if the ray intersects with the sphere
Hit Sphere::Intersection(const Ray& ray, int part) const
{

    Hit intersected;

    double a = dot(ray.direction, ray.direction);
    double b = 2 * dot(ray.direction, ray.endpoint - this->center);
    double c = dot(ray.endpoint - this->center, ray.endpoint - this->center) - (this->radius * this->radius);
    double discriminant = sqrt((b*b) - 4*a*c);

    if (discriminant >= 0) {
        double t = (-b + discriminant) / 2*a;
        intersected.object = this;
        intersected.dist = t;
        intersected.part = part;
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
