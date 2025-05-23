#pragma once
#include "raylib.h"
#include "GameObject.h"
#include <string>


class Enemy: public GameObject
{
public:

	float speed = 100.0f;

	Enemy(char* _name) : GameObject(_name)
	{
	}

	void Start() override;
	void Update() override;
	void Draw() override;


};

