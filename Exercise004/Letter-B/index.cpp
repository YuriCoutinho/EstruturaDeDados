#include <iostream>
#include <stack>
using namespace std;

stack<char> invertStackItems(stack<char> P, stack<char> auxStack1,stack<char> auxStack2 ){
    while(!P.empty()){
        auxStack1.push(P.top());
        P.pop();
    };

    while(!auxStack1.empty()){
        auxStack2.push(auxStack1.top());
        auxStack1.pop();
    };

    while(!auxStack2.empty()){
        P.push(auxStack2.top());
        auxStack2.pop();
    };

    return P;
};


int main(){
    stack<char> P;
    stack<char> auxStack1;
    stack<char> auxStack2;
    P.push('A');
    P.push('B');
    P.push('C');

    cout << P.top() << endl; // C

    P = invertStackItems(P, auxStack1, auxStack2);

    cout << P.top() << endl; // A

    return 0;
}