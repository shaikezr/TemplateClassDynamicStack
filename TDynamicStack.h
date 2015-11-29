#ifndef TDYNAMICSTACK_H
#define TDYNAMICSTACK_H

#include <iostream>
#include <string>
using namespace std;

template <class T>
class TDynamicStack{
  private:
      struct Node {
          T value;
          Node *next;
      };
      Node *head; // head pointer
      Node *top;

  public:
     TDynamicStack(){head = NULL; top = NULL;} // constructor
     ~TDynamicStack(); //destructor
    bool isEmpty(void);
    void peek(void);
    void push(T val);
    T pop(T &val);

};

template <class T>
TDynamicStack<T> :: ~TDynamicStack()
{
	   Node *nodePtr, *nextNode;
	   nodePtr = head;
	   while (nodePtr != NULL)
	   {
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		}
}

template <class T>
void TDynamicStack<T> :: push(T val){
	Node *newNode, *nodePtr;
	newNode = new Node;
	newNode->value = val;
	newNode->next = NULL;
	if (!head){
		head = newNode;
		top = newNode;
	}
	else
	{
		nodePtr = head;
		while (nodePtr -> next){
			nodePtr = nodePtr -> next;
		}
		nodePtr -> next = newNode;
		top = newNode;
	}
}

template <class T>
T TDynamicStack<T> :: pop(T &val){
	Node *preNode, *curNode;
	curNode = head;
	while (head != NULL){
		if (curNode->next != NULL){
			preNode = curNode;
			curNode = curNode->next;
		}
		else{
			preNode->next = NULL;
			if (curNode != NULL){ 
				val=curNode->value;
          		delete curNode;
          	}
			top = preNode;
			return val;
		}
	}
	return 0;
}


template <class T>
bool TDynamicStack<T> :: isEmpty(void)
{
	if (head){
		return false;
	}
	else{
		return true;
	}
}

template <class T>
void TDynamicStack<T> :: peek(void)
{
	cout<<top->value<<endl;

}

#endif
