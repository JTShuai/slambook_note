#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

/****************************
* 本程序演示了 Eigen 几何模块的使用方法
****************************/

int main(int argc, char** argv)
{
    // 3D 旋转矩阵直接使用 Matrix3d 或 Matrix3f
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
    // 旋转向量使用 AngleAxis, 它底层不直接是 Matrix, 但运算可以当作矩阵（因为重载了运算符）
    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0,0,1)); //绕 z 轴旋转 45 度

    cout.precision(3);
    cout<< "rotation matrix = \n" << rotation_vector.matrix() << endl; // 用 matrix() 把 vector 转换为矩阵
    // 也可以直接赋值
    rotation_matrix = rotation_vector.toRotationMatrix();

    // 坐标变换
    Eigen::Vector3d v(1,0,0);
    Eigen::Vector3d v_rotated = rotation_vector * v;
    cout << "(1, 0, 0) after rotation (by vector) = " << v_rotated.transpose() << endl;

    // 或者使用旋转矩阵
    v_rotated = rotation_matrix * v;
    cout << "(1,0,0) after rotation (by matrix) = " << v_rotated.transpose() << endl;

    // 欧拉角: 可以将旋转矩阵直接转换成欧拉角
    Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0); // ZYX顺序，即yaw-pitch-roll顺序
    cout << "yaw pitch roll = " << euler_angles.transpose() << endl;

    //欧式变换(齐次变换)矩阵使用 Eigen::Isometry
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity(); //虽然称为3d, 其实是 4*4 矩阵
    T.rotate(rotation_vector); // 按照 rotation_vector 进行旋转
    T.pretranslate(Eigen::Vector3d(1,3,4)); //  (1,3,4) * T; 平移 T, 平移向量为 (1,3,4)
    cout<< "Transform matrix = \n" << T.matrix() << endl;

    // 用变换矩阵进行坐标变换
    Eigen::Vector3d v_tranformed = T * v;
    cout<< "v transformed = " << v_tranformed.transpose() << endl;

    // 对于仿射和射影变换，使用 Eigen::Affine3d 和 Eigen::Projective3d 即可，略

    return 0;










}