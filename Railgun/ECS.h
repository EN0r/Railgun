#pragma once

#include <iostream>
#include <vector>
#include "Windows.h"


/*
	--INFORMATION--
	ALL ENTITIES ARE CLASSED AS GAMEOBJECTS
	ALL COMPONENTS HAVE ID'S WHICH ARE DEFINED IN THE CLASS OF THE COMPONENT
	EACH COMPONENT WILL HAVE FUNCTIONS INSIDE.
*/
// class definitions right here.

class gameObject
{
public:
	std::vector<DWORD> componentList;
};

class manager
{
private:
	manager();
	static manager* instance;
public:

	manager* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new manager;
		}

		return instance;
	}

	template<typename component>
	void addComponent(gameObject object);

	template<typename expectedReturn>
	expectedReturn getComponent(gameObject object, int ID)
	{
		expectedReturn* obj = reinterpret_cast<expectedReturn*>(object.componentList[ID]);
		return obj;
	}
};
manager* manager::instance = 0;

// functions here

template<typename component>
void manager::addComponent(gameObject object)
{
	component* c = new component * (object); // attaches components to a object.
	object.componentList.insert(c.ID, c);
}

