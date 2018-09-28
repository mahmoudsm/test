#pragma once

template <class Type>

class DEQ
{
public:

	DEQ(int nelements = 128);    // Constructor
	DEQ(const DEQ <Type> &);	// Copy Constructor
	~DEQ();					   // Destructor

							   // Member Functions
	void Add_Front(Type);			// Add to the front
	void Add_Rear(Type);			// Add to the rear
	void Remove_Front(Type &);		// Remove from the front
	void Remove_Rear(Type &);		// Remove from the rear
	void View_Front(Type &) const;	// Retrieve front without removal
	void View_Rear(Type &) const;	// Retrieve rear without removal 
	bool DEQisEmpty() const;		// Test for Empty DEQ
	bool DEQisFull() const;			// Test for full DEQ
	int  DEQ_Length() const;		// DEQ's length

private:
	class node			// Block of linked list
	{
	public:
		Type content;	// Node's content
		node *next;		// Pointer to next node	       
	};					// End of class node declaration

	typedef node * NodePointer;			// NodePointer as a data type
	NodePointer front, rear, cursor;   // Needed pointers
	int count, MaxSize;               // For counting
};

