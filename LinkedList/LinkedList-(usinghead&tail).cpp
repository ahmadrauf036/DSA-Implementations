#include <iostream>
using namespace std;

template <class Type>
struct Node
{
	Type data;
	Node* next;
};

template <class Type>
class linkedList
{
protected:
	Node<Type>* head;
	Node<Type>* tail;

public:
	linkedList();

	virtual void insertAtTail(Type data) = 0;
	virtual Type deleteFromTail() = 0;
	virtual void insertAtHead(Type data) = 0;
	virtual Type deleteFromHead() = 0;
	virtual int countAllNodes() = 0;
	virtual int sumOfEvenNodes() = 0;
	virtual int sumOfOddNodes() = 0;
	virtual void displayNodes() = 0;
	
};
template<class Type>
linkedList<Type>::linkedList()
{
	head = nullptr;
	tail = nullptr;
}
template <class Type>
class myLinkedList :public linkedList<Type>
{
public:
	void insertAtTail(Type data);
	Type deleteFromTail();
	void insertAtHead(Type data);
	Type deleteFromHead();
	int countAllNodes();
	int sumOfEvenNodes();
	int sumOfOddNodes();
	void displayNodes();
};



int main()
{
	cout << "Delete from tail;" << endl << endl;
	myLinkedList<int> l1,l2,l3,l4;
	cout << "l1: " << endl;
	l1.insertAtTail(1);
	l1.insertAtTail(2);
	l1.insertAtTail(3);
	l1.insertAtTail(4);
	l1.displayNodes();
	cout << "Sum of even nodes: " << l1.sumOfEvenNodes() << endl;
	cout << "Sum of odd nodes: " << l1.sumOfOddNodes() << endl;
	cout << "After deletion: " << endl;
	cout << "Deleted data: " << l1.deleteFromTail() << endl;
	l1.displayNodes();
	cout << "Total Nodes: " << l1.countAllNodes() << endl;
	l1.insertAtHead(0);
	l1.displayNodes();
	cout << endl;

	cout << "l2: " << endl;
	l2.insertAtTail(1);
	l2.insertAtTail(2);
	l2.insertAtTail(3);
	l2.displayNodes();
	cout << "Sum of even nodes: " << l2.sumOfEvenNodes() << endl;
	cout << "Sum of odd nodes: " << l2.sumOfOddNodes() << endl;
	cout << "After deletion: " << endl;
	cout << "Deleted data: " << l2.deleteFromTail() << endl;
	l2.displayNodes();
	cout << "Total Nodes: " << l2.countAllNodes() << endl;
	l2.insertAtHead(0);
	l2.displayNodes();
	cout << endl;

	cout << "l3: " << endl;
	l3.insertAtTail(1);
	l3.insertAtTail(2);
	l3.displayNodes();
	cout << "Sum of even nodes: " << l3.sumOfEvenNodes() << endl;
	cout << "Sum of odd nodes: " << l3.sumOfOddNodes() << endl;
	cout << "After deletion: " << endl;
	cout << "Deleted data: " << l3.deleteFromTail() << endl;
	l3.displayNodes();
	cout << "Total Nodes: " << l3.countAllNodes() << endl;
	l3.insertAtHead(0);
	l3.displayNodes(); 
	cout << endl;


	cout << "l4: " << endl;
	l4.insertAtTail(20);
	l4.displayNodes();
	cout << "Sum of even nodes: " << l4.sumOfEvenNodes() << endl;
	cout << "Sum of odd nodes: " << l4.sumOfOddNodes() << endl;
	cout << "After deletion: " << endl;
	cout << "Deleted data: " << l4.deleteFromTail() << endl;
	l4.displayNodes();
	cout << "Total Nodes: " << l4.countAllNodes() << endl;
	l4.insertAtHead(0);
	l4.displayNodes();
	cout << endl;

	cout << endl << "-------------------------------------------------------" << endl << endl;
	myLinkedList<int> dl1, dl2, dl3, dl4;
	cout << "Delete from head;" << endl << endl;
	cout << "dl1: " << endl;
	dl1.insertAtTail(1);
	dl1.insertAtTail(2);
	dl1.insertAtTail(3);
	dl1.insertAtTail(4);
	dl1.displayNodes();
	cout << "Sum of even nodes: " << dl1.sumOfEvenNodes() << endl;
	cout << "Sum of odd nodes: " << dl1.sumOfOddNodes() << endl;
	cout << "After deletion: " << endl;
	cout << "Deleted data: " << dl1.deleteFromHead() << endl;
	dl1.displayNodes();
	cout << "Total Nodes: " << dl1.countAllNodes() << endl;
	cout << endl;


	cout << "dl2: " << endl;
	dl2.insertAtTail(1);
	dl2.insertAtTail(2);
	dl2.insertAtTail(3);
	dl2.displayNodes();
	cout << "Sum of even nodes: " << dl2.sumOfEvenNodes() << endl;
	cout << "Sum of odd nodes: " << dl2.sumOfOddNodes() << endl;
	cout << "After deletion: " << endl;
	cout << "Deleted data: " << dl2.deleteFromHead() << endl;
	dl2.displayNodes();
	cout << "Total Nodes: " << dl2.countAllNodes() << endl;
	cout << endl;

	cout << "dl3: " << endl;
	dl3.insertAtTail(1);
	dl3.insertAtTail(2);
	dl3.displayNodes();
	cout << "Sum of even nodes: " << dl3.sumOfEvenNodes() << endl;
	cout << "After deletion: " << endl;
	cout << "Deleted data: " << dl3.deleteFromHead() << endl;
	dl3.displayNodes();
	cout << "Total Nodes: " << dl3.countAllNodes() << endl << endl;;

	cout << "dl4: " << endl;
	dl4.insertAtTail(20);
	dl4.displayNodes();
	cout << "Sum of even nodes: " << dl4.sumOfEvenNodes() << endl;
	cout << "Sum of odd nodes: " << dl4.sumOfOddNodes() << endl;
	cout << "After deletion: " << endl;
	cout << "Deleted data: " << dl4.deleteFromHead() << endl;
	dl4.displayNodes();
	cout << "Total Nodes: " << dl4.countAllNodes() << endl;
	cout << endl;


}

