#include "Enemy.h"

void Enemy::Start()
{
	texture = LoadTexture("Enemy.png");

	//Posicion inicial
	position = { x, y };//Cambiar posici�n
	float speed = 100;
}

void Enemy::Update()
{
	
}

void Enemy::Draw()
{
	DrawTexture(texture, position.x, position.y, WHITE);
}
