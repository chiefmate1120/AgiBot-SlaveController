/*
* Brief: define class AgiFrame, and corresponding calculation
*
* Data: May 29, 2024
* Author: Feijian Ni
*/

#pragma once
#include "AgiMathDefs.h"

class AgiFrame
{
public:
	// constructor and destructor
	AgiFrame();
	AgiFrame(const AgiVector3d& pos, const AgiMatrix3d& rot);
	AgiFrame(const AgiFrame& f);
	virtual ~AgiFrame();

	// multiply vector
	AgiVector3d operator*(const AgiVector3d& v) const;

	// multiply frame
	AgiFrame operator*(const AgiFrame& f) const;

	// assign
	AgiFrame& operator=(const AgiFrame& f);

	// equal
	bool operator==(const AgiFrame&);

	// check if current and target poses are the same (within tolerance)
	bool isEqual(const AgiFrame& pose,
		const double posError = g_smallDis,
		const double oriError = g_smallAng) const;

	// return inverse transformation
	AgiFrame inverse() const;

	// Get pose vector [pos,angle*axis]
	AgiVector6d getPoseVec() const;

	// reset the transformation to identity matrix
	void clear();

	// get the homogeneous transformation representation
	AgiMatrix4d getHomo() const;

	// rotation matrix
	AgiMatrix3d m_rot;

	// translation  vector
	AgiVector3d m_pos;

};



