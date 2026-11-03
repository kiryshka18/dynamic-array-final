#include "DynamicArray.h"

bool DynamicArray::checkIndex(size_t index) const {
    if (index >= size_) {
        std::cout << "Ошибка: Индекс выходит за пределы массива!" << std::endl;
        return false;
    }
    return true;
}

bool DynamicArray::checkValue(int value) const {
    if (value < -100 || value > 100) {
        std::cout << "Ошибка: Значение вне допустимого диапазона [-100, 100]!" << std::endl;
        return false;
    }
    return true;
}

DynamicArray::DynamicArray(size_t size) : size_(size) {
    data_ = new int[size_]{};
}

DynamicArray::~DynamicArray() {
    delete[] data_;
}

DynamicArray::DynamicArray(const DynamicArray& other) : size_(other.size_) {
    data_ = new int[size_];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

size_t DynamicArray::getSize() const { return size_; }

void DynamicArray::print() const {
    std::cout << "[ ";
    for (size_t i = 0; i < size_; ++i) std::cout << data_[i] << " ";
    std::cout << "]" << std::endl;
}

void DynamicArray::setElement(size_t index, int value) {
    if (!checkIndex(index) || !checkValue(value)) return;
    data_[index] = value;
}

int DynamicArray::getElement(size_t index) const {
    if (!checkIndex(index)) return 0;
    return data_[index];
}

void DynamicArray::pushBack(int value) {
    if (!checkValue(value)) return;
    int* newData = new int[size_ + 1];
    for (size_t i = 0; i < size_; ++i) newData[i] = data_[i];
    newData[size_] = value;
    delete[] data_;
    data_ = newData;
    size_++;
}

void DynamicArray::add(const DynamicArray& other) {
    for (size_t i = 0; i < size_; ++i) {
        int otherVal = (i < other.size_) ? other.data_[i] : 0;
        data_[i] += otherVal;
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    for (size_t i = 0; i < size_; ++i) {
        int otherVal = (i < other.size_) ? other.data_[i] : 0;
        data_[i] -= otherVal;
    }
}
