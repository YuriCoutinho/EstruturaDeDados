#include <iostream>
#include <stack>
using namespace std;

class customQueue{
    private:
    int amountOfItems;
    stack<char> auxStack1;
    stack<char> auxStack2;
    
    public:
        void create(){
            this->amountOfItems = 0;
        }

        void release(){
            // Nothing To Release.
        }

        void push(char element){
            auxStack2.empty() ? auxStack1.push(element) : auxStack2.push(element);
            this->amountOfItems++;
        }

        void pop(){
            if (!auxStack1.empty()){
                while (auxStack1.size() > 1){
                    auxStack2.push(auxStack1.top());
                    auxStack1.pop();
                }
                auxStack1.pop();

                while (!auxStack2.empty()){
                    auxStack1.push(auxStack2.top());
                    auxStack2.pop();
                }
                
            }else{
                while (auxStack2.size() > 1){
                    auxStack1.push(auxStack2.top());
                    auxStack2.pop();
                }
                auxStack2.pop();

                while (!auxStack1.empty()){
                    auxStack2.push(auxStack1.top());
                    auxStack1.pop();
                }
            }
            this->amountOfItems--;
        }

        char front(){
            char top;
            if(!auxStack1.empty()){
                while(!auxStack1.empty()){
                    if(auxStack1.size() == 1){
                        top = auxStack1.top();
                    }
                    auxStack2.push(auxStack1.top());
                    auxStack1.pop();
                }

                while(!auxStack2.empty()){
                    auxStack1.push(auxStack2.top());
                    auxStack2.pop();
                }
            }else{
                while(!auxStack2.empty()){
                    if(auxStack2.size() == 1){
                        top = auxStack2.top();
                    }
                    auxStack1.push(auxStack2.top());
                    auxStack2.pop();
                }

                while(!auxStack1.empty()){
                    auxStack2.push(auxStack1.top());
                    auxStack1.pop();
                }
            }
            
            return top;
        }
};

int main(){
    customQueue Test;
    Test.push('A');
    Test.push('B');
    Test.push('C');

    cout << Test.front() << endl; // A

    Test.pop();
    cout << Test.front() << endl; // B

    Test.pop();
    cout << Test.front() << endl; // C
    return 0;
}