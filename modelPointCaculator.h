

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
    const float eps =1e-6;



public:
    /*
     * Khới tạo tọa độ Camera và Ray
     */
    modelPointCaculator(
            float _xCamera, float _yCamera, float _zCamera,
            float _xRay, float _yRay, float _zRay);

    ~modelPointCaculator() {};

    void setposCamera(float _xCamera, float _yCamera, float _zCamera) {
        this->posCamera = Vec3(_xCamera, _yCamera, _zCamera);
    }

    void setRay(float _xRay, float _yRay, float _zRay) {
        this->Ray = Vec3(_xRay, _yRay, _zRay);
    }

    // Khoảng Cách từ điểm A đến Ray xuất phát từ Camera
    float distPointtoCameraRay(Vec3 A);

    // Tìm điểm gần Ray một khoảng cách d và gần Camera nhất
    int getPoint(std::vector<Vec3> vPoint, float d);

};





#endif //MODELPOINT_MODELPOINTCACULATOR_H
