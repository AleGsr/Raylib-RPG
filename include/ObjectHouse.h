#pragma once
#include "raylib.h"
#include "GameObject.h"
#include <string>


class ObjectHouse: public GameObject
{
public:
	ObjectHouse(char* _name) : GameObject(_name)
	{

	}

	void Start() override;
	void Update() override;
	void Draw() override;

};

