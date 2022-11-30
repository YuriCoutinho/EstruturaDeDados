#include <iostream>
#include <queue>
using namespace std;

queue<char> invertQueueItems(queue<char> F, queue<char> auxQueue1,queue<char> auxQueue2){
    int size = F.size();

    while(F.size() > 1){
        auxQueue1.push(F.front());
        F.pop();
    }

    while(F.size() != size){
        if(!auxQueue1.empty()){
            while(auxQueue1.size() > 1){
                auxQueue2.push(auxQueue1.front());
                auxQueue1.pop();
            }

            F.push(auxQueue1.front());
            auxQueue1.pop();
        }else{
            while(auxQueue2.size() > 1){
                auxQueue1.push(auxQueue2.front());
                auxQueue2.pop();
            }

            F.push(auxQueue2.front());
            auxQueue2.pop();
        }
    }

    return F;
}


int main(){
    queue<char> F;
    queue<char> auxQueue1;
    queue<char> auxQueue2;

    F.push('A');
    F.push('B');
    F.push('C');

    cout << F.front() << endl; // A

    F = invertQueueItems(F, auxQueue1, auxQueue2);

    cout << F.front() << endl; // C
    return 0;
}