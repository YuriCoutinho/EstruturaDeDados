#include <iostream>
#include <queue>
using namespace std;

class customStack{
    private:
        int amountOfItems;
        queue<char> auxQueue1;
        queue<char> auxQueue2;
    
    public:
        void create(){
            this->amountOfItems = 0;
        }

        void release(){
            // Nothing To Release.
        }

        void push(char element){
            this->auxQueue2.empty() ? auxQueue1.push(element) : auxQueue2.push(element);
            this->amountOfItems++;
        }

        void pop(){
            if(!auxQueue1.empty()){
                while(auxQueue1.size() > 1){
                    auxQueue2.push(auxQueue1.front());
                    auxQueue1.pop();
                }
            }else{
                while(auxQueue2.size() > 1){
                    auxQueue1.push(auxQueue2.front());
                    auxQueue2.pop();
                }
            }
            this->amountOfItems--;
        }

        char top(){
            char top;
            if(!auxQueue1.empty()){
                while(!auxQueue1.empty()){

                    if(auxQueue1.size() == 1){
                        top = auxQueue1.front();
                    }

                    auxQueue2.push(auxQueue1.front());
                    auxQueue1.pop();
                }

            }else{
                while(!auxQueue2.empty()){

                    if(auxQueue2.size() == 1){
                        top = auxQueue2.front();
                    }

                    auxQueue1.push(auxQueue2.front());
                    auxQueue2.pop();
                }
            }
            return top;
        }
};


int main (){
    customStack Test;
    Test.create();
    Test.push('A');
    Test.push('B');
    Test.push('C');

    cout <<  Test.top() << endl; // C

    Test.pop();
    cout <<  Test.top() << endl; // B

    Test.pop();
    cout <<  Test.top() << endl; // A

    return 0;
}