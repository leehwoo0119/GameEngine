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
			//components(Component*��)�� T(������Ʈ �ڽ� Ŭ����)������ �ٿ� ĳ���� �õ�
			//���н�(���� components(������Ʈ ����Ʈ)�� T�� �� ���� ��) nullptr ��ȯ
			T* downCastCheck = dynamic_cast<T*>(component);
			if (downCastCheck != nullptr)
			{
				//�ٿ� ĳ���� ���� �� ��ȯ
				return downCastCheck;
			}
		}
		//���� nullptr ��ȯ
		return nullptr;
	}
};

#endif 
