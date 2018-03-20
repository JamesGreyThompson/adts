#include "StackV.h"

int Stack::size(){
	return data.size();
	}

 void Stack::push(int s){
	 data.push_back(s);
	 }
	 
void Stack::pop(){
		  data.pop_back();
		  }
int Stack::top(){
	return data[data.size()-1]
	;}
void Stack::clear(){
	
	while (size() > 0)
	pop();
	
	}
