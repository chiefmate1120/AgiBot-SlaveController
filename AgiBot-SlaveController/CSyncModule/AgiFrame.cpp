#include "AgiFrame.h"
AgiFrame::AgiFrame()
{
	m_rot.eye();
	m_pos.zeros();
}

AgiFrame::AgiFrame(const AgiVector3d& pos, const AgiMatrix3d& rot)
	: m_rot(rot)
	, m_pos(pos)
{ }


AgiFrame::AgiFrame(const AgiFrame& f)
{
	m_rot = f.m_rot;
	m_pos = f.m_pos;
}

AgiFrame::~AgiFrame() { }

bool AgiFrame::operator==(const AgiFrame& f)
{
	AgiMatrix3d deltaRot = f.m_rot.transpose() * this->m_rot;
	AgiAngleAxis axisAng = Rot2AxisAngle(deltaRot);

	return Norm(f.m_pos - this->m_pos) < g_smallDis && (axisAng.m_angle < g_smallAng);
}

AgiVector3d AgiFrame::operator*(const AgiVector3d& v) const
{
	return m_rot * v + m_pos;
}

AgiFrame AgiFrame::operator*(const AgiFrame& f) const
{
	AgiFrame newFrame;
	newFrame.m_rot = m_rot * f.m_rot;
	newFrame.m_pos = m_rot * f.m_pos + m_pos;
	return newFrame;
}

AgiFrame& AgiFrame::operator=(const AgiFrame& f)
{
	this->m_rot = f.m_rot;
	this->m_pos = f.m_pos;

	return *this;
}

AgiFrame AgiFrame::inverse() const
{
	AgiFrame newFrame;
	newFrame.m_rot = m_rot.transpose();
	newFrame.m_pos = -newFrame.m_rot * m_pos;
	return newFrame;
}

AgiVector6d AgiFrame::getPoseVec() const
{
	AgiVector6d vec;
	vec.Submatrix<3, 1>(0, 0) = m_pos;
	AgiAngleAxis angAxis = Rot2AxisAngle(m_rot);

	vec.Submatrix<3, 1>(3, 0) = angAxis.m_axis * angAxis.m_angle;
	return vec;
}

void AgiFrame::clear()
{
	m_pos.zeros();
	m_rot.eye();
}

AgiMatrix4d AgiFrame::getHomo() const
{
	AgiMatrix4d homo;
	homo.zeros();
	homo.Submatrix<3, 1>(0, 3) = m_pos;
	homo.Submatrix<3, 3>(0, 0) = m_rot;
	homo(3, 3) = 1.0;
	return homo;
}

bool AgiFrame::isEqual(
	const AgiFrame& pose, const double posError, const double oriError) const
{
	// check position difference
	double posDiff = Norm(m_pos - pose.m_pos);
	if (posDiff > posError) {
		return false;
	}

	// compute rotation distance
	AgiMatrix3d deltaRot = pose.m_rot.transpose() * this->m_rot;
	AgiAngleAxis axisAng = Rot2AxisAngle(deltaRot);


	return posDiff < posError&& fabs_(axisAng.m_angle) < oriError;
}
