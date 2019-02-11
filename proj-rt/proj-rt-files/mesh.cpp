#include "mesh.h"
#include <fstream>
#include <string>
#include <limits>

// Consider a triangle to intersect a ray if the ray intersects the plane of the
// triangle with barycentric weights in [-weight_tolerance, 1+weight_tolerance]
static const double weight_tolerance = 1e-4;

// Read in a mesh from an obj file.  Populates the bounding box and registers
// one part per triangle (by setting number_parts).
void Mesh::Read_Obj(const char* file)
{
    std::ifstream fin(file);
    if(!fin)
    {
        exit(EXIT_FAILURE);
    }
    std::string line;
    ivec3 e;
    vec3 v;
    box.Make_Empty();
    while(fin)
    {
        getline(fin,line);

        if(sscanf(line.c_str(), "v %lg %lg %lg", &v[0], &v[1], &v[2]) == 3)
        {
            vertices.push_back(v);
            box.Include_Point(v);
        }

        if(sscanf(line.c_str(), "f %d %d %d", &e[0], &e[1], &e[2]) == 3)
        {
            for(int i=0;i<3;i++) e[i]--;
            triangles.push_back(e);
        }
    }
    number_parts=triangles.size();
}

// Check for an intersection against the ray.  See the base class for details.
Hit Mesh::Intersection(const Ray& ray, int part) const
{
    TODO;
    double distance = 0.0;

    if (part >= 0) {
        if (Intersect_Triangle(ray, part, distance)) {
            return {this, distance, part};
        }
    }
    else {
        for (int i = 0; i < triangles.size(); ++i) {
            if (Intersect_Triangle(ray, i, distance) && i != triangles.size()) {
                return {this, distance, i};
            }
        }
    }

    return {0, 0, 0};
}

// Compute the normal direction for the triangle with index part.
vec3 Mesh::Normal(const vec3& point, int part) const
{
    assert(part>=0);
    TODO;
    vec3 vertA = vertices[triangles[part][0]];
    vec3 vertB = vertices[triangles[part][1]];
    vec3 vertC = vertices[triangles[part][2]];
    vec3 vecAB = vertB - vertA;
    vec3 vecAC = vertC - vertA;
    vec3 crossed = cross(vecAB, vecAC).normalized();
    return crossed;
}

// This is a helper routine whose purpose is to simplify the implementation
// of the Intersection routine.  It should test for an intersection between
// the ray and the triangle with index tri.  If an intersection exists,
// record the distance and return true.  Otherwise, return false.
// This intersection should be computed by determining the intersection of
// the ray and the plane of the triangle.  From this, determine (1) where
// along the ray the intersection point occurs (dist) and (2) the barycentric
// coordinates within the triangle where the intersection occurs.  The
// triangle intersects the ray if dist>small_t and the barycentric weights are
// larger than -weight_tolerance.  The use of small_t avoid the self-shadowing
// bug, and the use of weight_tolerance prevents rays from passing in between
// two triangles.
bool Mesh::Intersect_Triangle(const Ray& ray, int tri, double& dist) const
{
    TODO;
    vec3 vertA = vertices[triangles[tri][0]];
    vec3 vertB = vertices[triangles[tri][1]];
    vec3 vertC = vertices[triangles[tri][2]];
    vec3 norm = Normal(v1, tri);

    Plane triPlane(v1, norm);
    Hit planeHit = triPlane.Intersection(ray, part);
    if (planeHit.obj == NULL || planeHit.dist < small_t) {
        return false;
    }

    vec3 point = ray.Point(triPlane.dist);
    vec3 triArea = 1/2 * cross(vertBA, vertCA).magnitude();
    vec3 lineCP = vertC - point;
    vec3 lineBP = vertB - point;
    vec3 lineAP = vertA - point;
    vec3 pbcArea = 1/2 * cross(lineBP, lineCP).magnitude();
    vec3 pcaArea = 1/2 * cross(lineAP, lineCP).magnitude();
    vec3 pabArea = 1/2 * corss(lineAP, lineBP).magnitude();

    double alpha = pbcArea / triArea;
    double beta = pcaArea / triArea;
    double gamma = pabArea / triArea;

    if (gamma >= -weight_tolerance && beta >= -weight_tolerance && alpha >= -weight_tolerance) {
        dist = planeHit.dist;
        return true;
    }

    return false;
}

// Compute the bounding box.  Return the bounding box of only the triangle whose
// index is part.
Box Mesh::Bounding_Box(int part) const
{
    Box b;
    TODO;
    return b;
}
