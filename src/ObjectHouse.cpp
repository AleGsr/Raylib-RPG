#include "ObjectHouse.h"

void ObjectHouse::Start()
{
	texture = LoadTexture("House.png");

	//Posicion inicial
	position = { 700, 100 };//Cambiar posici�n
}

void ObjectHouse::Update()
{
}

void ObjectHouse::Draw()
{
	DrawTexture(texture, position.x , position.y, WHITE);
}
