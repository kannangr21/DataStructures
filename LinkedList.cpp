/*
LINKED LIST:
------------
A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. 
The elements in a linked list are linked using pointers.

In simple words, 
a linked list consists of nodes which contains a data field and a reference(link) to the next node in the list.

For demonstrating Linked list, Singly Linked List has been used in the below program.
*/

// Header files

#include<iostream>
using namespace std;

// Structure definition

struct node{
	char data;
	node* link;
}; // Node structure

struct head{
	int count;
	node* top;
}*hlink; // Head Structure

// Function prototypes

void createList();    // 1. Initializes list
void insertData();    // 2. Inserts node at the beginning, end, middle
void deleteData();    // 3. Deletes the first found given data
void searchData();    // 4. Searches for the data given
bool isEmpty();       // 5. Check if the list is empty
bool isFull();        // 6. Check if the list is full
void countList();     // 7. Gives the number of elements in the list
void traverseList();  // 8. Displays all the data in the list
void destroyList();   // 9. Destroys the list

// Main

int main(){  
	createList();
	int choice;
	char ch;
	cout<<"1. Insert\n2. Delete\n3. Search\n4. Check Empty\n";
	cout<<"5. Check Full\n6. Count\n7. Display\n8. Destroy\n";
	do{ 
		cout<<"Enter a choice : ";
		cin>>choice;
		switch(choice){ 
			case 1:{ // Insertion
				insertData();
				break;
			} // case 1 
			case 2:{ // Deletion
				deleteData();
				break;
			} // case 2
			case 3:{ // Searching
				searchData();
				break;
			} // case 3
			case 4:{ // If Empty
				bool flag = isEmpty();
				if(flag)
				cout<<"The list is empty.\n";
				else
				cout<<"List has content.\n";
				break;
			} // case 4
			case 5:{ // If Full
				bool flag = isFull();
				if(flag)
				cout<<"The list is full.\n";
				else
				cout<<"The list is not full.\n";
				break;
			} // case 5
			case 6:{ // Gets count
				countList();
				break;
			} // case 6
			case 7:{ // Displays the list
				traverseList();
				break;
			} // case 7
			case 8:{ // Destroys the list
				destroyList();
				cout<<"List Deleted!\n";
				break;
			} // case 8
			default:{
				cout<<"Select an option given in the list (1-8)\n";
				break;
			} // default
		} // switch
	cout<<"Do you want to continue (y) : ";
	cin>>ch;
	}while(ch == 'y'); // do while
} // main

// Function definitions

void createList(){ // Initializes head node
	hlink = new head(); 
	hlink->count = 0;
	hlink->top = NULL;
}

void insertData(){ //Data insertion in the list
	cout<<"1. Insert at the beginning\n2. Insert at the end\n3. Insert somewhere in the middle\n";
	cout<<"Enter the choice : ";
	int choice;
	cin>>choice;
	node* newnode = new node();
	if(choice == 1){ // Insertion in the beginning
		cout<<"Enter the character : ";
		char data;
		cin>>data;
		newnode->data = data;       // Inserts data in the node
		newnode->link = hlink->top; // Sets previous top node to link of new node 
		hlink->top = newnode;       // Sets new node to the top (node inserted in the beginning)
		hlink->count += 1;
	}
	else if(choice == 2){ // Insertion in the end
		node* temp = hlink->top;
		if(isEmpty()){ // If list is empty
			cout<<"Enter the character : ";
			char data;
			cin>>data;
			newnode->data = data;  // Inserts data in the node
			newnode->link = NULL;  // Sets link of the node to NULL
			hlink->top = newnode;  // Sets new node as top, since list is empty
			hlink->count += 1;
		} 
		else{ // If list is not empty
			for(;temp->link != NULL;){ // Iterates till last node
				temp = temp->link;
			}
			temp->link = newnode;  // Sets last node link to new node, So new node will be the last node now
 			newnode->link = NULL;  // Sets new node link to NULL since new node will be in the end
			cout<<"Enter the character : ";
			char data;
			cin>>data;
			newnode->data = data; // Inserts data in the node
			hlink->count += 1;
		} 
	} 
	else if(choice == 3){ // Insertion in the middle 
		int index, i = 0;
		cout<<"Enter the index to be inserted (from 0): ";
		cin>>index;
		if(index == 0){ // Inserts the node in the beginning
			cout<<"Enter the character : ";
			char data;
			cin>>data;
			newnode->data = data;       // Inserts data in the node
			newnode->link = hlink->top; // Assigns the top node to new node link
			hlink->top = newnode;       // Sets new node as the top link
			hlink->count += 1;
		} 
		else{ // If the index is not 0
			node* temp1 = hlink->top;
			node* temp2 = NULL;
			if(!isEmpty()){ // If index > 0 and list is not empty
				while(temp1 != NULL){ // Iteration through the nodes 	
					if(i == index){ // If index node is found
						cout<<"Enter the character : ";
						char data;
						cin>>data;
						newnode->data = data;  // Inserts data in the node
						newnode->link = temp1; // Sets current node to new node link
						temp2->link = newnode; // Sets new node to previous node link
						/* This inserts new node between current node and previous node */
						hlink->count += 1;
						break;
					} 
					temp2 = temp1;        // temp2 => will point current node as previous node in the next iteration
					temp1 = temp1->link;  // temp1 points next node
					++i;			  
				} 
				if(i < index){ // Index > list length
					cout<<"Can't insert in the provided index.\n";
				} 
			} 
			else{ // If list is empty and index > 0
				cout<<"Can't insert in the provided index.\n";
			} 
		} 
	} 
} 

