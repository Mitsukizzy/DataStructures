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

	// Default constructor
	Vector3():x(0.0f), y(0.0f), z(0.0f)
	{}

	Vector3( float newX, float newY, float newZ ):x(newX), y(newY), z(newZ)
	{}

	// Set all, useful after instantiation
	void Set( float newX, float newY, float newZ )
	{
		x = newX;
		y = newY;
		z = newZ;
	}

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

	float Dot( const Vector3 v )
	{
		return ( x * v.x + y * v.y + z * v.z );
	}

	Vector3 Cross( const Vector3 v )
	{
		Vector3 product;
		product.x = y * v.z - z * v.y;
		product.y = z * v.x - x * v.z;
		product.z = x * v.y - y * v.x;
		return product;
	}

	// OPERATOR OVERRIDES
	// friend keyword allows non-member functions to access private and protected memobers of a class
	friend Vector3 operator+( const Vector3 a, const Vector3 b )
	{
		return Vector3( a.x + b.x, a.y + b.y, a.z + b.z );
	}

	friend Vector3 operator-( const Vector3 a, const Vector3 b )
	{
		return Vector3( a.x - b.x, a.y - b.y, a.z - b.z );
	}

	friend Vector3 operator*( const Vector3 a, const Vector3 b )
	{
		return Vector3( a.x * b.x, a.y * b.y, a.z * b.z );
	}

}; // End Vector3 class

class Vector2
{
public:
	float x;
	float y;

	// Default constructor
	Vector2():x(0.0f), y(0.0f)
	{}

	Vector2( float newX, float newY ):x(newX), y(newY)
	{}

	// Set all, useful after instantiation
	void Set( float newX, float newY )
	{
		x = newX;
		y = newY;
	}

	float LengthSq()
	{
		return ( x * x + y * y );
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
	}

	Vector3 Normalize( const Vector3 v )
	{
		Vector3 vNorm = v;
		vNorm.Normalize();
		return vNorm;
	}


	float Dot( const Vector2 a, const Vector2 b )
	{
		return ( a.x * b.x + a.y * b.y );
	}

}; // End Vector2 class

}; // End Utils namespace