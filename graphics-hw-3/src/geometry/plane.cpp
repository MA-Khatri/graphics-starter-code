#include "plane.hpp"

Hit Plane::trace(ray & inRay) {
    vec4 origin = (this->worldToModel).transform(inRay.origin);
    vec4 dir = (this->worldToModel).transform(inRay.direction);

    ray ray(origin, dir);

    float t0 = -origin.z/dir.z;
    Hit hit;
    if(t0 >= 0) {
        hit.t = t0;
        hit.pos = inRay.origin + (inRay.direction * t0);
        hit.modelSpacePos = origin + (dir * t0);
        hit.normal = this->getNormal(hit.pos, ray);
        hit.material = this->material;
        hit.brightness = 0;
        hit.inRay = inRay;
    }
    return hit;
}
vec4 Plane::getNormal(vec4 & pos, ray & inRay) {
    vec4 v(0,0,1,0);
    if(v.dot(inRay.direction) > 0) {
        v.z = -1;
    }
    vec4 normal = this->normalToWorld.transform(v);
    normal.w = 0;
    normal.normalize();
    return normal;
}