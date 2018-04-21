#pragma once
#include "Entity.h"
#include "Component.h"

#include <vector>

class EntityManager
{
public:

	std::vector<Entity*>Entities;

	
	void cleanup()
	{
		for (auto e : Entities)
			delete e;
	}

	EntityManager();
	~EntityManager();
};

