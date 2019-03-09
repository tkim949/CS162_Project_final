//
// Created by Taekyoung Kim on 2019-03-07.
//

#include "Inventory.h"
#include <iostream>

Inventory::Inventory() = default;
Inventory::~Inventory() = default;

void Inventory::addItem(std::string s){

    if(myString.size() < 3) {
        myString.push(s);
    }
    else{
        std::cout<<"Sorry, your container is full, so you don't add items anymore."<<std::endl;
    }

    std::cout << "\nThis is the items in your container: ";
   print(myString);
   std::cout<<"\nNow, you have "<<myString.size()<<" items in your container."<<std::endl;
}

void Inventory::removeItem(){

    if(!myString.empty()){
        std::cout<<"Now remove ["<<myString.top()<<"] from the container."<<std::endl;
        myString.pop();
        std::cout << "This is the items in your container after remove: ";
        print(myString);
        std::cout<<std::endl;
    }
    else{
        std::cout<<"Sorry, your container is empty, so nothing to remove."<<std::endl;
    }

}

void Inventory::print(std::stack<std::string> mySt){

    if(mySt.empty()) {
        std::cout<<"\nYour list/container is empty"<<std::endl;
    }
    else {

        while (!mySt.empty()) // continues until stack is empty
        {
            std::cout << mySt.top() << " "; //return a reference to the top most element of the stack
            mySt.pop(); // delete the top most element of the stack
        }
    }
}

int Inventory::count(){

    return int(myString.size());
}

void Inventory::hasLast(){

    int length = int(myString.size());

    for(int i=0; i<length-1; i++) {
        myString.pop();
    }

    std::cout<<"Here is the last item: "<<myString.top()<<std::endl;

}
 void Inventory::showItem() {

    std::cout<<"Here is the list: ";
    print(myString);
    std::cout<<"\nTotal number of the list/items: "<<int(myString.size());
    std::cout<<std::endl;
}

void Inventory::writeList(std::string list) {

    myString.push(list);

}