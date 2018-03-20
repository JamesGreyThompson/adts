#include "List.h"
#include <iostream>
#include <stdexcept>//used to be able to "throw" exceptions

using namespace std;


class List::Node //self-referential Node class
{
public:
	   
           int data;
           Node* link;

Node()
{
data=0;
link=nullptr;
}


Node (int new_data)
{

data =new_data;
link = nullptr;
}
Node (int new_data,Node* new_link)
 	     {
  	 	
  	 	data =new_data;
		link =new_link;
 	     }

	   //link is a data member which is a pointer 
	   //to an object of the same type (i.e. Node)
	
           //end Node class definition (can only be seen by the List class)
};
List::List()
{
                frontPtr = nullptr;
                num_elements=0;
}



List::~List()  
{
    while(num_elements > 0)
      remove(1);
}
	


int List::size()
 {
    return num_elements;
 }


void List::insert(int val, int k) 
{
	if (k < 1 or k > num_elements +1) //if the location is invalid
	     throw out_of_range("List::insert("+to_string(val)+", " +to_string(k)+") failed. (valid indices are 1 to "+to_string(num_elements+1)+")");//throw an "out_of_range" exception
	
	
	Node* newPtr = new Node{val};
	
	if(k == 1)
	{
	  newPtr->link = frontPtr;
	  frontPtr = newPtr;
	 }
	else
	 {  
	
	  Node* tmpPtr = frontPtr;
	 
	  
	  for (int loc = 1; loc != k-1;loc++) //get pointer to (k-1)th node
	     {
		tmpPtr = tmpPtr->link;
	//	loc++;
	     }
	
	  newPtr->link = tmpPtr->link;
	  tmpPtr->link = newPtr;                                
        }//end else

     num_elements++;
 }

int List::remove(int k)
{
	if (k < 1 or k > num_elements)//if the location is invalid 
	     throw out_of_range("List::remove(" +to_string(k)+") failed. (valid indices are 1 to "+to_string(num_elements)+")");//throw an "out_of_range" exception
	
	Node* delPtr;
        int del_data;
	
	if(k == 1)
	{
	  delPtr = frontPtr;
	  frontPtr = frontPtr->link;
	 }
	 else
	 {
	    Node* Kth1tmpPtr = frontPtr;
		
            
             for(int loc = 1;loc != k-1;loc++)//get pointer to (k-1)th node
	    {
	       Kth1tmpPtr = Kth1tmpPtr->link;
		//loc++;
	    }
	
	    delPtr = Kth1tmpPtr->link;
	    Kth1tmpPtr->link = delPtr->link;
	  }

	del_data = delPtr->data;
	delete delPtr;
	num_elements--;
        return del_data;
	}
	
	//Implementations of missing operations
int List::get(int k)
         {
	if ( k > num_elements or k<1)
            throw out_of_range("List::get(" +to_string(k)+") failed. (valid indices are 1 to "+to_string(num_elements+1)+")");

Node* tmpPtr = frontPtr;
	for(int i = 1; i!= k;i++)
	{
	  tmpPtr=tmpPtr->link;
	}
return tmpPtr->data;
}
	void List::clear()
	{
		while(num_elements > 0)
		remove(1);
}

	
