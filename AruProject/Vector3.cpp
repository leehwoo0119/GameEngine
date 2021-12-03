#include "Vector3.h"

Vector3::Vector3():x(0), y(0), z(0)
{
}

Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
{
}

Vector3::~Vector3()
{
}

void Vector3::operator*=(const Vector3& _vector)
{
	x *= _vector.x;
	y *= _vector.y;
	z *= _vector.z;
}

void Vector3::operator+=(const Vector3& _vector)
{
	x += _vector.x;
	y += _vector.y;
	z += _vector.z;
}

void Vector3::operator-=(const Vector3& _vector)
{
	x -= _vector.x;
	y -= _vector.y;
	z -= _vector.z;
}

Vector3 Vector3::operator+(const Vector3& _vector)
{
	Vector3 addVector;
	addVector.x = _vector.x + x;
	addVector.y = _vector.y + y;
	addVector.z = _vector.z + z;
	return addVector;
}
