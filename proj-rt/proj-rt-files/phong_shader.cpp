#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& normal,int recursion_depth) const
{
    vec3 color;
    TODO; //determine the color
    vec3 ambient_component = color_ambient * world.ambient_color * world.ambient_intensity;
    vec3 specular_component, diffuse_component = {0, 0, 0};
    color += ambient_component;
    for (auto l : world.lights) {
        Ray shadowRay(intersection_point, l->position - intersection_point);
        vec3 lDir = l->position - intersection_point;
        vec3 rDir = ray.direction - 2 * (dot(ray.direction, normal)) * normal;
        // do if statement here
        diffuse_component = color_diffuse * l->Emitted_Light(lDir) * std::max(dot(normal, shadowRay.direction), 0.0);
        specular_component = color_specular * l->Emitted_Light(lDir) * std::pow(std::max(dot(ray.direction, rDir), 0.0), specular_power);
        color += diffuse_component;
        color += specular_component;
    }
    return color;
}
