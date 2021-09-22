/*
A stack is an abstract data structure that contains a collection of elements. 
Stack implements the LIFO (Last In First Out) mechanism 
i.e. the element that is pushed at the end is popped out first. 

Some of the principle operations in the stack are -

i)   Push - This adds a data value to the top of the stack.
ii)  Pop - This removes the data value on top of the stack
iii) Top - This returns the top data value of the stack

A program that implements a stack using array is given as follows.
*/

#include<iostream>
using namespace std;

// Function prototypes
char push(char* stack, int& top);
char pop(char* stack, int& top);
void display(char* stack, int top);

int main(){

	int top = -1; // Initially top index is set to -1 to check underflow   
	int count;    // Maximum number of elements in the stack
	cout<<"Enter the maximum number of elements in the stack : ";
	cin>>count;
	char stack[count]; // Array (stack) initialization
	int choice;
	char c = 'y';

	while (c == 'y'){ // Loop to perform stack operations
		cout<<"1. Push\n2. Pop\n3. Display\n4. Top\nEnter the choice : ";
		cin>>choice;

		switch(choice){
			case 1:{  // Push - adds the element at the top of the stack
				if(top>=count-1){	// Maximum elements are filled in the stack
					cout<<"\nStack Overflow";
				}
				else{
					cout<<push(stack, top)<<" added to "<<top + 1;
				}
				break;
			}

			case 2:{  // Pop - removes and returns the top element in the stack
				if(top != -1){
					cout<<"Popped element : "<<pop(stack, top);
				}
				else{ // No elements in the stack to pop (remove)
					cout<<"Stack underflow to pop";
				}
				break;
			}

			case 3:{
				if(top == -1){ // Checks data in stack
					cout<<"Stack is empty!";
				}
				else{			 // Displays stack
					display(stack, top);
				}
				break;
			}

			case 4:{ // Display the top index in the stack (Last updated data)
				if(top == -1)
				cout<<"No elements in the stack";
				else
				cout<<"Top : "<<top;
				break;
			}

			default:{
				cout<<"Enter the right option!";
				break;
			}
		}
		cout<<"\nDo you want to continue? (y/n) : ";
		cin>>c;
	}
}

char push(char* stack, int& top){
	top++;  // Increments the index value in the stack (initially -1 to 0)
	char element;
	cout<<"\nEnter the element to be added : ";
	cin>>element;
	stack[top] = element; // Stores the data in the top index
	return element;
}

char pop(char* stack, int& top){
	char ret = stack[top];
	top -= 1; // Reduces index by 1 to pop out the last element (latest insertion)
	return ret;
}

void display(char* stack, int top){
	cout<<"Index "<<"\t\telement"<<endl;
	for(top;top>=0;top--)
	cout<<top<<"\t-\t"<<stack[top]<<endl;
}
