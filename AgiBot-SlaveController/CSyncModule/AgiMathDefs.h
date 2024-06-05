/*
* Brief: define math/calculation relative types/constants
*
* Data: May 29, 2024
* Author: Feijian Ni
*/

#pragma once
#include "AgiMatrix.h"
#include <TcMath.h>

using BLA::LUDecompose;
using BLA::Inverse;
using BLA::Invert;
using BLA::Determinant;
using BLA::Norm;

constexpr double Agi_PI = 3.141592653589793;
constexpr double Agi_2PI = 2 * Agi_PI;
constexpr double g_smallNum = 1e-9;
constexpr double g_smallAng = 0.01 * 180.0 / Agi_PI;
constexpr double g_smallDis = 0.01 * 1e-3;

//#define max(a,b) ((double)(a)>(double)(b)?(a):(b))
//#define min(a,b) ((double)(a)<(double)(b)?(a):(b))

typedef AgiMatrix<2, 2, double> AgiMatrix2d;
typedef AgiMatrix<3, 3, double> AgiMatrix3d;
typedef AgiMatrix<4, 4, double> AgiMatrix4d;
typedef AgiMatrix<5, 5, double> AgiMatrix5d;
typedef AgiMatrix<6, 6, double> AgiMatrix6d;
typedef AgiMatrix<7, 7, double> AgiMatrix7d;
typedef AgiMatrix<8, 8, double> AgiMatrix8d;

typedef AgiMatrix<2, 1, double> AgiVector2d;
typedef AgiMatrix<3, 1, double> AgiVector3d;
typedef AgiMatrix<4, 1, double> AgiVector4d;
typedef AgiMatrix<5, 1, double> AgiVector5d;
typedef AgiMatrix<6, 1, double> AgiVector6d;
typedef AgiMatrix<7, 1, double> AgiVector7d;
typedef AgiMatrix<8, 1, double> AgiVector8d;

// data structure for angle-axis
struct AgiAngleAxis
{
	double m_angle;
	AgiVector3d m_axis;

};

// convert from degree to rad
inline double Deg2Rad(double deg)
{
	return deg * Agi_PI / 180.0;
}

// convert from rad to degree
inline double Rad2Deg(double rad)
{
	return  rad * 180.0 / Agi_PI;
}

// get basic rotation matrix
AgiMatrix3d RotX(double ang);
AgiMatrix3d RotY(double ang);
AgiMatrix3d RotZ(double ang);

double Limit(double lowBound, double val, double upBound);

// convertion between rotaion matrix and angle-axis
AgiAngleAxis Rot2AxisAngle(const AgiMatrix3d& rot);
AgiMatrix3d AxisAngle2Rot(const AgiAngleAxis& axisAng);
