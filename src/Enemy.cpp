#include "Enemy.h"

void Enemy::Start()
{
	texture = LoadTexture("Enemy.png");

	//Posicion inicial
	position = { 600, 600 };//Cambiar posici�n
	float speed = 100;
}

void Enemy::Update()
{
	//Caminar hacia el target que ser�a el player
	if (playerFollow != nullptr)
	{
		Vector2 dir = Vector2Subtract(playerFollow->position, position);

		float distance = Vector2Length(dir);

		if (distance > 50)
		{
			dir = Vector2Normalize(dir);
			position = Vector2Add(position, Vector2Scale(dir, speed * GetFrameTime()));
		}
	}

}

void Enemy::Draw()
{
	DrawTexture(texture, position.x, position.y - 20, WHITE);
}
