#include <iostream>
using namespace std;


template <class T>
struct Node
{
	T data;
	Node* next;
	Node* prev;
};
template <class T>
class linkedList
{
	Node<T>* head;
public:
	linkedList()
	{
		head = nullptr;
	}
	void insertAtTail(T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->next = nullptr;
		newNode->prev = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		Node<T>* temp = head;
		

		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
	void insertAthead(T value)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = value;
		newNode->prev = nullptr;
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	void deleteNode(T e)
	{
		Node<T>* temp = head;
		Node<T>* toDelete;
		if (head->data == e)
		{
			toDelete = head;
			head = head->next;
			head->prev = nullptr;
			delete toDelete;
			return;
		}
		while (temp->next != nullptr)
		{
			if (temp->next->data == e)
			{
				toDelete = temp->next;
				temp->next = temp->next->next;
				temp->next->prev = temp;
				delete toDelete;
				return;
			}
			temp = temp->next;
		}
		cout << "Element doesn't exists." << endl;
	}
	void deleteAtHead()
	{
		if (head == nullptr)
		{
			cout << "Empty list" << endl;
			return;
		}
		Node<T>* temp = head;
		Node<T>* toDelete;
		toDelete = head;
		head = head->next;
		head->prev = nullptr;
		delete toDelete;
		return;
		
	}
	void deleteAtTail()
	{
		if (head == nullptr)
		{
			cout << "Empty list" << endl;
			return;
		}
		Node<T>* temp = head;
		Node<T>* toDelete;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		toDelete = temp;
		temp->prev->next = nullptr;	
	}
	void reverseList_display()
	{
		Node<T>* end=head;
		while (end->next != nullptr)
		{
			end = end->next;
		}
		while (end!=nullptr)
		{
			cout << end->data << " ";
			end = end->prev;
		}
		cout << endl;
	}

	void display()
	{
		Node<T>* temp;
		temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};


int main()
{
	linkedList<int> l1;
	l1.insertAtTail(1);
	l1.insertAtTail(2);
	l1.insertAtTail(3);
	l1.insertAtTail(4);
	l1.insertAtTail(5);
	l1.insertAthead(0);
	l1.deleteNode(2);
	l1.reverseList_display();
	l1.display();
	l1.deleteAtHead();
	l1.display();

	l1.deleteAtTail(); 
	l1.display();
	l1.reverseList_display();


}