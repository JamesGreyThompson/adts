#include "StackL.h"



int Stack::size(){
	return data.size();
	}
	
void Stack::push(int num){
	data.insert(num, 1);//num will send value to stack position and will
	                    //be passed to elements variable, however , placing " 1 "
	                    //will always put it at the front.
	                      
	}
void Stack::pop(){
data.remove(1);
	}
	
 int Stack::top(){
	   return data.get(1);
	   }

void Stack::clear(){
	   data.clear();}
