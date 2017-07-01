#include "Utils.h"
using namespace Utils;

class Waypoint
{
public:
	Vector3 arrowFacing;
	Vector2 arrowScreenPos;

	Vector3 playerPos;
	Vector3 playerDest;

	void Update( float deltaTime )
	{
		// New facing is dest - currentPos, then normalize
		Vector3 newFacing = playerDest - playerPos;
		newFacing.Normalize();

		// Angle theta is facing dot dest
		float theta = arrowFacing.Dot( newFacing );

		// Axis is facing cross dest
		Vector3 axis = arrowFacing.Cross( newFacing );

		// If not parallel, make quaternion but normalize axis first
		// TODO: Create quaternion impl
		// Quaternion q;

		if ( axis.Length() < 0.001f )
		{
			// q = quat identity
		}
		else
		{
			axis.Normalize();
			// create q from angle and axis
		}

	}

};