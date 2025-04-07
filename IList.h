#pragma once
#include<iostream>
using namespace std;
class IList {
public:
    virtual void addAtStart(int value) = 0;
    virtual void addAtEnd(int value) = 0;
    virtual void addAtIndex(int index, int value) = 0;
    virtual void removeAtStart() = 0;
    virtual void removeAtEnd() = 0;
    virtual void removeAtIndex(int index) = 0;
    virtual bool search(int value) = 0;
    virtual int getSize() = 0;
    virtual void display() = 0;
    virtual void import(string fileName) = 0;
    virtual ~IList() {}
};
