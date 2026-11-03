#include "DynamicArray.h"
#include <iostream>

int main() {
    DynamicArray arr1(3);
    arr1.setElement(0, 10);
    arr1.setElement(1, -50);
    arr1.setElement(2, 100);
    std::cout << "arr1: "; arr1.print();

    DynamicArray arr2(arr1);
    std::cout << "arr2 (копия): "; arr2.print();

    arr1.pushBack(42);
    std::cout << "arr1 после pushBack: "; arr1.print();

    DynamicArray arr3(2);
    arr3.setElement(0, 5); arr3.setElement(1, 5);
    arr1.add(arr3);
    std::cout << "arr1 после add: "; arr1.print();
    
    arr1.subtract(arr3);
    std::cout << "arr1 после subtract: "; arr1.print();

    return 0;
}
