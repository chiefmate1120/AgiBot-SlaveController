/*
* Brief: define AgiMatrix template, which is implemented basd on thridparty BLA
*
* Data: May 29, 2024
* Author: Feijian Ni
*/

#pragma once
#include <BasicLinearAlgebra/BasicLinearAlgebra.h>

using BLA::Matrix;
using BLA::MatrixBase;
using BLA::RefMatrix;

template <int Rows, int Cols, typename DType = double>
class AgiMatrix : public Matrix<Rows, Cols, DType>
{
public:
    AgiMatrix() = default;
    ~AgiMatrix() = default;

    template <typename... TAIL>
    AgiMatrix(DType head, TAIL... args)
    {
        Matrix<Rows, Cols, DType>::FillRowMajor(0, head, args...);
    }

    template <typename DerivedType>
    AgiMatrix(const MatrixBase<DerivedType, Rows, Cols, DType>& mat)
    {
        static_cast<MatrixBase<Matrix<Rows, Cols, DType>, Rows, Cols, DType>&>(*this) = mat;
    }

    AgiMatrix& operator=(const Matrix<Rows, Cols, DType>& mat)
    {
        static_cast<Matrix<Rows, Cols, DType>&>(*this) = mat;
        return *this;
    }

    template <typename RefType>
    AgiMatrix& operator=(const RefMatrix<RefType, Rows, Cols>& mat)
    {
        for (int i = 0; i < Rows; ++i)
        {
            for (int j = 0; j < Cols; ++j)
            {
                (*this)(i, j) = mat(i, j);
            }
        }
        return *this;
    }

    void zeros()
    {
        (*this).Fill(0);

    }
    void ones()
    {
        (*this).Fill(1);

    }

    AgiMatrix<Rows, 1, DType> diagonal()
    {
        static_assert(Rows == Cols, "Matrix must be square for diagonal.");
        AgiMatrix<Rows, 1, DType> diagVec;
        for (int i = 0; i < Rows; i++) {
            diagVec(i, 0) = (*this)(i, i);
        }

        return diagVec;
    }

    AgiMatrix<Rows, Rows, DType> asDiagonal()
    {
        static_assert(Cols == 1, "Only vector can be use for asDiagonal.");
        AgiMatrix<Rows, Rows, DType> diagMat;
        diagMat.Fill(0);
        for (int i = 0; i < Rows; i++) {
            diagMat(i, i) = (*this)(i, 0);
        }

        return diagMat;

    }
    void eye()
    {
        static_assert(Rows == Cols, "Only square matrix can be identity");
        (*this).Fill(0);
        for (int i = 0; i < Rows; i++)
        {
            (*this)(i, i) = 1;
        }
    }

    AgiMatrix<Cols, Rows, DType> transpose() const
    {
        return ~(static_cast<const Matrix<Rows, Cols, DType>&>(*this));
    }

};
