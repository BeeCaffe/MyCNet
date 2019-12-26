//
// Created by caffe on 2019/12/25.
//

#ifndef MYCNET_MATRIX_H
#define MYCNET_MATRIX_H
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <typeinfo>
#include "EnvMsg.h"
#include "RunTimeError.h"
#include <cmath>
namespace MyCNet{
    template<class T>
    class Matrix{
    public:
        typedef float basic_tp;
        typedef T val_tp;
        typedef T* ptr;
        typedef T& ref;
        typedef size_t sz_tp;
        typedef std::vector<T> vector;
        typedef std::vector<std::vector<T>> matrix;
        typedef Matrix<T> self;
    protected:
        size_t row;
        size_t col;
        matrix data;
    public:
        //there are some basic functions of class Matrix
        Matrix();
        Matrix(sz_tp row, sz_tp col);
        Matrix(sz_tp row, sz_tp col, val_tp x);
        //copy constructor
        Matrix(const Matrix& mat);
        void operator =(const Matrix& mat);
        //get matrix infomation
        bool empty();
        vector& size() const;
        const sz_tp cols() const;
        const sz_tp rows() const;
        ref operator()(sz_tp r,sz_tp c) ;
        ref operator()(int r,int c) ;
        void show();
        ~Matrix(){
            row=0;
            col=0;
            data.clear();
        }
    public:
        //there are some matrix basic operations
        self operator+(const self& mat);
        self add(const self& mat);
        self operator-(const self& mat);
        self minus(const self& mat);
        //矩阵点乘，对应位置相乘
        self operator*(const self& mat);
        self mul(const self& mat);
        //矩阵乘法: Amxn x Bnxm = Cmxm
        self matmul(const self& mat);
        //矩阵除，对应位置除
        self div(const val_tp &x);
        //矩阵乘方
        self pow(const val_tp &n);
        //矩阵开根号
        self sqrt();
        void fill(const val_tp &x);

    public:
        //some initialize matrix function for static
        static self ones(sz_tp row, sz_tp col);
        static self ones(const self& mat);
        static self zeros(sz_tp row, sz_tp col);
        static self zeros(const self& mat);
        static self randMat(sz_tp row, sz_tp col);
        static self randMat(const self& mat);

    };
    //default constructor
    template <class T>
    Matrix<T>::Matrix():row(0),col(0){
    }
    //constructor
    template <class T>
    Matrix<T>::Matrix(unsigned long long int row, unsigned long long int col)
    :row(row),col(col){
        if(row<0) perrmsg("row can not be less than 0");
        if(col<0) perrmsg("col can not be less than 0");
        data = matrix (row,vector(col,0));
    }
    //constructor
    template <class T>
    Matrix<T>::Matrix(unsigned long long int row, unsigned long long int col, val_tp x)
    :row(row),col(col){
        if(row<0){
            perrmsg("row can not be less than 0");
            exit(0);
        }
        if(col<0){
            perrmsg("col can not be less than 0.");
            exit(0);
        }
        data=matrix(row,vector(col,x));
    }
    //copy constructor
    template <class T>
    Matrix<T>::Matrix(const MyCNet::Matrix<T> &mat) {
        row = mat.rows();
        col = mat.cols();
        data = mat.data;
    }
    //operator==()
    template <class T>
    void Matrix<T>::operator=(const Matrix<T> & mat) {
        if(static_cast<self>(mat).empty()){
            perrmsg("There should not be an empty matrix.");
            exit(0);
        }
        row=mat.row;
        col=mat.col;
        this->data=mat.data;
    }

    template <class T>
    const typename Matrix<T>::sz_tp Matrix<T>::rows() const{
        return row;
    }

    template <class T>
    const typename Matrix<T>::sz_tp Matrix<T>::cols() const{
        return col;
    }

    template <class T>
    bool Matrix<T>::empty() {
        return row==0 || col==0;
    }

    template <class T>
    typename Matrix<T>::vector & Matrix<T>::size() const{
        return vector({row,col});
    }

