#include "Enemy.h"

void Enemy::Start()
{
	texture = LoadTexture("Enemy.png");

	//Posicion inicial
	position = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };//Cambiar posici�n
	float speed = 100;
}

void Enemy::Update()
{
	//Caminar hacia el target que ser�a el player

}

void Enemy::Draw()
{
	DrawTexture(texture, position.x, position.y, WHITE);
	//DrawText("PLAYER", position.x, position.y - 40, 10, WHITE);
}
