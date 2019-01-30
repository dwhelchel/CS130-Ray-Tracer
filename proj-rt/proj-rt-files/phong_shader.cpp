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
    for (unsigned int i = 0; i < world.lights.size(); ++i) {
        Ray shadowRay = Ray(world.lights[i]->position, world.lights[i]->position - intersection_point);
        // do if statement here
        // diffuse_component = color_diffuse * world.lights[i]->Emitted_Light(shadowRay.direction) * std::max(dot(normal, shadowRay.direction), 0.0);
        // specular_component = color_specular * world.lights[i].Emitted_Light() * max(, 0);
        color += diffuse_component;
        color += specular_component;
    }
    return color;
}
