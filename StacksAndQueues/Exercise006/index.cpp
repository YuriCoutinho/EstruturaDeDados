#include <iostream>
#include <stack>
using namespace std;

class customStack{
    private:
    stack<int> auxStack;
    int min;
    
    public:
    void push(int element){
        if(element < min || auxStack.empty()){
            this->min = element;
        }
        this->auxStack.push(element);
    }

    void pop(){
        this->auxStack.pop();
    }

    int top(){
        return this->auxStack.top();
    }

    int getMin(){
        return this->min;
    }
};

int main(){
    customStack Test;
    Test.push(5);
    Test.push(1);
    Test.push(20);

    cout << Test.getMin() << endl; // 1
    return 0;
}