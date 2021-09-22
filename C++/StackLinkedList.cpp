/*
The main advantage of using linked list over an arrays is that it is possible to implements a stack that 
can shrink or grow as much as needed. 
Stack implements the LIFO (Last In First Out) mechanism.
In using array will put a restriction to the maximum capacity of the array which can lead to stack overflow.
Here each new node will be dynamically allocate. so overflow is not possible.

Stack Operations: 

push() : Insert the element into linked list nothing but which is the top node of Stack.
pop() : Return top element from the Stack and move the top pointer to the second node of linked list or Stack.
display(): Print all element of Stack.
top(): Return the top element.

*/

#include<iostream>
using namespace std;

// Functions prototypes
void push(int);
int pop();
void display();
void top();

struct node{ // Node structure that stores the data in a chained manner
	int data;
	node* link;
};

struct head{ // Head structure that stores the top node address in the stack
	int count;
	node* top;
}*hlink; // Global variable to access the head

int main(){
	hlink = new head(); // Initializing header
	hlink->count = 0;
	hlink->top = NULL;  // Null pointer since stack is empty
	int choice;
	char c = 'y';

	while (c == 'y'){ 
		cout<<"1. Push\n2. Pop\n3. Display\n4. Top\n5. Get total count\nEnter the choice : ";
		cin>>choice;

		switch(choice){
			case 1:{ // Push - adds the element at the top of the stack (stores in node)
				int data;
				cout<<"Enter element to be pushed : ";
				cin>>data;
				push(data);
				break;
			}
			
			case 2:{ // Pop - removes and returns the top element in the stack (from node)
				if(hlink->top == NULL){
					cout<<"Can't pop out, stack is empty";
				}
				else{
					cout<<"Popped out : "<<pop();
				}	
				break;
			}

			case 3:{ // Displays stack
				if(hlink->top == NULL){
					cout<<"Can't display since stack is empty";
				}
				else{
					display();
				}
				break;
			}
			
			case 4:{ // Displays the latest entry in the stack
				if(hlink->top == NULL){
					cout<<"Can't display top since stack is empty";
				}
				else{
					top();
				}
				break;
			}
			
			case 5:{ // Displays total number of elements in the stack
				cout<<"Number of elements in stack : "<<hlink->count;
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
	
void push(int ele){
	node *newnode = new node();
	if(newnode == NULL){
		cout<<"Stack Overflow";
	}
	else{
		newnode->data = ele;        // Stores the latest data at the top node
		newnode->link = hlink->top; // Stores the second top address to the first pointer 
		hlink->top = newnode;       // Stores the address of the latest node in the top
		++(hlink->count); 
	}	
}

int pop(){
	node *nodepop = hlink->top;    // Top node to be popped out
	hlink->top = hlink->top->link; // Stores the second top node address as top
	int ret = nodepop->data;       // To return the latest node value
	--(hlink->count);
	delete nodepop;
	return ret;
}

void display(){
	node *nodedis = hlink->top;
	for(;nodedis != NULL;nodedis = nodedis->link){ // Iterates till the pointer is NULL
		cout<<nodedis->data<<" ";	
	}
}

void top(){
	cout<<hlink->top->data; // Prints data in the top 
}
