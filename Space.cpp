//
// Created by Taekyoung Kim on 2019-03-05.
//

#include "Space.h"

Space::Space() = default;
Space::~Space() = default;

Space *Space::getTop(){
    return this->top;

}
Space *Space::getBottom(){
    return this->bottom;

}
Space *Space::getRight(){
   return this->right;
}
Space *Space::getLeft(){
   return this->left;
}
std::string Space::getName() const{
   return this->sName;
}
void Space::setTop(Space *ptr){
    top = ptr;

}
void Space::setBottom(Space *ptr){
    bottom = ptr;
}
void Space::setRight(Space *ptr){
    right = ptr;
}
void Space::setLeft(Space *ptr){
    left = ptr;
}
void Space::setName(std::string na){
    sName = na;
}