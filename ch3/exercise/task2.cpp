#include <iostream>
#include "libTask.h"

void task2(float x, float y, float z)
{
    // (w,x,y,z) - （q0, q1,q2,q3）
    // initial the point in virtual quaternion
    Eigen::Vector3d p;
    p << x,y,z;


    // world frame to frame 1
    Eigen::Quaterniond q_1 = Eigen::Quaterniond(0.35, 0.2, 0.3, 0.1).normalized();
    Eigen::Vector3d t_1(0.3, 0.1, 0.1);

    Eigen::Matrix3d matrix_1;
    matrix_1 = q_1.toRotationMatrix();


    // Eigen中四元数存储顺序(从打印可知)是 xyzw
    std::cout << "Eigen中四元数存储顺序(从打印可知)是 xyzw: \n" << q_1.coeffs().transpose() << std::endl;


    // world frame to frame 2
    Eigen::Quaterniond q_2 = Eigen::Quaterniond(-0.5, 0.4, -0.1, 0.2).normalized();
    Eigen::Vector3d t_2(-0.1, 0.5, 0.3);

    Eigen::Matrix3d matrix_2;
    matrix_2 = q_2.toRotationMatrix();


    /*
    四元数的逆定义为四元数的共轭除以它的模; 所以归一化后，四元数的逆等于共轭
    */
    // convert p from frame 1 to world frame
    // 在Eigen中四元数旋转为q×v，数学中则为q×v×q^-1
    Eigen::Vector3d p_w = q_1 * p;
    p_w += t_1;

    Eigen::Vector3d p_r = matrix_1 * p + t_1;


    // convert p_w from world frame to frame 2
    q_2 = q_2.conjugate();
    p_w = q_2 * p_w;
    p_w -= t_2;

    p_r = matrix_2.transpose() * p_r - t_2;

    std::cout << "点在 frame 2的坐标为： \n" << p_w.transpose() << std::endl;
    std::cout << "旋转矩阵得到点在 frame 2的坐标为： \n" << p_r.transpose() << std::endl;
}