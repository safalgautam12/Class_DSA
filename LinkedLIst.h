#pragma once
class Node
{
    public: 
    int info;
    Node *next;
    Node(){}
    Node(int d): info(d), next(nullptr){}
    Node(int d ,Node *next):info(d),next(next){}

};