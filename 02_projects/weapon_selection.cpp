#include <cstdio>
#include <cstring>

class Weapon {
public:
    char* name;
    int damage;
    int price;
    
    Weapon (const char* name, int damage, int price) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->damage = damage;
        this->price = price;
    }
    
    ~Weapon() {
        delete[] name;
    }
    
    void printInfo() {
        printf("무기이름: %s\n", name);
        printf("데미지: %d\n", damage);
        printf("가격: %d\n", price);
    }
};

class ShortSword : public Weapon {
public:
    ShortSword() : Weapon("Short Sword", 40, 2500) {}
};

class LongSword : public Weapon {
public:
    LongSword() : Weapon("Long Sword", 30, 2000) {}
};

class Hammer : public Weapon {
public:
    Hammer() : Weapon("Hammer", 20, 1500) {}
};

int main() {
    Weapon* weapons[3] = { new ShortSword(), new LongSword(), new Hammer() };
    int input;
    
    printf("[무기를 선택하세요]\n");
    printf("1. Short Sword\n");
    printf("2. Long Sword\n");
    printf("3. Hammer\n");
    printf("선택: ");
    scanf("%d", &input);
    printf("\n");
    
    if (input >= 1 && input <= 3) {
        weapons[input - 1]->printInfo();
    } else {
        printf("오류입니다. 다시 입력하세요.\n");
    }
    
    for(int i = 0; i < 3; i++) {
        delete weapons[i];
    }
     
    return 0;
}
