#include<iostream>
//#include <Eigen/Core>
//#include <Eigen/Geometry>
#include <cstdlib>  // For atoi function
#include <string>
#include "libTask.h"


// Function prototypes
Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> task1(int row, int col);

int main(int argc, char** argv)
{
    if (argc != 3) {
        std::cout << "Usage: ./run <arg1> <arg2>" << std::endl;
        return 1;
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

    return 0;
}