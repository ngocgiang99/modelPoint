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

float modelPointCaculator::distPointtoCameraRay(Vec3 A) {
    return abs(dot(this->Ray, A - posCamera)) / length(this->Ray);
}

int modelPointCaculator::getPoint(std::vector<Vec3> vPoint, float d) {
    int ans = -1;
    int n = vPoint.size();
    float dist = 1e9;

    for(int i = 0; i < n; ++i)
        if (distPointtoCameraRay(vPoint[i]) <= d) {
        float distP = distance(vPoint[i], posCamera);

        if (distP < dist) {
            dist = distP;
            ans = i;
        }
    }

    return ans;
}



