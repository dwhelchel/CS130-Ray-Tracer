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
    color += ambient_component;
    for (unsigned int i = 0; i < world.lights.size(); ++i) {
        Light light = world.lights[i];
        Ray shadowRay;
        shadowRay.endpoint = intersection_point;
        shadowRay.direction = (light.position - intersection_point).normalized();
        // add if statement

    }
    return color;
}
