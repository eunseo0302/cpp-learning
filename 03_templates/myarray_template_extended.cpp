#include <cstdio>
#include <string>

template <typename T>
class MyArray {
public:
    T* arrayItem;
    int count;
    int capacity = 8;
    
    MyArray() {
        arrayItem = new T[capacity];
        count = 0;
    }
    
    virtual ~MyArray() {
        delete[] arrayItem;
    }
    
    void putValue(T value) {
        if (capacity <= count) {
            T* newarray = new T[capacity * 2];
            for (int i = 0; i < count; i++) {
                newarray[i] = arrayItem[i];
            }
            delete[] arrayItem;
            arrayItem = newarray;
            capacity *= 2;
        }
        arrayItem[count++] = value;
    }
    
    bool contains(T value) {
        for (int i = 0; i < count; i++) {
            if (arrayItem[i] == value) {
                return true;
            }
        }
        return false;
    }
    
    void replace(int index, T value) {
        if (index < 0 || index >= count) return;
        arrayItem[index] = value;
    }
    
    void erase(int index) {
        if (index < 0 || index >= count) return;
        for (int i = index; i < count - 1; i++) {
            arrayItem[i] = arrayItem[i + 1];
        }
        count--;
    }
};

