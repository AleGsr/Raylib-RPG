#include "Inventory.h"

void Inventory::AddItem(Item* _item)
{
	currentItem = AddNode(_item);
	_item->SetInventory(this);
}

void Inventory::nextItem()
{
	if (currentItem == nullptr)
	{
		currentItem = head;
		return;
	}

	if (currentItem->next != nullptr)
	{
		currentItem = currentItem->next;
	}
	else
	{
		currentItem = head;
	}
}

void Inventory::prevItem()
{
	if (currentItem == nullptr)
	{
		currentItem = head;
		return;
	}

	if (currentItem->prev != nullptr)
	{
		currentItem = currentItem->prev;
	}
	else
	{
		if (head == nullptr)
		{
			std::cout << "ERROR: El inventario está vacío." << std::endl;
			return;
		}

		LLNode<Item>* iter = head;
		while (iter->next != nullptr)
			iter = iter->next;

		currentItem = iter;
	}
}

void Inventory::debugPrintContents()
{
	//iterar en la lista
	LLNode<Item>* iter = head;
	std::cout << "Item en inventario: " << std::endl;
	while (iter != nullptr)
	{
		std::cout << "\t" << iter->data->name << std::endl;
		iter = iter->next;
	}
}
