#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<char> invertQueueItems(queue<char> F, stack<char> auxStack){

    while(!F.empty()){
        auxStack.push(F.front());
        F.pop();
    }

    while(!auxStack.empty()){
        F.push(auxStack.top());
        auxStack.pop();
    }

    return F;
}

int main(){
    queue<char> F;
    stack<char> auxStack;

    F.push('A');
    F.push('B');
    F.push('C');
    
    cout << F.front() << endl; // A

    F = invertQueueItems(F,auxStack);

    cout << F.front() << endl; // C

    return 0;
}