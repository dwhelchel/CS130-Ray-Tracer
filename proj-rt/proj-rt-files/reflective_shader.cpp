#include "reflective_shader.h"
#include "ray.h"
#include "render_world.h"

vec3 Reflective_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color;
    TODO; // determine the color
    vec3 vDir = ray.direction - intersection_point;
    vec3 rDir = 2*dot(vDir, normal)*normal - vDir;
    vec3 sColor = shader->Shade_Surface(ray, intersection_point, normal, recursion_depth);

    Ray rRay = {intersection_point, rDir};

    color = (1-reflectivity) * sColor + reflectivity * world.Cast_Ray(rRay, recursion_depth);
    return color;
}
