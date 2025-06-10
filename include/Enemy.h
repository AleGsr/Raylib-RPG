#pragma once
#include "raylib.h"
#include "GameObject.h"
#include "raymath.h"
#include <string>



class Enemy : public GameObject
{
public:
	float x, y;
	float speed = 100.0f;

	GameObject* playerFollow;
	Enemy(char* _name, float xPos, float yPos) : GameObject(_name), x(xPos), y(yPos) {}

	void Start() override;
	void Update() override;
	void Draw() override;


};

