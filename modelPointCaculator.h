

#ifndef MODELPOINT_MODELPOINTCACULATOR_H
#define MODELPOINT_MODELPOINTCACULATOR_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

typedef  glm::vec3 Vec3;


class modelPointCaculator {
protected:
    Vec3 Ray, posCamera; // Vị trí Camera và tia chiếu từ Camera
    Vec3 nRayplane[6]; // Vector pháp của 6 mặt model
    Vec3 cstPoint[6]; // tọa độ 1 điểm tương ứng trên 6 mặt model
    const float eps =1e-6;
    std::vector<Vec3> vPoint; // Tập các điểm nằm trên mặt model



public:
    /*
     * Khới tạo tọa độ Camera và Ray
     */
    modelPointCaculator(
            float _xCamera, float _yCamera, float _zCamera,
            float _xRay, float _yRay, float _zRay);

    ~modelPointCaculator() {};

    // Lấy kết quả
    Vec3 getPoint();

    // Khởi tạo mặt phẳng của model
    void setPlane(int i, float _x, float _y, float _z) {
            nRayplane[i] = Vec3(_x, _y, _z);
    }

    // Khởi tạo 1 điểm bất kì tương ứng với mặt phẳng
    void setcstPoint(int i, float _x, float _y, float _z) {
        cstPoint[i] = Vec3(_x, _y, _z);
    }

    // Thêm 1 điểm vào model
    void insertPoint(float _x, float _y, float _z) {
        vPoint.push_back(Vec3(_x, _y, _z));
    }


    // Lấy giao của model và Ray
    Vec3 getPointonPlane(int iplane) {
        if (abs(dot(this -> Ray, nRayplane[iplane])) <= eps) return this -> posCamera;
        float t = -(dot(this -> posCamera - cstPoint[iplane], nRayplane[iplane]) / dot(this -> Ray, nRayplane[iplane]));

        return Vec3(this->posCamera + t * this->Ray);
    }

    // Kiểm tra xem Point có thuộc mặt phảng i không
    bool CheckPointonPlane(Vec3 _Point, int i) {
        return abs(dot(_Point - cstPoint[i], nRayplane[i])) <= eps;
    }

    float getF(Vec3 _Point, int i) {
        float res =  nRayplane[i].x * (_Point.x - cstPoint[i].x) +
                     nRayplane[i].y * (_Point.y - cstPoint[i].y) +
                     nRayplane[i].z * (_Point.z - cstPoint[i].z);
        if (res > -eps && res < eps) return 0.0f;
        return res;
    }

    // Kiểm tra xem Point có thuộc model hay không
    bool CheckPointonModel(Vec3 _Point) {
        for(int i = 0; i < 6; ++i) {
            if (abs(getF(_Point, i)) <= eps) continue;
            for(int j = 0; j < 6; ++j) {
                if (abs(getF(cstPoint[j], i)) <= eps) continue;
                if (getF(_Point, i) * getF(cstPoint[j], i) < 0) return false;
            }
        }
        return true;
    };

    // Trả về giao của model và Ray
    Vec3 getIntersectionPoint() {
        Vec3 res = this->posCamera;
        float dist = 1e9;
        for(int i = 0; i < 6; ++i) {
            Vec3 P = getPointonPlane(i);
            if (P == this->posCamera) continue;
            if (CheckPointonModel(P)) {
                if (distance(P, this->posCamera) < dist) {
                    dist = distance(P, this->posCamera);
                    res = P;
                }
            }
        }

        return res;
    }


};





#endif //MODELPOINT_MODELPOINTCACULATOR_H
