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


	Texture2D logroIcon;
	bool hasIcon;


	
	PanelMensaje(float posX, float width, float height, int _timeOnScreen)
	{
		position = { posX, -height }; //Start off-screen
		size = { width, height };
		timeOnScreen = _timeOnScreen;
		timer = 0;
		desiredPositionY = -height;
		state = hidden;

		logroIcon = LoadTexture("logros/default.png");
	}

	PanelState GetState()
	{
		return state;
	}

	void update()
	{
		if (state == hidden) return;

		else if (state == moving)
		{
			if (position.y != desiredPositionY)
			{
				position.y += (desiredPositionY - position.y) * 1.0f * GetFrameTime();
			}

			if (fabs(position.y - desiredPositionY) < 0.1f)
			{
				position.y = desiredPositionY;

				if (desiredPositionY > 0) 
				{
					state = showing;
					timer = 0;
				}
				else 
				{
					state = hidden;
				}
			}
		}
		else if (state == showing)
		{
			timer += GetFrameTime();
			if (timer > timeOnScreen)
			{
				desiredPositionY = -size.y - 10;
				state = moving;
			}
		}
	}


	void draw()
	{
		// Dibuja el fondo del panel
		DrawRectangle(position.x, position.y, size.x, size.y, BEIGE);
		DrawRectangle(position.x + 8, position.y + 8, size.x - 16, size.y - 16, WHITE);
		DrawRectangleLines(position.x, position.y, size.x, size.y, DARKBLUE);

		// Dibuja imagen del logro (si est� cargada)
		DrawTexture(logroIcon, position.x + 10, position.y + 10, WHITE);

		// Dibuja texto a la derecha de la imagen
		DrawText(message.c_str(), position.x + 60, position.y + 15, 20, DARKGRAY);

	}
	
	void Show(std::string msg)
	{
		//Cada vez que se mande a llamar show, guardar en un stack el mensaje deseado

		state = moving;
		timer = 0;
		message = msg;
		desiredPositionY = 10; 
		position.y = -size.y - 10; 

		if (logroIcon.id != 0) UnloadTexture(logroIcon);

		std::string path = msg + ".png";
		logroIcon = LoadTexture(path.c_str());

	}


};

