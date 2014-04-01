//Kathy Saad
//CPSC 131 - Section 01
//Assignment 6 - Binary Search Tree
//April 25, 2013

//****************************************************************
//MODIFICATION: I changed the variable rootPtr to root for brevity
//****************************************************************

//typedef int ItemType;

#include <iostream>
#include "REVISED TreeNode.h"

using namespace std;

template<class ItemType>
class Tree{
public:
	Tree();
	//Preconditions: None.
	//Postconditions: Tree is initialized to empty.

	~Tree();
	//Preconditions: Tree exists.
	//Postconditions: makeEmpty is called to ensure that the tree is empty when the destructor is called.

	bool isEmpty();
	//Preconditions: None.
	//Postconditions: Tree is unchanged.

	void makeEmpty();
	//Preconditions: The tree exists.
	//Postconditions: The tree is now empty. Any dynamically allocated memory which is no longer used is returned to the system.

	bool insert(ItemType newItem);
	//Preconditions: The tree exists and has a binary search property.
	//Postconditions: If the tree already has an item where the item == newItem, the function returns false and the tree is unchanged.

	bool retrieve(ItemType searchItem, ItemType & foundItem);
	//Preconditions: The tree exists and has a binary search property.
	//Postconditions: If the tree already has an item where the item == searchItem, foundItem is set to that item, and the function returns true.
		//If the tree has no such item, the function returns false, and foundItem remains unchanged. The tree is unchanged.

	bool deleteItem(ItemType deleteItem);
	//Preconditions: The tree exists and has a binary search property.
	//Postconditions: If the tree has an item where item == deleteItem, that item is removed from the tree, and the function returns true,
		//and the binary search property is maintained. If the tree has no such item, the function returns false and the tree remains unchanged.

	void print();
	//Preconditions: The tree exists and has a binary search property.
	//Postconditions: The items have been printed in ascending order, and the tree is unchanged.
	
private:
	TreeNode<ItemType> * root;

	void printHelper(TreeNode<ItemType> *);
	bool insertHelper(TreeNode<ItemType> * &, ItemType);
	bool deleteHelper(TreeNode<ItemType> * &, ItemType);
	void deleteNode(TreeNode<ItemType> * &);
	bool retrieveHelper(ItemType, TreeNode<ItemType> * &, ItemType &);
	void makeEmptyHelper(TreeNode<ItemType> * &);
};

//******************************
//FUNCTION IMPLEMENTATIONS BELOW:
//******************************

template<class ItemType>
Tree<ItemType>::Tree(){
	root = NULL;
}

template<class ItemType>
Tree<ItemType>::~Tree(){
	makeEmpty();
}

template<class ItemType>
bool Tree<ItemType>::isEmpty(){
	return(root == NULL);
}

template<class ItemType>
bool Tree<ItemType>::insert(ItemType newItem){
	return insertHelper(root, newItem);
}

template<class ItemType>
bool Tree<ItemType>::insertHelper(TreeNode<ItemType> * & root, ItemType newItem){
	if(root == NULL){
		root = new TreeNode<ItemType>;
		root->right = NULL;
		root->left = NULL;
		root->data = newItem;
		return true;
	}
	else if(newItem < root->data){
		insertHelper(root->left, newItem);
		return true;
	}
	else{
		insertHelper(root->right, newItem);
		return true;
	}
}

template<class ItemType>
void Tree<ItemType>::makeEmpty(){
	if(root != NULL){	
		makeEmptyHelper(root);
		root = NULL;
	}
}

template<class ItemType>
void Tree<ItemType>::makeEmptyHelper(TreeNode<ItemType> * & root){
	if(root != NULL){
		makeEmptyHelper(root->left);
		makeEmptyHelper(root->right);
		delete root;
	}
}

template<class ItemType>
bool Tree<ItemType>::retrieve(ItemType searchItem, ItemType & foundItem){
	return retrieveHelper(searchItem, root, foundItem);
}

template<class ItemType>
bool Tree<ItemType>::retrieveHelper(ItemType searchItem, TreeNode<ItemType> * & root, ItemType & foundItem){
	if(root == NULL){
		return false;
	}
	else if(root->data == searchItem){
		foundItem = root->data;
		return true;
	}
	else if(searchItem < root->data){
		return retrieveHelper(searchItem, root->left, foundItem);
	}
	else if(searchItem > root->data){
		return retrieveHelper(searchItem, root->right, foundItem);
	}
}

template<class ItemType>
bool Tree<ItemType>::deleteItem(ItemType deleteItem){
	return deleteHelper(root, deleteItem);
}

template<class ItemType>
bool Tree<ItemType>::deleteHelper(TreeNode<ItemType> * & root, ItemType deleteItem){
	if(root == NULL){
		return false;
	}
	else if (root->data == deleteItem){
		 deleteNode(root);
		 return true;
	}
	else if (root->data > deleteItem){
		return deleteHelper(root->left, deleteItem);
	}
	else{
		return deleteHelper(root->right, deleteItem);
	}
}

template<class ItemType>
void Tree<ItemType>::deleteNode(TreeNode<ItemType> * & root){
	if(root->left == NULL){
		TreeNode<ItemType> * deletePtr;
		deletePtr = root;
		root = root->right;
		delete deletePtr;
	}
	else if(root->right == NULL){
		TreeNode<ItemType> * deletePtr;
		deletePtr = root;
		root = root->left;
		delete deletePtr;
	}
	else if(root->left->right == NULL){
		root->data = root->left->data;
		TreeNode<ItemType> * deletePtr;
		deletePtr = root->left;
		root->left = root->left->left;
		delete deletePtr;
	}
	else{
		TreeNode<ItemType> * current;
		current = root->left;
		while (current->right->right != NULL){
			current = current->right;
		}
		root->data = current->right->data;
		TreeNode<ItemType> * deletePtr;
		deletePtr = current->right;
		current->right = current->right->left;
		delete deletePtr;
	}
}

template<class ItemType>
void Tree<ItemType>::print(){
	if (root == NULL){
		cout << endl << "**The tree is empty!**" << endl << endl;
	}
	else{
	printHelper(root);
	}
}

template<class ItemType>
void Tree<ItemType>::printHelper(TreeNode<ItemType> * root){
	if(root != NULL){
		printHelper(root->left);
		cout << root->data << endl;
		printHelper(root->right);
	}
}