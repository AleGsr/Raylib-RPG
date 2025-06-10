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
        : mensajes(10), 
        panel(GetScreenWidth() - 310, 300, 60, 3) 
    {
    }

    void AgregarMensaje(const std::string& msg)
    {
        mensajes.push(msg);
    }

    void Update()
    {
        panel.update();

        if (panel.GetState() == hidden && !mensajes.isEmpty())
        {
            std::string msg = mensajes.pop();
            panel.Show(msg);
        }
    }

    void Draw()
    {
        panel.draw();
    }
};

