#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef>
#include <iostream>

class DynamicArray {
private:
    int* data_;
    size_t size_;

    bool checkIndex(size_t index) const;
    bool checkValue(int value) const;

public:
    explicit DynamicArray(size_t size);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);

    size_t getSize() const;
    void print() const;
    void setElement(size_t index, int value);
    int getElement(size_t index) const;
    void pushBack(int value);
    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
};

#endif
