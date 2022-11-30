#include <iostream>
#include <stack>
#include<queue>
using namespace std;

stack<char> invertStackItems(stack<char> Stack, queue<char>auxQueue){
    while(!Stack.empty()){
        auxQueue.push(Stack.top());
        Stack.pop();
    }

    while(!auxQueue.empty()){
        Stack.push(auxQueue.front());
        auxQueue.pop();
    }

    return Stack;
}

int main(){
    stack<char> P;
    P.push('A');
    P.push('B');
    P.push('C');

    cout << P.top() << endl; // C

    queue<char> Queue; 

    P = invertStackItems(P, Queue);

    cout << P.top() << endl; // A

    return 0;
}