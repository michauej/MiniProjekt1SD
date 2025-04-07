#pragma once

template <typename T>
class IList {
public:
    virtual void addAtStart(T value) = 0;
    virtual void addAtEnd(T value) = 0;
    virtual void addAtIndex(int index, T value) = 0;
    virtual void removeAtStart() = 0;
    virtual void removeAtEnd() = 0;
    virtual void removeAtIndex(int index) = 0;
    virtual bool search(T value) = 0;
    virtual int getSize() = 0;
    virtual ~IList() {}
};