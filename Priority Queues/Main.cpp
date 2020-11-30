#include<iostream>
#include<string>
using namespace std;

class patient {
	string name;
	string disease;
	string id;
public:
	patient() { }
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
	void setDisease(string d)
	{
		disease = d;
	}
	string getDisease()
	{
		return disease;
	}
	void setID(string i)
	{
		id = i;
	}
	string getID()
	{
		return id;
	}
};
struct node {
	patient data;
	node* next=NULL;
};
class queue {
	node* front;
	node* rear;
public:
	queue()
	{
		rear = NULL;
		front = NULL;
	}
	bool isEmpty()
	{
		if (rear == NULL)
			return true;
		return false;
	}
	void enqueue(patient p)
	{
		node* temp = new node();
		temp->data = p;
		temp->next = NULL;
		if (isEmpty())
		{
			front = temp;
			rear = temp;
			return;
		}
		rear->next = temp;
		rear = rear->next;
	}
	void dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is Already Empty";
			return;
		}
		if (front == rear)
		{
			front = NULL;
			rear = NULL;
			return;
		}
		node* temp = front;
		front = front->next;
		cout << "\nDequeued member : " + temp->data.getName();
		delete temp;
	}
	void display()
	{
		if (isEmpty())
		{
			cout << "\nQueue is Empty";
			return;
		}
		node* temp = front;
		while (temp != NULL)
		{
			cout << "\nPatient : " + temp->data.getName();
			temp = temp->next;
		}
	}
	~queue()
	{
		while (front != rear)
		{
			node* temp = front;
			front = front->next;
			delete temp;
		}
		delete front;
		delete rear;
	}
};
int main()
{
	patient p;
	p.setName("Hassam Ullah");
	queue q;
	q.enqueue(p);
	q.display();
	return 0;
}