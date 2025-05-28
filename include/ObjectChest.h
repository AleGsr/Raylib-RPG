#pragma once
#include "raylib.h"
#include "GameObject.h"
#include <string>


class ObjectChest: public GameObject
{
public:

	float speed = 100.0f;

	ObjectChest(char* _name) : GameObject(_name)
	{
	}

	void Start() override;
	void Update() override;
	void Draw() override;



};

