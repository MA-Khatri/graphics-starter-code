#include "groundGrid.hpp"

Color groundGrid::getColor(vec4 & pos) {
    float xPos = pos.x;
    float yPos = pos.y;
    double intPart;

    if(modf(xPos, &intPart) > .95 || modf(xPos, &intPart) < -.95 || modf(yPos, &intPart) > .95 || modf(yPos, &intPart) < -.95) {
        return green;
    }
    else if((modf(xPos, &intPart) >= 0 && modf(xPos, &intPart) < .05) || (modf(yPos, &intPart) >= 0 && modf(yPos, &intPart) < .05) || 
        (modf(xPos, &intPart) <= 0 && modf(xPos, &intPart) > -.05) || (modf(yPos, &intPart) <= 0 && modf(yPos, &intPart) > -.05)) 
    {
        return green;
    }
    else {
        return white;
    }
}

ray groundGrid::scatter(ray & inRay, vec4 & pos, vec4 & normal) {
    float theta = 2*PI*static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float phi = 2*PI*static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    vec4 randomDirection;
    randomDirection += normal.normalize();
    randomDirection.x += cos(phi) * sin(theta);
    randomDirection.y += sin(phi) * sin(theta);
    randomDirection.z += cos(theta);
    randomDirection.w = 0;
    
    ray outRay(pos+normal*EPSILON, randomDirection);
    return outRay;
}