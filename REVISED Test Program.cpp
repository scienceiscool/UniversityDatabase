//Kathy Saad
//CPSC 131 - Section 01
//Assignment 6 - Binary Search Tree
//April 25, 2013

typedef int ItemType;

#include <iostream>
#include "REVISED BinarySearchTree.h"

using namespace std;

void initialize(Tree<int> & tree);
//Preconditions: None.
//Postconditions: Tree is initialized and ready for use.

void insertAndPrint(Tree<int> & tree, ItemType number);
//Preconditions: None.
//Postconditions: Items are inserted and tree is printed out onto screen.

void retrieve(Tree<int> & tree, ItemType number);
//Preconditions: Tree exists, hopefully, with the binary search property.
//Postconditions: Items are found, or not found, depending on tree.

void deleteItems(Tree<int> & tree, ItemType number);
//Preconditions: Tree exists, hopefully.
//Postconditions: Items that needed to be deleted were deleted.

void destroy(Tree<int> & tree, ItemType number);
//Preconditions: Tree exists, hopefully.
//Postconditions: Tree is destroyed and empty all over again.

int main ()
{
	Tree<int> tree;
	char selection,
		ans;
	ItemType number = 0;

	do{
	cout << "Choose from the following operations.\n" <<
			"A - Initialize\n" <<
			"B - Insert an Item\n" <<
			"C - Retrieve an Item\n" <<
			"D - Delete an Item\n" <<
			"E - Destroy Tree\n" <<
			"F - Check if Tree is Empty or Not\n" <<
			"P - Print Tree\n" <<
			"Q - Quit program\n";
	cin >> selection;

	switch(selection){
		case 'a':
		case 'A':
			initialize(tree);
			break;
		case 'b':
		case 'B':
			insertAndPrint(tree, number);
			break;
		case 'c':
		case 'C':
			retrieve(tree, number);
			break;
		case 'd':
		case 'D':
			deleteItems(tree, number);
			break;
		case 'e':
		case 'E':
			destroy(tree, number);
			break;
		case 'f':
		case 'F':
			if(tree.isEmpty()){
				cout << "\nThe tree is empty.\n\n" << endl;
			}
			else{
				cout << "\nThe tree is not empty.\n\n" << endl;
			}
			break;
		case 'p':
		case 'P':
			cout << endl;
			cout << "Current tree:\n";
			tree.print();
			cout << endl;
			break;
		case 'q':
		case 'Q':
			break;
		default:
			cout << "Not a valid selection.\n";
			break;
		}
	}while((selection != 'q') && (selection != 'Q'));

	return 0;
}

void initialize(Tree<int> & tree){
	cout << "The tree initialized:\n";
	tree.print();
}

void insertAndPrint(Tree<int> & tree, ItemType number){
	char ans;
	do{
		cout << "Enter a number to insert." << endl;
		cin  >> number;

		if(tree.insert(number))
			cout << "Successful insertion. :)\n\n";
		else
			cout << "Insertion was not successful. :(\n\n";

		cout << "Current tree:\n";
		tree.print();

		cout << "Want to insert another number?(y/n)\n";
		cin  >> ans;
	}while((ans == 'y') || (ans == 'Y'));
}

void retrieve(Tree<int> & tree, ItemType number){
	char ans;
	ItemType found = 0;
	do{
		cout << "Enter a number to retrieve (aka find)." << endl;
		cin  >> number;

		if(tree.retrieve(number, found))
			cout << "Found! :)\n\n" << endl;
		else
			cout << "Not found. :(\n\n" << endl;

		cout << "Want to retrieve another number?(y/n)\n";
		cin  >> ans;
	}while((ans == 'y') || (ans == 'Y'));
}

void deleteItems(Tree<int> & tree, ItemType number){
	char ans;
	do{
		cout << "Enter a number to delete.\n";
		cin  >> number;
		if(tree.deleteItem(number))
			cout << "Successful deletion. :)\n\n";
		else
			cout << "Deletion was not successful. :(\n\n";

		cout << "Current tree:" << endl;
		tree.print();

		cout << "Want to delete another number?(y/n)\n";
		cin  >> ans;
	}while((ans == 'y') || (ans == 'Y'));
}

void destroy(Tree<int> & tree, ItemType number){
	tree.makeEmpty();
	cout << "Tree should be destroyed by now, but let's check anyways." << endl;
	tree.print();
	cout << "Now try to delete a number that isn't in the tree." << endl;
	cin  >> number;

	if(tree.deleteItem(number))
		cout << "Successful deletion. :)\n\n";
	else
		cout << "Deletion was not successful. :(\n\n";
}