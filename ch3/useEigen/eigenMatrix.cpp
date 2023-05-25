#include <iostream>
#include <ctime>

// Eigen 部分
#include <Eigen/Core>
// 稠密矩阵的代数运算 (逆，特征值等)
#include <Eigen/Dense>

#define MATRIX_SIZE 50

/****************************
* 本程序演示了Eigen 基本类型的使用
****************************/
int main ( int argc, char** argv)
{
    // Eigen 是一个模板类。前三个参数为: 数据类型，行，列
    // 声明一个 2*3 的 float 矩阵
    Eigen::Matrix<float, 2, 3> matrix_23;

    // Vector3d 实质上是 Eigen::Matrix<double, 3, 1>
    Eigen::Vector3d v_3d;

    // Matrix3d 实质上是 Eigen::Matrix<double, 3, 3>
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();  // 初始化为零

    // 如果不确定矩阵大小，可以使用动态大小的矩阵
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;

    // 更简单的
    Eigen::MatrixXd matrix_x;


    // 矩阵的操作
    // 输入数据
    matrix_23 << 1,2,3,4,5,6;
    // 输出
    std::cout<< "matrix_23 : "<< matrix_23 << std::endl;

    // 访问矩阵中元素
    for (int i=0; i<1; i++)
        for (int j=0; j<2; j++)
            std::cout << matrix_23(i,j)<<std::endl;

    // 向量赋值
    v_3d << 3,2,1;

    // 矩阵和向量相乘需要 显式转换
    // cast<>()返回的是一个对矩阵或向量进行类型转换后的引用
    Eigen::Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    std::cout<< result << std::endl;


    // 一些矩阵运算，四则运算直接用运算符就行
    matrix_33 = Eigen::Matrix3d::Random();
    std::cout << matrix_33 << std::endl << std::endl;

    std::cout << matrix_33.transpose() << std::endl;
    std::cout << matrix_33.sum() << std::endl;
    std::cout << matrix_33.trace() << std::endl;
    std::cout << matrix_33.inverse() << std::endl;
    std::cout << matrix_33.determinant() << std::endl;

    // 特征值
    // 实对称矩阵可以保证对角化成功
    // SelfAdjointEigenSolver: 用于求解对称矩阵的特征值和特征向量
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver ( matrix_33.transpose()*matrix_33 );
    std::cout << "Eigen values = " << eigen_solver.eigenvalues() << std::endl;
    std::cout << "Eigen vectors = " << eigen_solver.eigenvectors() << std::endl;

    // 解方程： matrix_NN * x = v_Nd
    // 直接求逆是最直接的，但是求你运算量大
    Eigen::Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN;
    matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    Eigen::Matrix<double, MATRIX_SIZE, 1> v_Nd;
    v_Nd = Eigen::MatrixXd::Random(MATRIX_SIZE, 1);

    clock_t time_stt = std::clock();  // 计时
    // 直接求逆
    Eigen::Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse()*v_Nd;
    std::cout <<"time use in normal invers is " << 1000* (clock() - time_stt)/(double)CLOCKS_PER_SEC << "ms"
    << std::endl;

    // 用矩阵分解来求，会快很多; e.g., QR 分解
    time_stt = std::clock();

    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    std::cout <<"time use in Qr compsition is " <<1000* (clock() - time_stt)/(double)CLOCKS_PER_SEC <<"ms"
    << std::endl;

    return 0;








}