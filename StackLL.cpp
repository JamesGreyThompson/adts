#include "StackLL.h"

class Stack::Node //self-referential Node class
{
public:
	   
           int data;
           Node* link;

};

Stack::~Stack(){
	clear();
	
	}
////////
int Stack::size(){
		return  num_elements;
		}
	
///////
void Stack::push(int num){
	  Node* newPtr = new Node{num};
	  newPtr->link = frontPtr;
	  frontPtr = newPtr;	


     num_elements++;
 }
 ////
 void Stack::pop(){
	
	 Node* delPtr = frontPtr;
	 frontPtr = frontPtr->link;
	  delete delPtr;
	  num_elements--;
	 }
///////
int Stack::top(){
	return frontPtr->data;  
	}	 
	
void Stack::clear()
	{
		while(num_elements > 0)
		pop();
}



