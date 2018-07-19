#include <bits/stdc++.h>

using namespace std;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "modelPointCaculator.h"

typedef glm::vec3 Vec3;

int main() {
    cout<<fixed<<setprecision(6);

    Vec3 CameraPos = Vec3(7.0f, 4.0f, 1.0f);
    Vec3 RayCamera = Vec3(1.0f, -2.0f, 2.0f);

    modelPointCaculator getpoint(CameraPos.x, CameraPos.y, CameraPos.z, RayCamera.x, RayCamera.y, RayCamera.z);
    getpoint.setPlane(2, 0.0f, 1.0f, 0.0f); getpoint.setcstPoint(2, 5.0f, 0.0f, 5.0f);
    getpoint.setPlane(1, 0.0f, 0.0f, 1.0f); getpoint.setcstPoint(1, 5.0f, -5.0f, 10.0f);
    getpoint.setPlane(0, 0.0f, -1.0f, 0.0f); getpoint.setcstPoint(0, 5.0f, -10.0f, 5.0f);
    getpoint.setPlane(3, 0.0f, 0.0f, -1.0f); getpoint.setcstPoint(3, 5.0f, -5.0f, 0.0f);
    getpoint.setPlane(4, -1.0f, 0.0f, 0.0f); getpoint.setcstPoint(4, 0.0f, -5.0f, 5.0f);
    getpoint.setPlane(5, 1.0f, 0.0f, 0.0f); getpoint.setcstPoint(5, 10.0f, -5.0f, 5.0f);

    Vec3 X = getpoint.getIntersectionPoint();

    getpoint.insertPoint(5.0f, -1.0f, 3.0f);

    getpoint.insertPoint(1.0f, 0.0f, 2.0f);
    getpoint.insertPoint(3.0f, 0.0f, 3.0f);
    getpoint.insertPoint(4.0f, 0.0f, 4.5f);

    getpoint.insertPoint(0.0f, -5.0f, 2.0f);
    getpoint.insertPoint(0.0f, -3.0f, 4.0f);

    getpoint.insertPoint(5.0f, -3.0f, 0.0f);
    getpoint.insertPoint(2.0f, -6.0f, 0.0f);

    Vec3 ans = getpoint.getPoint();


    cout<< X.x <<' '<< X.y <<' '<< X.z << '\n';
    cout<< ans.x <<' '<< ans.y <<' '<< ans.z <<'\n';

    return 0;
}