#include "reflective_shader.h"
#include "ray.h"
#include "render_world.h"

vec3 Reflective_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color;
    TODO; // determine the color

    Ray reflection_ray;
    vec3 vDir = ray.endpoint - intersection_point;
    vec3 rDir = 2*dot(vDir, normal)*normal - vDir;
    reflection_ray = {intersection_point, rDir};

    vec3 rColor = world.Cast_Ray(reflection_ray, recursion_depth+1);                      ERROR HERE
    vec3 sColor = shader->Shade_Surface(ray, intersection_point, normal, recursion_depth);

    color = (1-reflectivity) * sColor + reflectivity * rColor;

    return color;
}
