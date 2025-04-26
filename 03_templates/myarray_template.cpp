#include <cstdio>
#include <string>

template <typename T>
class MyArray {
private:
    T* arrayItem;
    int count = 0;
    int capacity = 8;
public:
    MyArray() {
        arrayItem = new T[capacity];
    }
    
    virtual ~MyArray() {
        delete[] arrayItem;
    }
    
    void putValue(const T& value) {
        if (capacity <= count) {
            T* newarray = new T[capacity * 2];
            capacity = capacity * 2;
            for (int i = 0; i < count; i++) {
                newarray[i] = arrayItem[i];
            }
            delete[] arrayItem;
            arrayItem = newarray;
            
        }
        arrayItem[count] = value;
        count++;
    }
    
    int getCount() {
        return count;
    }
    
    T getValue(int index) {
        return arrayItem[index];
    }
};

int main() {
    MyArray<std::string> m = MyArray<std::string>();
    
    m.putValue("apple");
    m.putValue("banana");
    m.putValue("integer");
    m.putValue("hi");
    m.putValue("bye");
    m.putValue("string");
    m.putValue("house");
    m.putValue("money");
    m.putValue("car");
    
    for(int i = 0; i < m.getCount(); i++) {
        printf("%s ", m.getValue(i).c_str());
    }
    
    return 0;
}

Add MyArray template class with dynamic resizing
