#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::Destroy(Object* obj)
{
}

inline bool Object::operator==(const Object* _obj)
{
	return this == _obj;
}

inline bool Object::operator!=(const Object* _obj)
{
	return this != _obj;
}
