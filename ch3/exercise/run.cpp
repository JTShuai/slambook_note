#include<iostream>
//#include <Eigen/Core>
//#include <Eigen/Geometry>
#include <cstdlib>  // For atoi function
#include <string>
#include "libTask.h"


// Function prototypes
Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> task1(int row, int col);
void task2(float x, float y, float z);

int main(int argc, char** argv)
{
    if (argc != 6) {
        std::cout << "Usage: ./run <arg1> <arg2> <arg3> <arg4> <arg5>" << std::endl;
        return -1;
    }
    /*
    argv[0]: the name of the program
    argv[1]: first argument
    argv[2]: second argument
    ...
    */


    // call task1
    int row = std::atoi(argv[1]);
    int col = std::atoi(argv[2]);
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> res = task1(row,col);

    // call task2
    float x = std::atof(argv[3]);
    float y = std::atof(argv[4]);
    float z = std::atof(argv[5]);
    task2(x,y,z);


    return 0;
}