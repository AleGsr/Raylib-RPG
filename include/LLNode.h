#pragma once

template <class T>
class LLNode
{
public:
	//ref al siguiente nodo de la lista
	LLNode<T>* next;

	//Esta losta ligada almacena floats
	T* data;

	//Dos constructores
	//Recordar el polymorfismo de OOP
	LLNode(T* _data) :data(_data), next(nullptr) {}
	LLNode(T* d, LLNode<T>* nxt) : data(d), next(nxt) {}
};

