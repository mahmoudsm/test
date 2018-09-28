#include <iostream>
using namespace std;
#include"DEQ.h"
// Constructor with argument, size is nelements, default 128
template <class Type>
DEQ<Type>::DEQ(int nelements)
{
	front = new node; // Empty
	rear = front;     // Empty
	cursor = front;   // Empty
	MaxSize = nelements;
	count = 0;        // Empty 
}

// Copy Constructor
template <class Type>
DEQ<Type>::DEQ(const DEQ<Type> &original)
	:MaxSize(original.MaxSize), front(original.front), rear(original.rear), cursor(original.cursor), count(original.count) // Copying values
{
	for (int i = 0; i < MaxSize; i++) { // Copying contents
		cursor->content = original.cursor->content; // Copying contents
		cursor = cursor->next; // Moving cursor pointer
		original.cursor = original.cursor->next; // Moving cursor pointer
	}
}


// Destructor
template <class Type>
DEQ<Type>::~DEQ()
{
	while (!DEQisEmpty()) { // If not empty
		Type v; // For removal
		Remove_Front(v); // Removes the first one by one
	}
}

// Add to the front
template <class Type>
void DEQ<Type>::Add_Front(Type v)
{
	if (DEQisFull()) cout << "DEQ is Full" << endl; // Exits if full
	else if (DEQisEmpty()) { // If empty
		node* temp = new node; // Temprorary node
		front = temp; // Moving front
		rear = temp; // Moving rear
		cursor = temp; // Moving cursor
		front->content = v; // Assigning content
		front->next = NULL;
		count++; // Incrementing length
	}
	else
	{
		node* temp = new node; // Temprorary node
		temp->next = front;
		front = temp; // Moving front
		front->content = v; // Assigning content
		count++; // Incrementing length
	}
}

// Add to the rear
template <class Type>
void DEQ<Type>::Add_Rear(Type v)
{
	if (DEQisFull()) cout << "DEQ is Full" << endl; // Exits if full
	else if (DEQisEmpty()) { // If empty
		node* temp = new node; // Temprorary node
		front = temp; // Moving front
		rear = temp; // Moving rear
		cursor = temp; // Moving cursor
		front->content = v; // Assigning content
		front->next = NULL;
		count++; // Incrementing length
	}
	else
	{
		node* temp = new node; // Temprorary node
		rear->next = temp;
		rear = rear->next; // Moving rear
		rear->content = v; // Assigning content
		rear->next = NULL;
		count++; // Incrementing length
	}
}

// Remove from the front
template <class Type>
void DEQ<Type>::Remove_Front(Type &v)
{
	if (DEQisEmpty()) cout << "DEQ is Empty" << endl; // Exits if empty
	else
	{
		v = front->content; // Output content
		cursor = front; // Moving cursor
		front = front->next; // Moving front
		delete cursor; // Deleting the first node
		count--; // Decrementing length
	}
}

// Remove from the rear
template <class Type>
void DEQ<Type>::Remove_Rear(Type &v)
{
	if (DEQisEmpty()) cout << "DEQ is Empty" << endl; // Exits if empty
	else
	{
		int c = 0; // To reach the node before the last
		cursor = front; // Moving cursor
		while (c < count - 2) {  // To reach the node before the last
			cursor = cursor->next;
			c++;
		}
		rear = cursor; // Assigning rear the node before the last
		cursor = cursor->next; // Reached the last node
		v = cursor->content; // Output content
		rear->next = NULL;
		delete cursor; // Deleting the last node
		count--; // Decrementing length
	}
}

// Retrieve front without removing it
template <class Type>
void DEQ<Type>::View_Front(Type &v) const
{
	if (DEQisEmpty()) cout << "DEQ is Empty" << endl; // Exits if empty
	else 	v = front->content; // Output front content
}

// Retrieve rear without removing it
template <class Type>
void DEQ<Type>::View_Rear(Type &v) const
{
	if (DEQisEmpty()) cout << "DEQ is Empty" << endl; // Exits if empty
	else 	v = rear->content; // Output rear content
}

// Test for Empty DEQ
template <class Type>
bool DEQ<Type>::DEQisEmpty() const
{
	return (count == 0); // True if empty
}

// Test for Full DEQ
template <class Type>
bool DEQ<Type>::DEQisFull() const
{
	return (count == MaxSize); // True if full
}

// DEQ Length
template <class Type>
int DEQ<Type>::DEQ_Length() const
{
	return count; // Returns length
}
