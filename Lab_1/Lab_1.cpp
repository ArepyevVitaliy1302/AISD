#include <iostream>
#include <fstream>
#include <string>
using namespace std;


template <typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	int GetSize() { return Size; }
	void delete_indx(const int index);
	void add_indx(const int index, T data);
	void add_end(T data);
	void delete_end();
	void add_head(T data);
	void delete_head();
	void clear();
	void shift_element_indx(const int index, T data);
	void add_list_indx(const int index, List list);
	void void_check();



	T& operator[](const int index);

private:

	template <typename T>

	class Node
	{
	public:
		Node *pNext;
		T data;
		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T> *head;
};

template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;

}


template <typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else 
	{
		Node<T> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}

		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
void List<T>::delete_indx(const int index)
{
	Node<T> *current = head;
	Node<T> *temp;

	if (GetSize() - 1 <= index)
	{
		delete_end();
	}
	else if (index == 0)
	{
		delete_head();
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			current = current->pNext;
		}

		temp = current->pNext;

		current->pNext = current->pNext->pNext;

		delete temp;

		Size--;
	}
}

template<typename T>
void List<T>::add_indx(const int index, T data)
{
	Node<T> *current = head;
	Node<T> *temp;

	if (GetSize() < index)
	{
		add_end(data);
	}
	else if (index == 0)
	{
		add_head(data);
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			current = current->pNext;
		}

		temp = current->pNext;

		current->pNext = new Node<T>(data);

		current = current->pNext;

		current->pNext = temp;

		Size++;
	}
}

template<typename T>
void List<T>::add_end(T data)
{
	Node<T> *current = this->head;

	while (current->pNext != nullptr)
	{
		current = current->pNext;
	}

	current->pNext = new Node<T>(data);

	Size++;
}

template<typename T>
void List<T>::delete_end()
{
	Node<T> *current = this->head;

	while (current->pNext != nullptr)
	{
		current = current->pNext;
	}

	delete current;

	Size--;
}

template<typename T>
void List<T>::add_head(T data)
{
	Node<T> *temp = this->head;

	head = new Node<T>(data);
	head->pNext = temp;

	Size++;
}

template<typename T>
void List<T>::delete_head()
{
	Node<T> *temp = head;
	head = head->pNext;

	delete temp;
	
	Size--;

}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		delete_head();
	}
}

template<typename T>
void List<T>::shift_element_indx(const int index, T data)
{
	Node<T> *current = head;

	if (index > GetSize())
	{
		add_end(data);
	}
	else if (index == 0)
	{
		head->data = data;
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			current = current->pNext;
		}
		current->data = data;
	}
}

template<typename T>
void List<T>::add_list_indx(const int index, List list)
{
	Node<T> *temp;
	Node<T> *current = head;

	if (index == 0)
	{
		temp = head;
		head = list.head;
		current = list.head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}

		current->pNext = temp;
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			current = current->pNext;
		}

		temp = current->pNext;

		current->pNext = list.head;

		current = list.head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}

		current->pNext = temp;
	}

	Size = Size + list.GetSize();
}

template<typename T>
void List<T>::void_check()
{
	if (GetSize() == 0)
	{
		cout << "LIST CLEAR!" << endl;
	}
	else
	{
		cout << "LIST NOT CLEAR!" << endl;
	}
}

template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T> *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
			break;
		}

		current = current->pNext;
		counter++;
	}
}



int main()
{

	setlocale(LC_ALL, "ru");

	List<int> lst;
	List<int> lst_2;

	lst.push_back(1);
	lst.push_back(10);
	lst.push_back(100);

	lst_2.push_back(2);
	lst_2.push_back(3);
	lst_2.push_back(4);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << ' ';
	}

	cout << endl;

	lst.add_list_indx(2, lst_2);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << ' ';
	}

	cout << endl;

	lst.add_end(123);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << ' ';
	}

	cout << endl;

	lst.add_head(333);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << ' ';
	}

	cout << endl;

	lst.add_indx(1, 300);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << ' ';
	}

	cout << endl;

	lst.delete_end();

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << ' ';
	}

	cout << endl;

	lst.delete_head();

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << ' ';
	}

	cout << endl;

	lst.delete_indx(3);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << ' ';
	}

	cout << endl;

	lst.shift_element_indx(5, 385);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << ' ';
	}

	cout << endl;

	lst.void_check();

	lst.clear();

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << ' ';
	}

	cout << endl;

	lst.void_check();

	return 0;
}