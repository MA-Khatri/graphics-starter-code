#include "rayTracer.hpp"

Image RayTracer::takePicture(Scene &scene, int camIndex)
{
    Image output;
    Camera cam = (*scene.cameras[camIndex]);
    output.width = cam.width;
    output.height = cam.height;
    for (int i = 0; i < output.width; i++)
    {
        for (int j = 0; j < output.height; j++)
        {
            Color c;
            output.pixels.push_back(c);
        }
    }

    // Number of samples per pixel
    // int sampleRate = 1000;
    int sampleRate = 100;

    //Start at the top right corner. Go left to right, top to bottom
    for (int j = (cam.height - 1); j >= 0; j--)
    {
        // TODO: This doesn't quite work right yet but I'll move on for now
        printf("\r%3f%%", (1.0 - float(j)/float(output.width)) * 100);

        for (int i = 0; i < (cam.width); i++)
        {
            Color c = output.getPixel(i, j);

            // Generate multiple randomized samples per pixel
            for (int k = 0; k < sampleRate; k++)
            {                
                float randX = 0.0;
                float randY = 0.0;
                if (sampleRate > 1)
                {
                    randX = float(rand())/float(RAND_MAX) - 0.5;
                    randY = float(rand())/float(RAND_MAX) - 0.5;
                }

                ray eyeRay = cam.getEyeRay(i + .5 + randX, j + .5 + randY);

                Hit hit;
                hit = this->traceRay(scene, eyeRay, hit, 0);

                c.r += hit.color.r / sampleRate;
                c.g += hit.color.g / sampleRate;
                c.b += hit.color.b / sampleRate;   
            }

            // Add gamma correction (this makes sure this matches with the provided result)
            c.r = (float)pow((double)c.r, 1 / 2.2);
            c.g = (float)pow((double)c.g, 1 / 2.2);
            c.b = (float)pow((double)c.b, 1 / 2.2);

            output.setPixel(i, j, c);
        }
    }

    printf("\n");

    return output;
}

Hit RayTracer::traceRay(Scene &scene, ray &eyeRay, Hit &hit, int depth)
{
    Hit closest = hit;
    for (Geometry *item : scene.items)
    {
        Hit current = item->trace(eyeRay);
        if (current.t < closest.t)
        {
            closest = current;
        }
    }
    this->findShade(scene, closest, depth);
    return closest;
}

void RayTracer::findShade(Scene &scene, Hit &hit, int depth)
{
    // missed
    if (hit.t > 1e10)
    {
        hit.color = scene.backgroundColor;
        hit.brightness = scene.ambientLight;
    }
    // hit
    else
    {
        Color hitColor = hit.material->getColor(hit.modelSpacePos);
        
        ray scatterRay = hit.material->scatter(hit.inRay, hit.pos, hit.normal);
        Hit scatterHit;

        if (depth < 10)
        {
            scatterHit = this->traceRay(scene, scatterRay, scatterHit, depth +1);

            hit.color.r += (scatterHit.brightness) * scatterHit.color.r * hitColor.r;
            hit.color.g += (scatterHit.brightness) * scatterHit.color.g * hitColor.g;
            hit.color.b += (scatterHit.brightness) * scatterHit.color.b * hitColor.b;
        }
    }
}