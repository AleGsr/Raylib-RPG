#include "Enemy.h"

void Enemy::Start()
{
	texture = LoadTexture("Enemy.png");

	//Posicion inicial
	position = { 600, 600 };//Cambiar posición
	float speed = 100;
}

void Enemy::Update()
{
	//Caminar hacia el target que sería el player

}

void Enemy::Draw()
{
	DrawTexture(texture, position.x, position.y - 20, WHITE);
	DrawText(getUID().c_str(), position.x, position.y - 20, 10, WHITE);
	//DrawText("PLAYER", position.x, position.y - 40, 10, WHITE);
}
