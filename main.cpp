#include <bits/stdc++.h>

using namespace std;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "modelPointCaculator.h"

typedef glm::vec3 Vec3;

vector<Vec3> vPoint;

int main() {
    cout<<fixed<<setprecision(6);

    Vec3 CameraPos = Vec3(7.0f, 4.0f, 7.0f);
    Vec3 RayCamera = Vec3(1.0f, -2.0f, -2.0f);

    modelPointCaculator getpoint(CameraPos.x, CameraPos.y, CameraPos.z, RayCamera.x, RayCamera.y, RayCamera.z);

    vPoint.push_back(Vec3(5.0f, -1.0f, 3.0f));

    vPoint.push_back(Vec3(1.0f, 0.0f, 2.0f));
    vPoint.push_back(Vec3(3.0f, 0.0f, 3.0f));
    vPoint.push_back(Vec3(4.0f, 0.0f, 4.5f));

    vPoint.push_back(Vec3(0.0f, -5.0f, 2.0f));
    vPoint.push_back(Vec3(0.0f, -3.0f, 4.0f));

    vPoint.push_back(Vec3(5.0f, -3.0f, 0.0f));
    vPoint.push_back(Vec3(2.0f, -6.0f, 0.0f));

    float d = 10.0f;
    float pos = getpoint.getPoint(vPoint, d);
    Vec3 ans = vPoint[pos];

    cout<< ans.x <<' '<< ans.y <<' '<< ans.z <<'\n';

    return 0;
}