#include <iostream>
using namespace std;

class Deque{
    private:
    int amountOfItems;
    int beginning;
    int end;
    char auxList[1000];

    public:
    void create(){
        this->amountOfItems = 0;
        this->beginning = 0;
        this->end = 0;
    }

    void release(){
        // Nothing To Release
    }

    void insertEnd(char element){
        this->auxList[this->end] = element;
        this->end =(this->end+1)%100;
        this->amountOfItems++;
    }

    void insertBeginning(char element){
        this->auxList[this->beginning] = element;
        this->beginning =(this->beginning-1)%100;
        this->amountOfItems++;
    }

    void removeEnd(){
        this->end--;
        this->amountOfItems--;;
    }

    void removeBeginning(){
        this->beginning++;
        this->amountOfItems--;
    }

    char findEnd(){
        return this->auxList[this->end];
    }

    char findBeginning(){
        return this->auxList[this->beginning];
    }
};

int main(){
    return 0;
}
