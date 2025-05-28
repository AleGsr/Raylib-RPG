#pragma once
#include <iostream>
#include "LLNode.h"

template <class T>
class LinkedList
{
protected:
	LLNode<T>* head;
	LLNode<T>* tail;

public:
	//lista vacia
	LinkedList() : head(nullptr), tail(nullptr) {}
	LinkedList(LLNode<T> *_hd) : head(_hd) {};

	//Imprimir el contenido
	//void PrintElements();

	//agrega elemento al final de la lista ligada
	LLNode<T>* AddNode(T* _data)
	{
		LLNode<T>* newNode = new LLNode<T>(_data);

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		//else
		//{
		//	/*tail->next = newNode;
		//	tail = newNode;*/
		//}

		//return newNode;

		LLNode<T>* iter = head;
		while (iter->next != nullptr)
			iter = iter->next;
		iter->next = new LLNode<T>(_data);
		return iter->next;

	}

	//Remover el ultimo nodo
	void RemoveLastNode()
	{
		if (head == nullptr)
			return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr; 
			return;
		}

		LLNode<T>* iter = head;
		while (iter->next->next != nullptr)
			iter = iter->next;

		delete iter->next;
		iter->next = nullptr;
		tail = iter; 
	}

};

