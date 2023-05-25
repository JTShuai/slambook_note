#include <iostream>
#include <stdexcept>
using namespace std;

#include "libTask.h"
//#include <Eigen/Core>
//#include <Eigen/Geometry>

/*
* 假设我有一个大的Eigen 矩阵，我想把它的左上角3 x 3 的块取出来，然后赋值为
* I_3x3。请编程实现此事
*/

Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> task1(int row, int col){

    cout << "The input size of matrix:" << row << "x" << col << endl;

    if (row<3 || col<3)
    {
        throw std::invalid_argument("Arguments must be larger than 3");
    }

    // 生成一个大的随机矩阵
    Eigen::Matrix<double,Eigen::Dynamic, Eigen::Dynamic> big_matrix = Eigen::MatrixXd::Random(row, col);

    // 选择左上角 3x3
    Eigen::MatrixXd submatrix = big_matrix.block(0, 0, 3, 3);  // Start at row 1, column 1 and select a 3x3 sub-matrix

    cout << "Sub-matrix:\n" << submatrix << endl;

    // 用单位矩阵替换
    big_matrix.block(0,0,3,3) = Eigen::Matrix3d::Identity();

    cout << "The new big matrix: \n" << big_matrix << endl;

    return big_matrix;
}
