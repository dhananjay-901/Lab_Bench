/*a NULL pointer in c++ represents a pointer that dose not refer to any valid memory address
- it indicates that the pointer is intentionally set to point to nothing and holds the valye NULL or nullptr in c++11 and later
- it is commonly used during variable declaraton to show that a pointer is not yet associated with any memory and it is also returned by many built in functions to  indicate a failure condition
- attemptnig to dereference a null pointer results in undefined behavior and may cause the program to crash*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int *ptr = nullptr;
    if(ptr == nullptr){
        cout << "pointer is currently null" <<endl;
    }else{
        cout << "pointer is not null" << endl;
    }

    int value = 5;
    ptr = &value;

    if(ptr ==nullptr){
        cout << "pointer is currently null" << endl;
    }else{
        cout << "pointer is not null" << endl;
        cout << "value at the memory location pointed to by the pointer" << *ptr << endl;
    }
    return 0;
} 

/*applications of null pointer in c++
null pointers serve several important purposes in c++ from safe initialization of pointers to error handling and resource management.
- initialization - it is a good practice to initiliaze pointers to null vaue as it helps avoid undefined behavior by explicitly indicating they are not pointing to a valid memory locations.
- default values - null pointers acts a default or initial values for pointers when no valid address is assignde to the pointers
- error handling - they are useful in error conditions or to signify the absence of data that enables better handling of exceptional cases.
- resource release - to releease the resources, like the destructor of a class, or to set pointers to NULL after deletion we can use a null pointer to avoid accidently using or accessing the released memory
- sentinel values - a null pointer can be used to indicate the end of a data structure or a list like in the linked list last node has a null pointer as the next field.

isses with null
null pointer makse it possible to check for pointer error but it also has its limitations
- dereferencing a null pointer causes undefined behavior that may lead to runtime errors like segmentation faults.
- we need to check explicitly for NULL pointers before dereferencing it to avoid undefined behavior.
*/