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

				if (desiredPositionY > 0) // si se movió hacia abajo para mostrar
				{
					state = showing;
					timer = 0;
				}
				else // si se movió hacia arriba para ocultarse
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
		DrawRectangleLines(position.x, position.y, size.x, size.y, DARKBLUE);

		// Dibuja imagen del logro (si está cargada)
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
		desiredPositionY = 10; // 10 pixels from the top of the screen
		position.y = -size.y - 10; //start off-screen


		// Libera la imagen anterior si no es la default
		if (logroIcon.id != 0) UnloadTexture(logroIcon);

		// Determina la ruta basada en el mensaje
		std::string path = msg + ".png";
		logroIcon = LoadTexture(path.c_str());

	}


};

