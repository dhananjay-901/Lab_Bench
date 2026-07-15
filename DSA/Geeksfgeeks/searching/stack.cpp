#include <iostream>
using namespace std;

class stack{
    public:
    int arr[5];
    int top = -1;

    void push(int x){
        if(top==4){
            cout << "stack overflow";
        }
        arr[++top] = x;
    }

    void pop(){
        if(top == -1){
            cout << "stack underflow";
        }
        top--;
    }

    void display(){
        for (int i = top; i >=0;i--){
            cout << arr[i] <<" ";
        }
        cout << endl;
    }
};

int main(){
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "stack elements: ";
    s.display();

    s.pop();

    cout << "After pop: ";
    s.display();
    return 0;
}