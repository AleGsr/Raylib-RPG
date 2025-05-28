#pragma once
#include "PanelMensaje.h"
#include "Stack.h"
#include <string>

class MessageSystem
{
private:
	Stack<std::string> mensajes;
	PanelMensaje panel;

public:
    MessageSystem()
        : mensajes(10), // máximo 10 mensajes en pila
        panel(GetScreenWidth() - 310, 300, 60, 3) // esquina superior derecha
    {
    }

    void AgregarMensaje(const std::string& msg)
    {
        mensajes.push(msg);
    }

    void Update()
    {
        panel.update();

        // Si el panel está oculto y hay mensajes pendientes
        if (panel.GetState() == hidden && !mensajes.isEmpty())
        {
            std::string msg = mensajes.pop(); // toma el siguiente mensaje
            panel.Show(msg); // mostrar en el panel
        }
    }

    void Draw()
    {
        panel.draw();
    }
};

