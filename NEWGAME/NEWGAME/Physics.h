#pragma once


	class RigidBody;

	class CPhysicsWorld
	{
		btDefaultCollisionConfiguration*		collisionConfig;
		btCollisionDispatcher*					collisionDispatcher;	//!<衝突解決処理。
		btBroadphaseInterface*					overlappingPairCache;	//!<ブロードフェーズ。衝突判定の枝切り。
		btSequentialImpulseConstraintSolver*	constraintSolver;		//!<コンストレイントソルバー。拘束条件の解決処理。
		btDiscreteDynamicsWorld*				dynamicWorld;			//!<ワールド。
	public:
		CPhysicsWorld();
		~CPhysicsWorld();
		void Init();
		void Update();
		void Release();
		/*!
		* @brief	ダイナミックワールドを取得。
		*/
		btDiscreteDynamicsWorld* GetDynamicWorld()
		{
			return dynamicWorld;
		}
		void AddRigidBody(RigidBody* rb);
		void RemoveRigidBody(RigidBody* rb);
		void ConvexSweepTest(
			const btConvexShape* castShape,
			const btTransform& convexFromWorld,
			const btTransform& convexToWorld,
			btCollisionWorld::ConvexResultCallback& resultCallback,
			btScalar allowedCcdPenetration = 0.0f
			)
		{
			dynamicWorld->convexSweepTest(castShape, convexFromWorld, convexToWorld, resultCallback, allowedCcdPenetration);
		}
	};


