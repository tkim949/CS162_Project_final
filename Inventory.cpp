/****************************************************************************************************
 * * Program name: CS162 Final Project
 * * Author: Taekyoung Kim
 * * Date: 03/03/2019
 * * Description: This is Inventory.cpp file for CS162 Final Project
 * * This project implements text-based game.
 * * A user(you) need to find a USB that has financial info of his deceased father.
 * * There are total 7 rooms in the house and 5 of them might have the USB.
 * * And each room has three places that the USB might be.
 * * Also, there is an obstacles, his/her step mother and brother.
 * * If the user ran into them, he might lose his strength or jewelry.
 * * User has a container and its capacity is 3, but he/she needs to keep the PASSWORD for the usb,
 * * actual capacity would be 2. Users can find jewelry in the house and keep and use it.
 * * Users can search for a room one at a time, and he has 15 turns to change rooms.
 * * The last two rooms of 7 are the places for user to rest and get a chance to have something good.
 ******************************************************************************************************/


#include "Inventory.h"
#include <iostream>

//constructor
Inventory::Inventory() = default;
//destructor
Inventory::~Inventory() = default;

/********************************************************************************************
 * * This addItem function adds user's item in the container whose limitation is 3.
 * * The first item is the PASSWORD and it comes out lastly.
 * * @param
 *******************************************************************************************/

void Inventory::addItem(std::string s){

    if(myString.size() < LIMIT) {
        myString.push(s);
    }
    else{
        std::cout<<"Sorry, your container is full, so you don't add items anymore."<<std::endl;
    }

    std::cout << "\nThis is the items in your container: ";
   print(myString);
   std::cout<<"\nNow, you have "<<myString.size()<<" items in your container."<<std::endl;
}

/**************************************************************************************
 * * This removeItem() function removes item from the container, which is the last in.
 **************************************************************************************/

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

/*************************************************************************************
 * * This print() function shows which items are in the container
 * * @param mySt
 *************************************************************************************/

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
/**************************************************************************************
 * * This count() function shows the container size, how many items in it.
 * * @return
 ***************************************************************************************/

int Inventory::count(){

    return int(myString.size());
}

/********************************************************************************
 * * This hasLast() function shows the last item, which is PASSWORD in this game.
 *********************************************************************************/

void Inventory::hasLast(){

    int length = int(myString.size());

    for(int i=0; i<length-1; i++) {
        myString.pop();
    }

    std::cout<<"Here is the last item: "<<myString.top()<<std::endl;

}

/**********************************************************************************************
 * * This showItem() function calls the print function and shows the items in the container.
 ***********************************************************************************************/

 void Inventory::showItem() {

    std::cout<<"Here is the list: ";
    print(myString);
    std::cout<<"\nTotal number of the list/items: "<<int(myString.size());
    std::cout<<std::endl;
}

/*********************************************************************************************
 * * This writeList function adds items in the container without limit after getting string.
 * * This function is for the user's path.
 * * @param list
 **********************************************************************************************/

void Inventory::writeList(std::string list) {

    myString.push(list);

}

/***************************************************************************
 * * This clear() function empty the container.
 **************************************************************************/

void Inventory::clear(){

        while (!myString.empty()) // continues until stack is empty
        {
            myString.pop(); // delete the top most element of the stack
        }

}