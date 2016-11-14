#pragma once 
#include "stdafx.h"
class ICollider {
public:
	virtual btCollisionShape* GetBody() = 0;
};