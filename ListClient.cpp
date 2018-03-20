#include <iostream>
#include "List.h"

using namespace std;

int main()
{

 List L1, L2;

 L1.insert(3,1);
 L1.insert(4,2);
 L1.remove(1);
 L2.insert(7,1);
 L2.insert(40,2);
 L1.get(1);
 L2.get(2);

cout << "List L1 is" << " " << L1.get(1) << endl;

cout << "List L2 is" << " " << L2.get(1) << endl;

 
}
