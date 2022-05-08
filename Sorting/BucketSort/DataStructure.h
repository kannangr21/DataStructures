#include<iostream>

using namespace std;

template<typename T>
struct Node{
    T data;
    Node *next;
};

template<typename T>
class SList{
    private:
        Node<T> *a;
        int size;
    public:
        SList();
        bool insertFront(T);
        bool elementAt(int p, T&);
        int getSize(){return size;}
        void sort();
};

template<typename T>
SList<T>::SList(){
    a = NULL;
    size = 0;
}

template<typename T>
bool SList<T>::insertFront(T x){
    Node<T> *n;
    n = new Node<T>;

    if (n == NULL){
        return false;
    }
    n->data = x;
    n->next = NULL;
    n->next = a;
    a = n;
    size++;
    return true;
}

template<typename T>
bool SList<T>::elementAt(int p, T &x){
	Node<T> *t = a;
	int c=1;
	while(t != NULL){
		if(c == p){
			x = t->data;
			return true;
		}
		t = t->next;
		c++;
	}
	return false;
}

template<typename T>
void SList<T>::sort(){
	Node<T> *i,*j;
	double t;
	i = a;
	for(i = a; i != NULL; i = i->next){
		for(j = i->next; j != NULL; j = j->next){
			if(j->data < i->data){
				t = i->data;
				i->data = j->data;
				j->data = t;
			}
		}
	}
}