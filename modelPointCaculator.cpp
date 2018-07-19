#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "modelPointCaculator.h"


typedef glm::vec3 Vec3; // kiểu vector 3 chiều

modelPointCaculator::modelPointCaculator(
        float _xCamera, float _yCamera, float _zCamera,
        float _xRay, float _yRay, float _zRay)
        : posCamera(_xCamera, _yCamera, _zCamera),
          Ray(_xRay, _yRay, _zRay)

{}

Vec3 modelPointCaculator::getPoint() {

    Vec3 X = getIntersectionPoint();
    int plane = -1;
    for(int i = 0; i < 6; ++i)
        if (CheckPointonPlane(X, i)) {plane = i; break;}


    int n = vPoint.size();
    Vec3 ans = this->posCamera;
    float mindist = 1e9;

    for(int i = 0; i < n; ++i)
        if (CheckPointonPlane(vPoint[i], plane) && distance(X, vPoint[i]) < mindist) {
            mindist = distance(X, vPoint[i]);
            ans = vPoint[i];
        }

    return ans;
}



