//
// Created by Taekyoung Kim on 2019-03-07.
//

#ifndef FP_INVENTORY_H
#define FP_INVENTORY_H
#include <iostream>
#include <stack>


class Inventory {


private:

    const int LIMIT = 5;
    std::stack<std::string> myString;

public:

    Inventory();
    ~Inventory();
    void addItem(std::string s);
    void removeItem();
    void print(std::stack<std::string> mySt);
    int count();
    void hasLast();
    void showItem();
    void writeList(std::string s);

};


#endif //FP_INVENTORY_H
