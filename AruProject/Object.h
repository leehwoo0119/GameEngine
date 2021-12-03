#ifndef _OBJECT_H_
#define _OBJECT_H_
#include <string>

class Object
{
public:
	Object();
	~Object();

public:
	std::string name;

public:
	void Destroy(Object* obj);

	inline bool operator==(const Object* _obj);
	inline bool operator!=(const Object* _obj);
};

#endif 