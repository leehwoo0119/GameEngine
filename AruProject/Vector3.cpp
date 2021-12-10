#include "Vector3.h"

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

Vector3 Vector3::operator-(const Vector3& _vector)
{
	Vector3 addVector;
	addVector.x = _vector.x - x;
	addVector.y = _vector.y - y;
	addVector.z = _vector.z - z;
	return addVector;
}

Vector3 Vector3::operator*(const Vector3& _vector)
{
	Vector3 addVector;
	addVector.x = _vector.x * x;
	addVector.y = _vector.y * y;
	addVector.z = _vector.z * z;
	return addVector;
}
