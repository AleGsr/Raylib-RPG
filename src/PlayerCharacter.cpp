#include "PlayerCharacter.h"

void PlayerCharacter::Start()
{
	texture = LoadTexture("wabbit_alpha.png");
	inventory = new Inventory();

	//Posicion inicial
	position = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
	float speed = 100;
}

void PlayerCharacter::Update()
{

	//if (IsKeyDown(KEY_W)) speed.y = -500;
	//if (IsKeyDown(KEY_S)) velPlayer.y = 500;
	//if (IsKeyDown(KEY_A)) velPlayer.x = -500;
	//if (IsKeyDown(KEY_D)) velPlayer.x = 500;



	/*if (IsKeyDown(KEY_D))
	{
		position.x += speed * GetFrameTime();
		if (position.x > GetScreenWidth() - scrollBorder)
		{
			position.x = GetScreenWidth() - scrollBorder;
			cameraOffset.x += speed * GetFrameTime();
		}
	}
	if (IsKeyDown(KEY_A))
	{
		position.x -= speed * GetFrameTime();
		if (position.x < scrollBorder)
		{
			position.x = scrollBorder;
			cameraOffset.x -= speed * GetFrameTime();
		}
	}
	if (IsKeyDown(KEY_W))
	{
		position.y -= speed * GetFrameTime();
		if (position.y < scrollBorder)
		{
			position.y = scrollBorder;
			cameraOffset.y -= speed * GetFrameTime();
		}
	}

	if (IsKeyDown(KEY_S))
	{
		position.y += speed * GetFrameTime();
		if (position.y < GetScreenHeight() - scrollBorder)
		{
			position.y = GetScreenHeight() - scrollBorder;
			cameraOffset.y += speed * GetFrameTime();
		}
	}*/

	//position.x += speed.x * GetFrameTime();
	//position.y += speed.y * GetFrameTime();

	if (IsKeyPressed(KEY_I))
	{
		//asume que siempre tiene inventory
		inventory->nextItem();
	}
}

void PlayerCharacter::Draw()
{
	DrawTexture(texture, position.x, position.y, WHITE);
	DrawText("PLAYER", position.x, position.y - 40, 10, WHITE);

	//hud
	DrawRectangle(10, 10, 100, 30, WHITE);

	if (inventory != nullptr && inventory->currentItem != nullptr)
	{
		DrawText(inventory->currentItem->data->name.c_str(), 20, 20, 10, BLACK);
	}
	else
	{
		DrawText("EMPRT", 20, 20, 10, BLACK);
	}

	DrawText("Inventory", 10, 10, 10, BLACK);
}

//Va todo lo que concierne al main