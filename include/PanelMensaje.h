#pragma once
#include "raylib.h"
#include <string>


enum PanelState
{
	hidden, moving, showing
};

class PanelMensaje
{
private:
	float timer;
	float desiredPositionY;
	PanelState state = hidden;


public:
	Vector2 position;
	Vector2 size;
	int timeOnScreen;
	std::string message;

	
	PanelMensaje(float posX, float width, float height, int _timeOnScreen)
	{
		position = { posX, -height }; //Start off-screen
		size = { width, height };
		timeOnScreen = _timeOnScreen;
		timer = 0;
		desiredPositionY = -height;
		state = hidden;
	}

	PanelState GetState()
	{
		return state;
	}

	void update()
	{
		if (state == hidden)
		{
			return;
		}
		else if (state == moving)
		{
			//interpolacion de movimiento
			if (position.y != desiredPositionY)
			{
				//lerp position
				position.y += (desiredPositionY - position.y) * 1.0f * GetFrameTime();

			}
			if (position.y - desiredPositionY < 0.1f)
			{
				position.y = desiredPositionY;
				state = showing;
				timer = 0;
			}

		}
		else if (state == showing)
		{
			timer += GetFrameTime();
			if (timer > timeOnScreen)
			{
				//start moving
				desiredPositionY = -size.y - 10; //move off-screen
				state = moving;
			}
		}

	}


	void draw()
	{
		DrawRectangle(position.x, position.y, size.x,size.y, BEIGE);
		DrawRectangleLines(position.x, position.y, size.x, size.y, DARKBLUE);
		DrawText(message.c_str(), position.x + 10, position.y + 10, 20, DARKGRAY);
	}
	
	void Show(std::string msg)
	{
		//Cada vez que se mande a llamar show, guardar en un stack el mensaje deseado


		state = moving;
		timer = 0;
		message = msg;
		desiredPositionY = 10; // 10 pixels from the top of the screen
		position.y = -size.y - 10; //start off-screen
	}


};

