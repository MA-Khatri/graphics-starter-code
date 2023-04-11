#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include "../math/mat4.hpp"
#include "../hit.hpp"
#include "../math/vec4.hpp"
#include "../materials/material.hpp"
#include "../materials/baseMaterial.hpp"
#include "../materials/groundGrid.hpp"

enum class GeometryType {none, plane, sphere, square, mesh, triangle, bvh};
class Hit;

class Geometry {
public:
    GeometryType type = GeometryType::none;

    mat4 modelMatrix;
    mat4 worldToModel;
    mat4 normalToWorld;

    Material* material;

    void setMaterial(Material & m);
    virtual vec4 getNormal(vec4 & pos, ray & inRay) = 0;

    void setIdentity() {
        modelMatrix.setIdentity();
        worldToModel.setIdentity();
        normalToWorld.setIdentity();
    }

    void translate(vec4 & v);
    void rotate(float angle, vec4 & axis);
    void scale(vec4 & v);

    virtual Hit trace(ray & inRay) = 0;
    virtual ~Geometry() {}
};

#endif