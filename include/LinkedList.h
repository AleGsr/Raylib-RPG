#pragma once
#include <iostream>
#include "LLNode.h"

template <class T>
class LinkedList
{
protected:
	LLNode<T>* head;

public:
	//lista vacia

	//agrega elemento al final de la lista ligada
	LLNode<T>* AddNode(T* _data)
	{
		LLNode<T>* newNode = new LLNode<T>(_data);

		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			LLNode<T>* iter = head;
			while (iter->next != nullptr)
			{
				iter = iter->next;
			}
			iter->next = newNode;
			newNode->prev = iter;
		}

		return newNode;
	}

	//Remover el ultimo nodo
	void RemoveLastNode()
	{
		if (head == nullptr) return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		LLNode<T>* iter = head;
		while (iter->next->next != nullptr)
		{
			iter = iter->next;
		}

		delete iter->next;
		iter->next = nullptr;
	}

};

