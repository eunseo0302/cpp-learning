#include <cstdio>
#include <string>
using namespace std;

enum Subject {
    INTERNAL,  // 내과
    SURGERY,   // 외과
    DENTAL,    // 치과
    SKIN       // 피부과
};

const string SubjecttoString(Subject subject) {
    switch(subject){
        case INTERNAL: return "내과";
        case SURGERY:  return "외과";
        case DENTAL:   return "치과";
        case SKIN:     return "피부과";
        default:       return "알 수 없음";
    }
}

class Animal {
public:
    string name;
    int age;
    Subject subject;
    static int totalAnimals;
    static const string hospitalName;
    
    Animal(string name, int age, Subject subject) {
        this->name = name;
        this->age = age;
        this->subject = subject;
        totalAnimals++;
    }
    
    void printInfo() {
        printf("이름: %s, 나이: %d, 병원: %s, 진료과목: %s\n", name.c_str(), age, hospitalName.c_str(), SubjecttoString(subject).c_str());
    }
};

int Animal::totalAnimals = 0;
const string Animal::hospitalName = "드림 동물병원";

void updateAge(Animal& an, int age) {
    an.age = age;
}

void changeName(Animal& an, const string& name) {
    an.name = name;
}

string getString(const string& prompt) {
    char buffer[100];
    printf("%s", prompt.c_str());
    scanf(" %[^\n]", buffer);
    return string(buffer);
}

int getInt(const string& prompt) {
    printf("%s", prompt.c_str());
    int input;
    scanf("%d", &input);
    getchar();
    return input;
}

Subject getSubject() {
    int choice;
    printf("진료과목 선택 (0: 내과, 1: 외과, 2: 치과, 3: 피부과): ");
    scanf("%d", &choice);
    getchar();
    return static_cast<Subject>(choice);
}

int main() {
    const int Max = 3;
    Animal* animals[Max];
    
    for(int i = 0; i < Max; i++){
        string name = getString("이름: ");
        int age = getInt("나이: ");
        Subject subject = getSubject();
        
        animals[i] = new Animal(name, age, subject);
    }
    
    updateAge(*animals[0], 2);
    changeName(*animals[1], "온이");
    
    for(int i = 0; i < Max; i++){
        animals[i]->printInfo();
        delete animals[i];
    }
    
    return 0;
}
