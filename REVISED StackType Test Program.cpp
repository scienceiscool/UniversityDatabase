//Kathy Saad
//CPSC 131 - Section 01
//Assignment 04 - Use of Stacks
//April 11, 2013

#include <iostream>
#include <fstream>
#include <string>
#include "REVISED StackType.h"

using namespace std;

//typedef int ItemType;

bool isOpen(char symbol);
bool isClosed(char symbol);
bool matches(char symbol, char openSymbol);

int main(){
	fstream in_stream;
	string fileName,
		line;
	StackType<int> stack;
	bool balanced = true;
	char openSymbol,
		 symbol,
		 ans,
		 readSymbol;
	
	do{
		cout << "Valid file names: mismatch, empty, moreOpen, and moreClosed.\n"
			 << "NOTE: End file name with .txt\n";
		cout << "Make a selection: ";
		cin  >> fileName;
	
		in_stream.open(fileName.c_str());

		in_stream.get(symbol);

		while((symbol != '\n') && (balanced)){
			if((isOpen(symbol)) && (!stack.IsFull()))
				stack.Push(symbol);
			else if(isClosed(symbol)){
				if(stack.IsEmpty())
					balanced = false;
				else{
					openSymbol = stack.Top();
					stack.Pop();
					balanced = matches(symbol, openSymbol);
				}
			}
			in_stream.get(symbol);
		}

		if(balanced)
			cout << "Expression is well formed." << endl;
		else if(!balanced){
			cout << "Expression is not well formed." << endl;
			getline(in_stream, line);
			cout << line;
		}
		else if((symbol == '\n') && (stack.IsFull())){
			in_stream.get(readSymbol);
			while(readSymbol != '\n'){
				cout << readSymbol;
				in_stream.get(readSymbol);
			}
			cout << "Error, expression is again ill formed!\n";
		}

		in_stream.close();

		cout << endl << endl;
		cout << "Would you like to try again? (y/n)" << endl;
		cin  >> ans;
	}while((ans == 'y') || (ans == 'Y'));

	return 0;
}

bool isOpen(char symbol){
	return((symbol == '(') || (symbol == '{') || (symbol == '['));
}

bool isClosed(char symbol){
	return((symbol == ')') || (symbol == '}') || (symbol == ']'));
}

bool matches(char symbol, char openSymbol){
	return(((openSymbol == '(') && (symbol == ')')) || ((openSymbol == '{') && (symbol == '}')) || ((openSymbol == '[') && (symbol == ']')));
}