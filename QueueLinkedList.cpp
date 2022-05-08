/*
Queue is a linear structure which follows a particular order in which the operations are performed.
The order is First In First Out (FIFO). 

Operations on Queue: 
Mainly the following four basic operations are performed on queue:
Enqueue: Adds an item to the queue. If the queue is full, then it is said to be an Overflow condition. 
Dequeue: Removes an item from the queue. The items are popped in the same order in which they are pushed. If the queue is empty, then it is said to be an Underflow condition. 
Front: Get the front item from queue. 
Rear: Get the last item from queue. 
*/

#include<iostream>    // Header files
using namespace std;

struct node{          // Node structure which stores data and link to the next node in the queue
	int data;
	node* link;
};

struct head{		  // Head structure which stores the count, first and last node addresses
	int count;
	node* front;
	node* rear;
}*qhead;

void initialize(){    // Initializes head structure to NULL
	qhead = new head();
	qhead->count = 0;
	qhead->front = NULL;
	qhead->rear = NULL; 
}

void enqueue(){       // Appends the element in the queue (Adds element in the last of the queue)
	node *newnode = new node();
	if(newnode == NULL){   // Checks for overflow condition
		cout<<"Overflow!";
	}
	else{                  // Appends the element
		int dataInput;
		cout<<"Enter the integer to be added to the queue : ";
		cin>>dataInput;
		newnode->data = dataInput;  // Stores the data in the node 
		newnode->link = NULL;       // link is set to NULL because it is appended in the last
		if(qhead->front == NULL){
			qhead->front = newnode;
		}
		else{
			qhead->rear->link = newnode;  // Address of the last node is set to the second last node's link	  
		}
		qhead->rear = newnode;      // Node is appended at the end of the queue
		cout<<"Element added successfully";
		qhead->count += 1;
	}
}

void dequeue(){		  // Remove the front element (which was enqueued least recently)
	if(qhead->front == NULL){ // Checks for underflow
		cout<<"No element present in the queue!";
	}
	else{ 
		node *temp = new node();
		temp = qhead->front;  // Temporary node to store the front node
		qhead->front = temp->link; // The second element in the queue is set as front
		cout<<"Element removed from queue was : "<<temp->data;
		qhead->count -= 1;
		delete temp;        // Front element is deleted (FIFO)
	}
}

void viewQueue(){     // To view all the elements in the queue
	node *queue = new node();
	queue = qhead->front; // Front is the first node in the queue
	int i = 0;
	if(qhead->front == NULL){
		cout<<"No element present in the queue!";
	}
	else{
		while(true){
			if(queue->link == NULL){ // Condition that terminates the loop
				cout<<++i<<". "<<queue->data<<endl;
				break;
			}
			cout<<++i<<". "<<queue->data<<endl;
			queue = queue->link; // next node is set as current node
		}
	}
}

void showFront(){     // Prints the first element in the queue 
	if(qhead->front == NULL){
		cout<<"No element present in the queue!";
	}
	else{
		cout<<"Front element : "<<qhead->front->data;
	}
}

void showRear(){      // Prints the last element in the queue
	if(qhead->front == NULL){
		cout<<"No element present in the queue!";
	}
	else{
		cout<<"Rear element : "<<qhead->rear->data;
	}
}

void getCount(){      // Prints the total number of elements in the queue
	cout<<"Total elements in the queue : "<<qhead->count;
}

int main(){
	initialize();
	int choice=0;
	cout<<"1.Enqueue\n2.Dequeue\n3.View Queue\n4.Front\n5.Rear\n6.Get Count\n7.Exit";
	while(choice != -1){
		cout<<"\n\nEnter the choice : ";
		cin>>choice;
		switch(choice){
			case 1:{
				cout<<endl;
				enqueue();
				break;
			}
			case 2:{
				cout<<endl;
				dequeue();
				break;
			}
			case 3:{
				cout<<endl;
				viewQueue();
				break;
			}
			case 4:{
				cout<<endl;
				showFront();
				break;
			}
			case 5:{
				cout<<endl;
				showRear();
				break;
			}
			case 6:{
				cout<<endl;
				getCount();
				break;
			}
			case 7:{
				cout<<endl;
				choice = -1;
				break;
			}
			default:{
				cout<<endl;
				cout<<"Enter a valid option !\n";
				break;
			}
		}
	}
}
