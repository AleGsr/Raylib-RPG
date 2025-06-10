#include "Inventory.h"

void Inventory::AddItem(Item* _item)
{
	LLNode<Item>* node = AddNode(_item);
	if (currentItem == nullptr) // si no hay item seleccionado
		currentItem = node;
}

void Inventory::nextItem()
{
	if (currentItem && currentItem->next)
		currentItem = currentItem->next;
}

void Inventory::prevItem()
{
	if (currentItem && currentItem->prev)
		currentItem = currentItem->prev;
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
