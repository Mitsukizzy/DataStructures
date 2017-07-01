#pragma once
#include <cmath>

namespace Utils
{

class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3():x(0.0f), y(0.0f), z(0.0f)
	{}

	Vector3( float inX, float inY, float inZ ):x(inX), y(inY), z(inZ)
	{}

	float LengthSq()
	{
		return ( x * x + y * y + z * z );
	}

	float Length()
	{
		return sqrtf( LengthSq() );
	}

	void Normalize()
	{
		float len = Length();
		x /= len;
		y /= len;
		z /= len;
	}

	Vector3 Normalize( const Vector3 v )
	{
		Vector3 vNorm = v;
		vNorm.Normalize();
		return vNorm;
	}

	float Dot( const Vector3 a, const Vector3 b )
	{
		return ( a.x * b.x + a.y * b.y + a.z * b.z );
	}

	Vector3 Cross( const Vector3 a, const Vector3 b )
	{
		Vector3 product;
		product.x = a.y * b.z - a.z * b.y;
		product.y = a.z * b.x - a.x * b.z;
		product.z = a.x * b.y - a.y * b.x;
		return product;
	}

}; // End Vector3 class

class Vector2
{
public:
	float x;
	float y;

	Vector2():x(0.0f), y(0.0f)
	{}

	Vector2( float inX, float inY ):x(inX), y(inY)
	{}

	float Dot( const Vector2 a, const Vector2 b )
	{
		return ( a.x * b.x + a.y * b.y );
	}

}; // End Vector2 class

}; // End Utils namespace