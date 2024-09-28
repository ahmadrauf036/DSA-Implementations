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
class circularLinkedList
{
	Node<T>* head;
public:
	circularLinkedList()
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
			head->next = head;
			head->prev = head;
			return;
		}
		Node<T>* temp = head;


		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = head;
		head->prev = newNode;
	}
	void insertAthead(T value)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = value;
		newNode->next = head;
		if (head == nullptr)
		{
			newNode->prev = head;
			head = newNode;
			return;
		}
		
		Node<T>* temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		newNode->prev = head->prev;
		head->prev = newNode;
		head = newNode;
		temp->next = head;
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
		while (temp->next != head)
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
		if (head->next == head)
		{
			Node<T>* toDelete;
			toDelete = head;
			head = nullptr;
			delete head;
			return;
		}
		Node<T>* temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		Node<T>* toDelete;
		toDelete = head;
		head->next->prev = head->prev;
		head = head->next;
		temp->next = head;

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
		if (head->next == head)
		{
			Node<T>* toDelete;
			toDelete = head;
			head = nullptr;
			delete toDelete;
			return;
		}
		Node<T>* toDelete;
		Node<T>* temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		toDelete = temp;
		temp->prev->next = head; 
		head->prev = temp->prev;
	}
	void reverseList_display()
	{
		if (head == nullptr)
		{
			cout << "Empty" << endl;
			return;
		}
		Node<T>* end = head;
		while (end->next != head)
		{
			end = end->next;
		}
		Node<T>* last = end;
		while (end->prev != last)
		{
			cout << end->data << " ";
			end = end->prev;
		}
		cout << end->data << " ";
		cout << endl;
	}

	void display()
	{
		if (head == nullptr)
		{
			cout << "empty" << endl;
			return;
		}
		Node<T>* temp;
		temp = head;
		while (temp->next != head)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data << " ";
		cout << endl;
	}
};


int main()
{
	circularLinkedList<int> l1;
	l1.insertAtTail(1);
	l1.insertAtTail(2);
	l1.insertAtTail(3);
	l1.insertAtTail(4);
	l1.insertAtTail(5);
	l1.display();
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