template<class Type>
void myLinkedList<Type>::insertAtTail(Type data)
{
	Node<Type>* newNode = new Node<Type>;
	newNode->data = data;
	newNode->next = nullptr;
	if (this->head == nullptr)
	{
		this->head = newNode;
		return;
	}
	else if (this->tail == nullptr)
	{
		this->tail = newNode;
		this->head->next = this->tail;
		return;
	}
	this->tail->next = newNode;
	this->tail = newNode;
}

template<class Type>
Type myLinkedList<Type>::deleteFromTail()
{
	if (this->head == nullptr && this->tail == nullptr)
	{
		return Type();
	}
	if (this->head != nullptr && this->tail == nullptr)
	{
		Type data = this->head->data;
		Node<Type>* toDelete = this->head;
		delete toDelete;
		this->head = nullptr;
		return data;
	}
	if (this->head->next->next == nullptr)
	{
		Node<int>* toDelete = this->tail;
		int data = this->tail->data;
		delete toDelete;
		this->tail = nullptr;
		this->head->next = nullptr;
		return data;
	}
	Type data = this->tail->data;
	Node<Type>* toDelete = this->tail;
	Node<Type>* temp = this->head;
	while (temp->next->next != nullptr)
	{
		temp = temp->next;
	}
	if (this->head == temp)
	{
		this->tail = nullptr;
		return data;
	}
	else
		this->tail = temp;
	this->tail->next = nullptr;

	return data;
}

template<class Type>
void myLinkedList<Type>::insertAtHead(Type data)
{
	Node<Type>* newNode = new Node<Type>;
	newNode->data = data;
	newNode->next = nullptr;
	if (this->head == nullptr)
	{
		this->head = newNode;
		return;
	}
	newNode->next = this->head;
	this->head = newNode;
}

template<class Type>
Type myLinkedList<Type>::deleteFromHead()
{
	if (this->head == nullptr)
	{
		cout << "Empty" << endl;
		return Type();
	}
	if (this->head->next == nullptr)
	{
		Node<Type>* toDelete = this->head;
		Type data = this->head->data;
		delete toDelete;
		this->head = nullptr;
		return data;
	}
	Node<Type>* toDelete = this->head;
	Type data = this->head->data;
	this->head = this->head->next;
	if (this->head->next == nullptr)
	{
		this->tail = nullptr;
	}
	delete toDelete;
	return data;
}

template<class Type>
int myLinkedList<Type>::countAllNodes()
{
	if(this->head==nullptr)
		return 0;
	Node<Type>* temp = this->head;
	int s = 0;
	while (temp!=nullptr)
	{
		s++;
		temp = temp->next;
	}
	return s;
}

template<class Type>
int myLinkedList<Type>::sumOfEvenNodes()
{
	if (this->head == nullptr)
	{
		cout << "Empty" << endl; return int();
	}
	if (this->head->next==nullptr)
	{
		cout << "only one node exist." << endl; return int();
	}
	Node<Type>* temp = this->head->next;
	int sum = temp->data;
	while (temp->next!=nullptr && temp->next->next!=nullptr)
	{
		temp = temp->next->next;
		sum += temp->data;
	}
	return sum;
}

template<class Type>
int myLinkedList<Type>::sumOfOddNodes()
{
	if (this->head == nullptr)
	{
		cout << "Empty" << endl; return int();
	}
	Node<Type>* temp = this->head;
	int sum = temp->data;
	while (temp->next != nullptr && temp->next->next != nullptr)
	{
		temp = temp->next->next;
		sum += temp->data;
	}
	return sum;
}

template<class Type>
void myLinkedList<Type>::displayNodes()
{
	if (this->head == nullptr)
	{
		cout << "empty" << endl;
		return;
	}
	Node<Type>* temp = this->head;
	while (temp!=nullptr)
	{
		cout << temp->data << " ";
		temp= temp->next;
	}
	cout << endl;
}
