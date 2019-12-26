//
// Created by caffe on 2019/12/25.
//
#include "../include/Matrix.h"
using namespace MyCNet;
int main(){
//    //test 1
//    MyCNet::Matrix<double> mat1(2, 2, 99);
//    mat1.show();
//    //test 2
//    MyCNet::Matrix<double > mat2(2,3);
//    mat2.show();
//    //test 3
//    MyCNet::Matrix<int> mat3;
//    mat3.show();
//    //test 4
//    MyCNet::Matrix<double> mat4(mat1);
//    mat4.show();
//    //test 5
//    mat2 = mat4;
//    mat2.show();
//    //test 6
//    MyCNet::Matrix<float > mat6(3,3 ,1);
//    cout<<mat6(0,0)<<endl;
//    //test 7
//    mat6(0,0)=2;
//    mat6.show();
    //test 7
//    MyCNet::Matrix<float > mat7(3,3,2.3);
//    MyCNet::Matrix<float > mat7_(3,3, 9.87);
//    mat7 = mat7+mat7_;
//    mat7 = mat7.add(mat7_);
//    mat7 = mat7 - mat7_;
//    mat7.minus(mat7_);
//    mat7.show();
    //test 8
//    MyCNet::Matrix<float > mat8(2,3, 1);
//    MyCNet::Matrix<float > mat8_(3,2,5);
//    MyCNet::Matrix<float > mat=mat8.matmul(mat8_);
    //test 9
//    MyCNet::Matrix<float > mat(3,3,9);
//    mat.div(31);
//    mat.show();
    //test 10
//    MyCNet::Matrix<float > mat(3,3,9);
//    mat.pow(2);
//    mat.sqrt();
    //test 11
    auto mat = Matrix<float>::ones(3, 3);
    mat.show();
    auto mat1 = Matrix<float >::zeros(mat);
    mat.fill(8);
    mat.show();
    return 0;
}
