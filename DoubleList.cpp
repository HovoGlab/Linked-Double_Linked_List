#include <iostream>


struct DoubleList
{
	int data; 
	DoubleList  *next;
	DoubleList  *prev;
};

DoubleList  * head;

void AddList(int value, int position)
{
	DoubleList  *node = new DoubleList;
	node->data = value; 
	if (head == NULL)
	{
		node->next = node; 
		node->prev = node; 
		head = node; 
	}
	else
	{
		DoubleList *p = head;
		for (int i = position; i > 1; i--) {
			p = p->next;
		}
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
	std::cout << std::endl;
	std::cout << "elementy avelacvac e" << std::endl;
	std::cout << std::endl;
}

int DeleteList(int position)
{
	if (head == NULL) { 
		std::cout << "cucaky datark e" << std::endl;
		return 0;
	}

	if (head == head->next)	{
		delete head;
		head = NULL;
	}
	else {
		DoubleList  *a = head;
		for (int i = position; i > 1; i--) { 
			a = a->next; 
		}
		if (a == head) {
			head = a->next;
		}
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}
	std::cout << std::endl;
	std::cout << "elementy jnjvac e " << std::endl;
	std::cout << std::endl;
}

void PrintList()
{
	if (head == NULL) {
		std::cout << "cucaky datark e " << std::endl;
	}
	else {
		DoubleList *a = head;
		std::cout << std::endl;
		std::cout << "cucaki elementnery: ";
		do
		{
			std::cout << a->data << " ";
			a = a->next;
		} while (a != head);
		std::cout << std::endl;
	}
}

int main()
{
	
	int value;
	int position;
	int x;
	do
	{
		std::cout << "1. avelacnel element" << std::endl;
		std::cout << "2. jnjel element" << std::endl;
		std::cout << "3. durs berel cucaky" << std::endl;
		std::cout << "0. elq" << std::endl;
		std::cout << std::endl;
		std::cout << "operaciayi hamary > ";
		std::cin >> x;
		switch (x)
		{
		case 1:
			std::cout << "arjeq > ";
			std::cin >> value;
			std::cout << "dirq > ";
			std::cin >> position;
			AddList(value, position);
			break;
		case 2:
			std::cout << "dirq > "; 
			std::cin >> position;
			DeleteList(position);
			break;
		case 3: PrintList();
			break;
		}
	} while (x != 0);
}



