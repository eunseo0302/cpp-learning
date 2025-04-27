#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int getInteger(const char* prompt) {
    printf("%s", prompt);
    int input;
    scanf("%d", &input);
    getchar();
    return input;
}

std::string getString(const char* prompt) {
    printf("%s", prompt);
    char str[100];
    scanf(" %99[^\n]", str);
    return str;
}

class Student {
public:
    std::string name;
    int korean;
    int math;
    int english;
    
    Student(std::string name, int korean, int math, int english) {
        this->name = name;
        this->korean = korean;
        this->math = math;
        this->english = english;
    }
    
    void printInfo() {
        printf("%s, %d, %d, %d\n", name.c_str(), korean, math, english);
    }
    
    float average() {
        float av;
        av = (korean + math + english) / 3.0f;
        return av;
    }
};

void saveStudents(const vector<Student>& students) {
    FILE* fp = fopen("student.txt", "w");
    for (int i = 0; i < students.size(); i++) {
        fprintf(fp, "%s %d %d %d\n", students[i].name.c_str(), students[i].korean, students[i].math, students[i].english);
    }
    fclose(fp);
}

void loadStudents(vector<Student>& students) {
    FILE* fp = fopen("student.txt", "r");
    if (fp == nullptr) {
        printf("파일 열기 실패!\n");
        return;
    }
    students.clear();
    
    char name[100];
    int korean, math, english;

    while (fscanf(fp, "%s %d %d %d", name, &korean, &math, &english) == 4) {
        students.push_back(Student(name, korean, math, english));
    }
    
    fclose(fp);
}

int main() {
    vector<Student> students;

    int menu;
    printf("1. 학생 추가  2. 저장하기  3. 불러오기  4. 출력  5. 종료\n");

    while (true) {
        printf("메뉴 선택: ");
        scanf("%d", &menu);
        getchar();

        if (menu == 1) {
            // 학생 추가
            std::string name = getString("enter name: ");
            int korean = getInteger("enter score korean: ");
            int math = getInteger("enter score math: ");
            int english = getInteger("enter score english: ");
            Student s(name, korean, math, english);
            students.push_back(s);
        }
        else if (menu == 2) {
            saveStudents(students);
        }
        else if (menu == 3) {
            loadStudents(students);
        }
        else if (menu == 4) {
            for (int i = 0; i < students.size(); i++) {
                students[i].printInfo();
                printf("%.2f\n", students[i].average());
            }
        }
        else if (menu == 5) {
            printf("프로그램 종료!\n");
            break;
        }
    }

    return 0;
}