    template <class T>
     typename Matrix<T>::ref Matrix<T>::operator()(Matrix::sz_tp r, Matrix::sz_tp c) {
        if(r<0 || r>row){
            perrmsg("index of \"r\" may out of memory, check the row of you matrix");
            exit(0);
        }
        if(c<0 || c>col){
            perrmsg("index of \"c\" may out of memory, check the col of you matrix");
        }
        return data[r][c];
    }
    template <class T>
     typename Matrix<T>::ref Matrix<T>::operator()(int r, int c) {
        if(r<0 || r>row){
            perrmsg("index of \"r\" may out of memory, check the row of you matrix");
            exit(0);
        }
        if(c<0 || c>col){
            perrmsg("index of \"c\" may out of memory, check the col of you matrix");
        }
        return data[r][c];
    }
    template <class T>
    void Matrix<T>::show() {
        if(col==0 || row==0) printf("empty matrix\n");
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                printf("%.4f ", static_cast<basic_tp >(data[i][j]));
            }
            printf("\n");
        }
    }

    template <class T>
    typename Matrix<T>::self  Matrix<T>::operator+(const Matrix<T> &mat) {
        if(row!=mat.row || col!=mat.col){
            perrmsg("the width and height of two matrix are not equal");
            exit(0);
        }
        self ret(row,col);
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                ret(i,j)=data[i][j]+ static_cast<self>(mat)(i,j);
            }
        }
        return ret;
    }

    template <class T>
    typename Matrix<T>::self Matrix<T>::add(const MyCNet::Matrix<T>::self &mat) {
        if(row!=mat.row || col!=mat.col) {
            perrmsg("the width and height of two matrix are not equal");
            exit(0);
        }
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                data[i][j] += static_cast<self>(mat)(i,j);
            }
        }
        return *this;
    }
    template <class T>
    typename Matrix<T>::self Matrix<T>::operator-(const Matrix::self & mat) {
        if(row!=mat.row || col!=mat.col) {
            perrmsg("the width and height of two matrix are not equal");
            exit(0);
        }
        self ret(row,col);
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                ret(i,j)=data[i][j] - static_cast<self>(mat)(i,j);
            }
        }
        return ret;
    }

    template <class T>
    typename Matrix<T>::self Matrix<T>::minus(const Matrix::self & mat) {
        if(row!=mat.row || col!=mat.col) {
            perrmsg("the width and height of two matrix are not equal");
            exit(0);
        }
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                data[i][j] -= static_cast<self>(mat)(i,j);
            }
        }
        return *this;
    }


    template <class T>
    typename Matrix<T>::self Matrix<T>::operator*(const Matrix::self & mat) {
        if(row!=mat.row || col!=mat.col) {
            perrmsg("the width and height of two matrix are not equal");
            exit(0);
        }
        self ret(row,col);
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                ret(i,j) = data[i][j] * static_cast<self>(mat)(i,j);
            }
        }
        return ret;
    }

    template <class T>
    typename Matrix<T>::self Matrix<T>::mul(const MyCNet::Matrix<T>::self &mat) {
        if(row!=mat.row || col!=mat.col) {
            perrmsg("the width and height of two matrix are not equal");
            exit(0);
        }
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                data[i][j] *= static_cast<self>(mat)(i,j);
            }
        }
        return *this;
    }

    /**
     * @brief : the matrix multiplication, Amxn x Bnxm = Cmxm, where must promise that
     * A's cols are equal to B's rows, and the result matrix size is (mxm).
     * @param mat : Matrix
     * @return Matrix -> size(m,m)
     */
    template <class T>
    typename MyCNet::Matrix<T>::self Matrix<T>::matmul(const MyCNet::Matrix<T>::self & mat) {
        sz_tp r1 = row,c1 = col;
        sz_tp r2 = mat.rows(), c2=mat.cols();
        if(c1 != r2) {
            perrmsg("the matrix A's cols must equal to matrix B's rows in matrix multiplication.")
            exit(0);
        }
        sz_tp n=c1;
        self ret(r1, c2, 0);
        for(int i=0;i<r1;++i){
            for(int j=0;j<c2;++j){
                for(int k=0;k<n;++k){
                    ret(i,j) += (data[i][k] * static_cast<self>(mat)(k,j));
                }
            }
        }
        return ret;
    }


    template <class T>
    typename MyCNet::Matrix<T>::self Matrix<T>::div(const MyCNet::Matrix<T>::val_tp & x) {
        if(x==0){
            perrmsg("dividend should not be zero");
            exit(0);
        }
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                data[i][j]/=x;
            }
        }
        return *this;
    }

    template <class T>
    typename MyCNet::Matrix<T>::self Matrix<T>::pow(const MyCNet::Matrix<T>::val_tp & n) {
        for(int i=0;i<row;++i){
            for(int j=0; j<col;++j){
                data[i][j] = static_cast<val_tp>(std::pow(static_cast<double >(data[i][j]), static_cast<double >(n)));
            }
        }
        return *this;
    }

    template <class T>
    typename MyCNet::Matrix<T>::self Matrix<T>::sqrt() {
        for(int i=0;i<row;++i){
            for(int j=0; j<col;++j){
                data[i][j] = static_cast<val_tp>(std::sqrt(data[i][j]));
            }
        }
        return *this;
    }

    template <class T>
    typename Matrix<T>::self Matrix<T>::ones(MyCNet::Matrix<T>::sz_tp row, MyCNet::Matrix<T>::sz_tp col) {
        if(row<0 || col<0){
            perrmsg("matrix's width and height should not be zero");
        }
        return Matrix(row,col, 1);
    }

    template <class T>
    typename MyCNet::Matrix<T>::self Matrix<T>::ones(const MyCNet::Matrix<T>::self & mat) {
        if(mat.rows()<0 || mat.cols()<0){
            perrmsg("matrix's width and height should not be zero");
        }
        return Matrix(mat.rows(),mat.cols(), 1);
    }

    template <class T>
    typename Matrix<T>::self Matrix<T>::zeros(MyCNet::Matrix<T>::sz_tp row, MyCNet::Matrix<T>::sz_tp col) {
        if(row<0 || col<0){
            perrmsg("matrix's width and height should not be zero");
        }
        return Matrix(row,col, 0);
    }

    template <class T>
    typename MyCNet::Matrix<T>::self Matrix<T>::zeros(const MyCNet::Matrix<T>::self & mat) {
        if(mat.rows()<0 || mat.cols()<0){
            perrmsg("matrix's width and height should not be zero");
        }
        return Matrix(mat.rows(),mat.cols(), 0);
    }

    template <class T>
    void Matrix<T>::fill(const MyCNet::Matrix<T>::val_tp & x) {
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                data[i][j]=x;
            }
        }
    }
}
#endif //MYCNET_MATRIX_H
