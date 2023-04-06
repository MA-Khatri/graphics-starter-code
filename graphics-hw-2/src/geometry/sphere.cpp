#include "sphere.hpp"

#include <iostream>

//implement these two functions
Hit Sphere::trace(ray & inRay) {
    vec4 origin = (this->worldToModel).transform(inRay.origin);
    vec4 dir = (this->worldToModel).transform(inRay.direction);

    ray ray(origin, dir);

    vec4 center(0,0,0,1);

    Hit hit;

    /* Implementing the half-chord sphere-intersection method from cs351-2 */
    // Ray to (center of) sphere vector
    vec4 r2s = center - origin;
    float L2 = r2s.length_squared();

    // Distance along the ray to the midpoint of the chord
    float tcaS = dir.dot(r2s);

    // If the ray origin is outside the sphere and the sphere is behind the ray origin,
    // the ray misses the sphere
    if (L2 > 1.0 && tcaS < 0) {
        return hit; // empty hit
    }

    float DL2 = dir.length_squared();

    // distance^2 from ray origin to midpoint of chord
    float tca2 = (tcaS * tcaS) / DL2;

    //distance^2 from sphere center to midpoint of chord
    float LM2 = L2 - tca2;

    // If shortest distance^2 from ray to sphere center is > radius^2, ray misses sphere
    if (LM2 > 1.0) {
        return hit; // empty hit
    }

    // squared half-chord length
    float L2hc = 1.0 - LM2;

    // We only return the first hit along the ray!
    float t0 = (tcaS / DL2) - sqrt(L2hc / DL2);

    hit.t = t0;
    hit.pos = inRay.origin + (inRay.direction * t0);
    hit.modelSpacePos = ray.origin + (ray.direction * t0);
    hit.normal = this->getNormal(hit.modelSpacePos, ray);
    hit.inRay = inRay;

    return hit;
}

vec4 Sphere::getNormal(vec4 & pos, ray & inRay) {
    vec4 normVec(pos.x, pos.y, pos.z, 0);
    normVec = this->normalToWorld.transform(normVec);
    return normVec;
}