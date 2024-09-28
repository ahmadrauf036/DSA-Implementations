#include <iostream>
#include <stack>
using namespace std;


template <class T>
struct Node
{
	T data;
	Node* next;
};
template <class T>
class linkedList
{
	Node<T>* head;
	Node<T>* reverseRecursion(Node<T>* temp)
	{
		if (temp->next == nullptr)  // base case
		{
			head = temp;
			return temp;
		}
		Node<T>* newNode = reverseRecursion(temp->next);
		newNode->next = temp;
		temp->next = nullptr;
		return temp;
	}
	void reverseUsingStack(Node<T>* temp)
	{
		stack<Node<T>*> st;
		while (temp!=nullptr)
		{
			st.push(temp);
			temp = temp->next;
		}
		st.top()->next = nullptr;
		Node<T>* prev = st.top();
		head = prev;
		st.pop();
		while (!st.empty())
		{
		
			prev->next = st.top();
			prev = prev->next;
			prev->next = nullptr;
			st.pop();
		}
	}
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
	}
	void insertAthead(T value)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = value;
		if (head == nullptr)
		{
			head = newNode;
			return;
		}
		newNode->next = head;
		head = newNode;
	}
	void deleteNode(T e)
	{
		Node<T>* temp = head;
		Node<T>* toDelete;
		if (head->data == e)
		{
            toDelete=head;
			head = head->next;
            delete toDelete;
			return;
		}
		while (temp->next != nullptr)
		{
			if (temp->next->data == e)
			{
				toDelete = temp;
				temp->next = temp->next->next;
				delete toDelete;
				return;
			}
			temp = temp->next;
		}
		cout << "Element doesn't exists." << endl;
	}

	void reverseList()
	{
		Node<T>* prev = nullptr, * nex = head->next, * current = head;
		while (current != nullptr)
		{

			current->next = prev;

			prev = current;
			current = nex;
			if (nex != nullptr)
				nex = nex->next;
		}
		head = prev;

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
	}
	void reverseRecursion()
	{
		reverseRecursion(head);
	}
	void reverseUsingStack()
	{
		reverseUsingStack(head);
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
	//l1.insertAthead(0);
	//l1.deleteNode(0);
	// l1.reverseList();
	//l1.display();

	l1.reverseUsingStack();
	l1.display();
}