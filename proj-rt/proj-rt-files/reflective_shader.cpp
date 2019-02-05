#include "reflective_shader.h"
#include "ray.h"
#include "render_world.h"

vec3 Reflective_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color;
    TODO; // determine the color
    // vec3 view = ray.endpoint - intersection_point;

    // color = (1-reflectivity)*color+reflectivity*world.Cast_Ray(reflected_ray, recursion_depth);
    return color;
}