void deleteData(){  // Deletes a particular Node
	cout<<"This deletes the first element found!\n";
	bool flag = true;
	node* temp = hlink->top;
	node* temp2 = new node();
	if(isEmpty()){ // If list is empty
		cout<<"List is empty!\n";
	} // If empty
	else{ // If list is not empty
		char data;
		cout<<"Enter the data to be deleted : ";
		cin>>data;
		int i = 0;
		for(;temp != NULL;){ // Iterates through all the nodes
			if(temp->data == data){ // If data is found
				temp2->link = temp->link; // Sets current node link (next node) to previous node link
				/* This removes the current node from chain */
				if(i == 0){ // If data is in the top;
					hlink->top = temp->link; // Sets current node link (next node) to top if data is in the top
				} 
				delete temp;
				cout<<"Element deleted!\n";
				hlink->count -= 1;
				flag = false;
				break;
			}
			temp2 = temp;      // temp2 => will point current node as previous node in the next iteration
			temp = temp->link; // temp points to next node
			i++;
		} 
		if(flag){ // If element not found
			cout<<"Element not found!\n";
		} 
	} 
} 

void searchData(){  // Searches for the data
	if (isEmpty()){ // Looks for empty list
		cout<<"List is empty!\n";
	} 
	else{  // If list is not empty
		node* temp = hlink->top;
		char data;
		bool flag = true;
		int i = 0; 
		cout<<"Enter the data to be searched : ";
		cin>>data;
		for(;temp != NULL;){  // Iterates till last node
			if(temp->data == data){ // If the data is found
				cout<<"Element found in the node : "<<i<<endl;
				flag = false;
				break;
			}
			i++;
			temp = temp->link; // temp points next node
		}
		if(flag){ // If not found
			cout<<"Element not found!\n";
		}
	}
}

bool isEmpty(){ // Checks if the list is empty
	if(hlink->top == NULL)
	return true;
	else
	return false;
}

bool isFull(){ // Checks if the lsit is full
	node* newnode = new node();
	if(newnode == NULL)
	return true;
	else 
	return false;
} 

void countList(){ // Returns the number of elements in the list
	cout<<"Number of elements in the list : "<<hlink->count<<endl;
}

void traverseList(){  // To display all the elementsn the list
 	node* temp = hlink->top;
	if(isEmpty()){ // Checks for empty list
		cout<<"Empty List\n";
	}
	else{  // If the list is not empty
		cout<<"---THE LIST---\n";
		for(;temp != NULL;){    // Loop to iterate through all the nodes
			cout<<" "<<temp->data<<" "<<endl;
			temp = temp->link;	// temp points to next node
		} 
	} 
}

void destroyList(){  // To destroy the list
	node* temp = hlink->top;
	for(;hlink->top != NULL;){   // Deletes all the nodes
		temp = hlink->top;
		hlink->top = temp->link; // Sets next node as top node
		delete temp;             // Deletes the current node
		hlink->count -= 1;
	}
}

