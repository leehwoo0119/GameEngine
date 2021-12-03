#ifndef _VECTOR3_H_
#define _VECTOR3_H_

class Vector3
{
public:
	Vector3();
	Vector3(float _x, float _y, float _z);
	~Vector3();

public:
	float x;
	float y;
	float z;

public:
	void operator*=(const Vector3& _vector);
	void operator+=(const Vector3& _vector);
	void operator-=(const Vector3& _vector);
	Vector3 operator+(const Vector3& _vector);
};

#endif 