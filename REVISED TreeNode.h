//Kathy Saad
//CPSC 131 - Section 01
//Assignment 6 - Binary Search Tree
//April 25, 2013

//****************************************************************************************
//MODIFICATION: I changed the variables leftPtr and rightPtr to left and right for brevity
//****************************************************************************************

//typedef int ItemType;

#pragma once

template<class ItemType> class Tree;

template<class ItemType>
class TreeNode{
	friend class Tree<ItemType>;

public:
	TreeNode(ItemType);
	TreeNode();
	ItemType getData() const;
private:
	ItemType data;
	TreeNode<ItemType> * left; //left pointer
	TreeNode<ItemType> * right; //right pointer
};

//******************************
//FUNCTION IMPLEMENTATIONS BELOW:
//******************************

template<class ItemType>
TreeNode<ItemType>::TreeNode(ItemType newItem){
	data = newItem;
	left = NULL;
	right = NULL;
}

template<class ItemType>
TreeNode<ItemType>::TreeNode(){
	left = NULL;
	right = NULL;
}

template<class ItemType>
ItemType TreeNode<ItemType>::getData() const{
	return data;
}