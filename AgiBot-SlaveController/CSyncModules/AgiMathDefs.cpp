#include "AgiMathDefs.h"

double Limit(double lowBound, double val, double upBound)
{
	return min(max(val, lowBound), upBound);
}
// get basic rotation matrix
AgiMatrix3d RotX(double ang)
{
	AgiMatrix3d rot;
	rot.eye();
	rot(1, 1) = cos_(ang);
	rot(2, 2) = rot(1, 1);
	rot(2, 1) = sin_(ang);
	rot(1, 2) = -rot(2, 1);

	return rot;
}
AgiMatrix3d RotY(double ang)
{
	AgiMatrix3d rot;
	rot.eye();
	rot(0, 0) = cos_(ang);
	rot(2, 2) = rot(0, 0);
	rot(0, 2) = sin_(ang);
	rot(2, 0) = -rot(0, 2);

	return rot;

}
AgiMatrix3d RotZ(double ang)
{
	AgiMatrix3d rot;
	rot.eye();
	rot(0, 0) = cos_(ang);
	rot(1, 1) = rot(0, 0);
	rot(1, 0) = sin_(ang);
	rot(0, 1) = -rot(1, 0);

	return rot;
}

AgiAngleAxis Rot2AxisAngle(const AgiMatrix3d& rot)
{
	double tmp = Limit(-1.0, (rot(1, 1) + rot(2, 2) + rot(0, 0) - 1) / 2, 1.0);
	double angle = acos_(tmp);

	AgiVector3d axis;
	// no rotation
	if (fabs_(angle) < g_smallAng)
	{
		angle = 0;
		axis(0) = 1;
		axis(1) = 0;
		axis(2) = 0;
	}
	// rotate pi
	else if (fabs_(angle - Agi_PI) < g_smallAng)
	{
		angle = Agi_PI;
		axis(0) = sqrt_((rot(0, 0) + 1) / 2);
		axis(1) = sqrt_((rot(1, 1) + 1) / 2);
		axis(2) = sqrt_((rot(2, 2) + 1) / 2);
		if (axis(0) > g_smallNum) {
			axis(1) = 0.5 * rot(0, 1) / axis(0);
			axis(2) = 0.5 * rot(0, 2) / axis(0);
		}
		else if (axis(1) > g_smallNum) {
			axis(0) = 0.5 * rot(1, 0) / axis(1);
			axis(2) = 0.5 * rot(1, 2) / axis(1);
		}
		else {
			axis(0) = 0.5 * rot(2, 0) / axis(2);
			axis(1) = 0.5 * rot(2, 1) / axis(2);
		}
	}
	// others
	else {
		tmp = 2 * sin_(angle);
		axis(0) = (rot(2, 1) - rot(1, 2)) / tmp;
		axis(1) = (rot(0, 2) - rot(2, 0)) / tmp;
		axis(2) = (rot(1, 0) - rot(0, 1)) / tmp;
	}

	// normalize
	axis = axis / Norm(axis);

	AgiAngleAxis res;
	res.m_angle = angle;
	res.m_axis = axis;

	return res;
}

AgiMatrix3d AxisAngle2Rot(const AgiAngleAxis& angAxis)
{
	AgiMatrix3d rot;
	double cAng = cos_(angAxis.m_angle);
	double _cAng = cos_(angAxis.m_angle);
	double sAng = sin_(angAxis.m_angle);
	double rx = angAxis.m_axis(0);
	double ry = angAxis.m_axis(1);
	double rz = angAxis.m_axis(2);

	rot(0, 0) = rx * rx * _cAng + cAng;
	rot(1, 0) = rx * ry * _cAng + rz * sAng;
	rot(2, 0) = rx * rz * _cAng - ry * sAng;

	rot(0, 1) = rx * ry * _cAng - rz * sAng;
	rot(1, 1) = ry * ry * _cAng + cAng;
	rot(2, 1) = ry * rz * _cAng + rx * sAng;

	rot(0, 2) = rx * rz * _cAng + ry * sAng;
	rot(1, 2) = ry * rz * _cAng - rx * sAng;
	rot(2, 2) = rz * rz * _cAng + cAng;

	return rot;
}