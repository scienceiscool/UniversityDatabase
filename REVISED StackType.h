//Kathy Saad
//CPSC 131 - Section 01
//Assignment 04 - Use of Stacks
//April 11, 2013

#pragma once

const int MAX_ITEMS = 100; //Maximum number of items that could be on the stack

template<class ItemType>
class StackType
{
public:
	StackType();
	//Purpose: Default constructor
	//Precondition(s): Class exists
	//Postcondition(s): Stack is initialized

	bool IsEmpty() const;
	//Purpose: Determines whether the stack is empty
	//Precondition(s): Stack has been initialized
	//Postcondition(s): Returns true if stack is empty, and false if it is not empty

	bool IsFull() const;
	//Purpose: Determines whether the stack is full
	//Precondition(s): Stack has been initialized
	//Postcondition(s): Returns true if stack is full, and false if it is not full

	void Push(ItemType item);
	//Purpose: Adds newItem to the top of the stack
	//Precondition(s): Stack has been initialized
	//Postcondition(s): If the stack is not full, then newItem is pushed to the top of the stack

	void Pop();
	//Purpose: Removes top item from the stack
	//Precondition(s): Stack has been initialized
	//Postcondition(s): If the stack is not empty, then the top element has been removed from stack

	ItemType Top() const;
	//Purpose: Returns a copy of the top item on the stack
	//Precondition(s): Stack has been initialized
	//Postcondition(s): If the stack is not empty, then a copy of the top element is returned

private:
	int top;
	ItemType items[MAX_ITEMS];
};

//*******************************
//FUNCTION IMPLEMENTATIONS BELOW:
//*******************************

template<class ItemType>
StackType<ItemType>::StackType()
{
	top = -1;
}

template<class ItemType>
bool StackType<ItemType>::IsEmpty() const
{
	return (top == -1);
}

template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
	return (top == MAX_ITEMS - 1);
}

template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
	top++;
	items[top] = newItem;
}

template<class ItemType>
void StackType<ItemType>::Pop()
{
	top--;
}

template<class ItemType>
ItemType StackType<ItemType>::Top() const
{
	return items[top];
}