#include <iostream>

template <typename T>
class List {
public:
	List();
	void insert (int pos, T value);
	int get_size();
	void remove (int pos);
	int find (T value);
	void print ();

public:
	struct Node {
		T value;
		Node* next;
		Node() : next(nullptr){}
	};

private:
	Node * m_head;
};

template <typename T>
List<T>::List() {
	m_head = nullptr;
}

int main() {
	List<int> lst;
	lst.insert(0, 15);
	lst.insert(0, 25);
	lst.insert(1, 35);
	lst.insert(2, 45);
	lst.insert(0, 5);
	lst.insert(3, 7);
	lst.remove(2);
	lst.print();
	std::cout << std::endl;
	std::cout << lst.find(35) << std::endl;
}

template <typename T>
void List<T>::insert(int pos, T value) {
	if (0 == pos) {
		Node* tmp = new Node();
		tmp->value = value;
		tmp->next = m_head;
		m_head = tmp;
	}
	else if (pos == get_size()) {
		Node* cur = m_head;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = new Node();
		cur->next->value = value;
	}
	else {
		Node * cur = m_head;
		int count = 1;
		while (count < pos) {
			cur = cur->next;
			++count;
		}
		Node* tmp = cur->next;
		cur->next = new Node();
		cur->next->value = value;
		cur->next->next = tmp;
	}

}

template <typename T>
void List<T>::remove(int pos) {
	if (0 == pos) {
		Node* tmp = m_head;
		m_head = m_head->next;
		delete tmp;
	}
	else {
		Node* cur = m_head;
		int count = 1;
		while (count < pos) {
			cur = cur->next;
			++count;
		}
		Node* tmp = cur->next;
		cur->next = tmp->next;
		delete tmp;
	}
}

template <typename T>
int List<T>::find(T value) {
	int pos = 0;
	Node* cur = m_head;
	while (cur && cur->value != value) {
		cur = cur->next;
		++pos;
	}

	return (pos == get_size()) ? -1 : pos;
}

template <typename T>
void List<T>::print() {
	Node* ptr = m_head;
	while (ptr != nullptr) {
		std::cout << "[ " << ptr->value << " ]";
		ptr = ptr->next;
	}
}

int List<int>::get_size() {
	Node* print = m_head;
	int tmp = -1;
	while (print != nullptr) {
		print = print->next;
		++tmp;
	}
	return tmp;
}
