#include "ObjectChest.h"

void ObjectChest::Start()
{
	texture = LoadTexture("Chest.png");

	//Posicion inicial
	position = { 500, 500 };//Cambiar posici�n
}

void ObjectChest::Update()
{
}

void ObjectChest::Draw()
{
	DrawTexture(texture, position.x - 200, position.y - 200, WHITE);
}
