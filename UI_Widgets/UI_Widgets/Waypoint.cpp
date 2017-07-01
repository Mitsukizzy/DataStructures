#include "Utils.h"
using namespace Utils;

class Waypoint
{
public:
	Vector3 arrowFacing;
	Vector3 arrowDest;
	Vector2 arrowScreenPos;

	void Update( float deltaTime )
	{
		// New facing is dest - currentPos, then normalize
		// Angle theta is facing dot dest
		// Axis is facing cross dest
		// If not parallel, make quaternion but normalize axis first
	}

};