#pragma once


#include "light.h"
#include "shadow.h"
#include "Physics.h"
#include "ParticleEmitter.h"
#include "Pad.h"

class Scene
{
public:
	Scene(){}
	virtual ~Scene()
	{

	}
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	/*!
	* @brief	カメラを取得。
	*/
	
	CPad* GETPad(){ return &pad; }
	Light* GETlight(){ return &light; }
	ShadowMap* Getshadow(){ return &shadow; }
	//物理ワールドの取得。
	CPhysicsWorld* GetPhysicsWorld()
	{
		return &physicsWorld;
	}
protected:
	CPad				pad;
	Light				light;
	ShadowMap			shadow;
	CPhysicsWorld		physicsWorld;
	CParticleEmitter	particleEmitter;	//パーティクルエミッター
};
