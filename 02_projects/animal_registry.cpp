#include <cstdio>
#include <cstring>

class Animal {
public:
    char* name;
    int age;
    
    Animal(const char* name, int age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
    }
    
    virtual ~Animal() {
        delete[] name;
    }
    
    virtual void makeSound() = 0;
};

class Cat : public Animal {
public:
    Cat(const char* name, int age) : Animal(name, age) {}
    void makeSound() override {
        printf("야옹!");
    }
};

class Dog : public Animal {
public:
    Dog(const char* name, int age) : Animal(name, age) {}
    void makeSound() override {
        printf("멍멍!");
    }
};

class Lion : public Animal {
public:
    Lion(const char* name, int age) : Animal(name, age) {}
    void makeSound() override {
        printf("어흥!");
    }
};

char* getChar(const char* prompt) {
    printf("%s", prompt);
    char* input = new char[100];
    scanf(" %[^\n]", input);
    return input;
}

int getInt(const char* prompt) {
    printf("%s", prompt);
    int input;
    scanf("%d", &input);
    return input;
}

int main() {
    Animal* animals[3];
    
    for (int i = 0; i < 3; i++) {
        printf("[동물 등록 - %d번째]\n", i + 1);
        int input1 = getInt("종류를 선택하세요 (1. 고양이 / 2. 개 / 3. 사자): ");
        char* input2 = getChar("이름을 입력하세요: ");
        int input3 = getInt("나이: ");
        
        switch(input1) {
        case 1:
            animals[i] = new Cat(input2, input3);
            break;
        case 2: 
            animals[i] = new Dog(input2, input3);
            break;
        case 3:
            animals[i] = new Lion(input2, input3);
            break;
        default:
            printf("입력이 바르지 않습니다.");
            --i;
            continue;
        }
        
        delete[] input2;
    }
    
    printf("[등록된 동물 리스트]\n");
    for(int i = 0; i < 3; i ++) {
        printf("이름: %s / 나이: %d\n", animals[i]->name, animals[i]->age);
        printf("소리: ");
        animals[i]->makeSound();
        printf("\n");
        delete animals[i];
    }
    
    return 0;
}

Add animal registry program with abstract class and polymorphism
