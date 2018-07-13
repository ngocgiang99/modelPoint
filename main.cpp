#include <bits/stdc++.h>

using namespace std;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

typedef glm::vec3 Vec3;

const float block = 1000.0;
const float eps = 1e-6;

int cnt = 0;

Vec3 P[100000];

float xCamera, yCamera, zCamera;
float xRay, yRay, zRay;

Vec3 Point, Q;


Vec3 getPoint(Vec3 n, Vec3 CameraPos, Vec3 RayCamera) {
    if (dot(RayCamera, n) <= eps) return CameraPos;
    float t = -(dot(CameraPos - Q, n) / dot(RayCamera, n));

    return Vec3(CameraPos + t*RayCamera);
}

bool Check(Vec3 Point, int x) {
    if (abs(Point.x - xCamera) <= eps && abs(Point.y - yCamera) <= eps && abs(Point.z - zCamera) <= eps) return false;

    if (x == 1) return abs(Point.y) <= eps;
    if (x == 2) return abs(Point.z - block) <= eps;
    if (x == 3) return abs(Point.y + block) <= eps;
    if (x == 4) return abs(Point.z) <= eps;
    if (x == 5) return abs(Point.x) <= eps;
    if (x == 6) return abs(Point.x - block) <= eps;
}

Vec3 getIntersectionPoint(Vec3 CameraPos, Vec3 RayCamera) {


    if (yCamera > 0.0f) {
        Q = Vec3(block/2 , 0, block/2);
        Point = getPoint(Vec3(0.0,1.0,0.0), CameraPos, RayCamera);
        if (Check(Point,1)) return Point;

        if (xCamera > block) {
            Q = Vec3(block, -block/2, block/2);
            Point = getPoint(Vec3(1.0,0.0,0.0), CameraPos, RayCamera);
            if (Check(Point,6)) return Point;
        }

        if (xCamera < 0.0) {
            Q = Vec3(0.0, -block/2, block/2);
            Point = getPoint(Vec3(-1.0,0.0,0.0), CameraPos, RayCamera);
            if (Check(Point,5)) return Point;
        }

        if (zCamera > block) {
            Q = Vec3(block/2, -block/2, block);
            Point = getPoint(Vec3(0.0,0.0,1.0), CameraPos, RayCamera);
            if (Check(Point,2)) return Point;
        }

        if (zCamera < 0.0) {
            Q = Vec3(block/2, -block/2, block);
            Point = getPoint(Vec3(0.0,0.0,-1.0), CameraPos, RayCamera);
            if (Check(Point,4)) return Point;
        }
    }
    else if (yCamera >= -block) {
        if (xCamera > block) {
            Q = Vec3(block, -block/2, block/2);
            Point = getPoint(Vec3(1.0,0.0,0.0), CameraPos, RayCamera);
            if (Check(Point,6)) return Point;
        }

        if (xCamera < 0.0) {
            Q = Vec3(0.0, -block/2, block/2);
            Point = getPoint(Vec3(-1.0,0.0,0.0), CameraPos, RayCamera);
            if (Check(Point,5)) return Point;
        }

        if (zCamera > block) {
            Q = Vec3(block/2, -block/2, block);
            Point = getPoint(Vec3(0.0,0.0,1.0), CameraPos, RayCamera);
            if (Check(Point,2)) return Point;
        }

        if (zCamera < 0.0) {
            Q = Vec3(block/2, -block/2, block);
            Point = getPoint(Vec3(0.0,0.0,-1.0), CameraPos, RayCamera);
            if (Check(Point,4)) return Point;
        }
    }
    else {
        Q = Vec3(block/2, -block, block/2);
        Point = getPoint(Vec3(0.0,-1.0,0.0), CameraPos, RayCamera);
        if (Check(Point, 3)) return Point;

        if (xCamera > block) {
            Q = Vec3(block, -block/2, block/2);
            Point = getPoint(Vec3(1.0,0.0,0.0), CameraPos, RayCamera);
            if (Check(Point,6)) return Point;
        }

        if (xCamera < 0.0) {
            Q = Vec3(0.0, -block/2, block/2);
            Point = getPoint(Vec3(-1.0,0.0,0.0), CameraPos, RayCamera);
            if (Check(Point,5)) return Point;
        }

        if (zCamera > block) {
            Q = Vec3(block/2, -block/2, block);
            Point = getPoint(Vec3(0.0,0.0,1.0), CameraPos, RayCamera);
            if (Check(Point,2)) return Point;
        }

        if (zCamera < 0.0) {
            Q = Vec3(block/2, -block/2, block);
            Point = getPoint(Vec3(0.0,0.0,-1.0), CameraPos, RayCamera);
            if (Check(Point,4)) return Point;
        }
    }
}

float dist(Vec3 P1, Vec3 P2) {
    return distance(P1, P2);
}

Vec3 getans(Vec3 X) {
    float Mindist = 1e9;
    int pos = -1;
    for(int i = 0; i < cnt; ++i)
        if (Mindist > dist(P[i], X)) {
            pos = i;
            Mindist = dist(P[i], X);
        }
    cout<< Mindist <<endl;
    return P[pos];
}

void initPoint() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(-10.0, 10.0);

    cnt = 100;

    for(int i = 0; i < cnt; ++i) {
        P[i] = Vec3(dis(gen), dis(gen), dis(gen));
        //cout<< P[i].x <<' '<< P[i].y <<' '<< P[i].z <<endl;
    }
}

int main() {
    cout<<fixed<<setprecision(6);
    xCamera = 7.0f; yCamera = 4.0f; zCamera = 7.0f;
    xRay = 1.0f; yRay = 2.0f; zRay = 2.0f;


    Vec3 CameraPos = Vec3(xCamera, yCamera, zCamera);
    Vec3 RayCamera = Vec3(xRay, yRay, zRay);

    Vec3 X = getIntersectionPoint(CameraPos, RayCamera);

    initPoint();

    Vec3 ans = getans(X);


    //cout<< distance(Vec3(1,0,0), Vec3(0,1,0)) <<endl;


    cout<< X.x <<' '<< X.y <<' '<< X.z << '\n';
    cout<< ans.x <<' '<< ans.y <<' '<< ans.z <<'\n';

    return 0;
}