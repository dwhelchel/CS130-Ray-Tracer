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
    vec3 ambient_component = color_ambient * world_input.ambient_color * world_input.ambient_intensity;
    color += ambient_component;
    for (unsigned int i = 0; i < world_input.lights.size(); ++i) {
        Light light = lights[i];
        Ray shadowRay;
        shadowRay.endpoint = intersection_point;
        shadowRay.direction = light.position - intersection_point;
        // add if statement

    }
    return color;
}
