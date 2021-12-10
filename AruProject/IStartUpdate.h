#ifndef _ISTARTUPDATE_H_
#define _ISTARTUPDATE_H_

__interface IStartUpdate
{
public:
	virtual void Awake() = 0;
	virtual void Start() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Update() = 0;
	virtual void Coroutine() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render() = 0;
};

#endif 