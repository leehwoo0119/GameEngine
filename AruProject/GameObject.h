#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include <list>
#include <string>

class Component;
class Transform;
class Vector3;

class GameObject
{
public:
	GameObject(std::string _name);
	~GameObject();

public:
	std::list<Component*> m_Components;

	GameObject* p_GameObject;
	Transform* p_Transform;

private:
	std::string name;

public:
	void AddComponent(Component* _comp);

	void Awake();
	void Start();
	void FixedUpdate();
	void Update();
	void Coroutine();
	void LateUpdate();
	void Render();

	template <typename T>
	T* GetComponent()
	{
		for (Component* component : m_Components)
		{
			//components(Component*형)를 T(컴포넌트 자식 클래스)형으로 다운 캐스팅 시도
			//실패시(현재 components(컴포넌트 리스트)에 T형 이 없을 시) nullptr 반환
			T* downCastCheck = dynamic_cast<T*>(component);
			if (downCastCheck != nullptr)
			{
				//다운 캐스팅 성공 값 반환
				return downCastCheck;
			}
		}
		//실패 nullptr 반환
		return nullptr;
	}
};

#endif 
