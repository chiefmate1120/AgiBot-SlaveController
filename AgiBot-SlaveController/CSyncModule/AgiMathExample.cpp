#include "AgiMathExample.h"

int runExample()
{
    AgiMatrix3d A = { 2,2,3,4,5,6,7,8,9 };
    AgiMatrix3d B, C;
    int a = B.Rows;
    int b = B.Cols;
    B(1, 1) = 10;

    AgiVector3d diagA = A.diagonal();
    AgiMatrix3d asDiagA = diagA.asDiagonal();

    // horizontally and vertically concatenation
    AgiMatrix<3, 6> AB1 = A || B;
    AgiMatrix<6, 3> AB2 = A && B;

    AgiVector3d diagAVec = A.diagonal();
    AgiMatrix3d diagAMat = diagAVec.asDiagonal();

    B.zeros();
    C.ones();
    C.eye();
    C.Fill(1.11);

    B = A;
    B *= A;
    B *= 2.0;
    B -= A;
    B += A;

    B = A;
    C = A;
    C = A * 2.0;
    // C = 3 * A ; not valid;
    C = A * B;

    double det = Determinant(C);

    AgiVector3d colVec = C.Column(1);
    AgiMatrix<1, 3> rowVec;
    rowVec = C.Row(1);

    AgiMatrix<2, 2> subMat;
    subMat = B.Submatrix<2, 2>(0, 0);
    subMat.eye();
    B.Submatrix<2, 2>(0, 0) = subMat;

    double matDet = Determinant(A);

    AgiMatrix3d A_inv = A;
    bool isSingluar = Invert(A_inv);
    AgiMatrix3d A_trans = A.transpose();

    AgiMatrix6d LUA = { 16, 78, 50, 84, 70, 63, 2,  32, 33, 61, 40, 17, 96, 98, 50, 80, 78, 27,
                      86, 49, 57, 10, 42, 96, 44, 87, 60, 67, 16, 59, 53, 8,  64, 97, 41, 90 };
    AgiVector6d LUb = { 3, 99, 95, 72, 57, 43 };
    auto ACopy = LUA;
    auto LUDecompA = LUDecompose(ACopy);
    LUDecompA.P;
    LUDecompA.L;
    LUDecompA.U;
    AgiVector6d LURes = LUSolve(LUDecompA, LUb);

    AgiMatrix6d AInv = Inverse(LUA);
    AgiVector6d InvRes = AInv * LUb;



    AgiFrame frame1;
    frame1.m_rot = RotY(Deg2Rad(0));
    frame1.m_pos = AgiVector3d(0, 0, 0.1);

    AgiFrame frame2 = frame1;

    AgiFrame invFrame = frame1.inverse();

    frame2 = invFrame * frame1;

    AgiVector6d poseVec = frame1.getPoseVec();
    AgiAngleAxis angAxis = Rot2AxisAngle(frame1.m_rot);

    return 1;

}
