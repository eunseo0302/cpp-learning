#include <cstdio>
#include <cstring>

class Patient {
public:
    char* name;
    int age;
    
    Patient(const char* name, int age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
    }
    
    virtual ~Patient() {
        delete[] name;
    }
    
    virtual void treat() {}
    
    void introduce() {
        printf("이름: %s / 나이: %d\n", name, age);
    }
};

class DentalPatient : public Patient {
public:
    DentalPatient(const char* name, int age) : Patient(name, age) {}
    
    void treat() override {
        printf("충치를 치료합니다.\n");
    }
};

class SurgeryPatient : public Patient {
public:
    SurgeryPatient(const char* name, int age) : Patient(name, age) {}
    
    void treat() override {
        printf("수술을 준비합니다.\n");
    }
};

class PsychPatient : public Patient {
public:
    PsychPatient(const char* name, int age) : Patient(name, age) {}
    
    void treat() override {
        printf("상담을 시작합니다.\n");
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
    Patient* patients[3];
    
    for (int i = 0; i < 3; i++) {
        printf("[환자 등록 - %d번째]\n", i + 1);
        char* name = getChar("이름: ");
        int age = getInt("나이: ");
        int input;
        printf("진료과목 (1. 치과 / 2. 외과 / 3. 정신과): ");
        
        if (scanf("%d", &input) != 1) {
            printf("입력이 바르지 않습니다. 숫자를 입력하세요.\n");
            while (getchar() != '\n');
            --i;
            continue;
        }
        getchar();
        
        switch(input) {
        case 1:
            patients[i] = new DentalPatient(name, age);
            break;
        case 2:
            patients[i] = new SurgeryPatient(name, age);
            break;
        case 3:
            patients[i] = new PsychPatient(name, age);
            break;
        default:
            printf("입력이 바르지 않습니다.\n");
            --i;
            continue;
        }
        
        delete[] name;
    }
    
    for (int i = 0; i < 3; i++) {
        patients[i]->introduce();
        patients[i]->treat();
        delete patients[i];
    }
    
    return 0;
}

Add patient management system using class inheritance and polymorphism
