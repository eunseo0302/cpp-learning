#include <cstdio>
#include <cstring>

int number = 0;

int getInt(const char* prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    getchar(); // 개행 문자 제거
    return input;
}

char* getString(const char* prompt) {
    char* input = new char[100];
    printf("%s", prompt);
    scanf(" %[^\n]", input);  // 개행 포함 X
    getchar(); // 버퍼 클리어
    return input;
}

class Emp {
public:
    int empno;
    char name[20];
    int gender;
    char rank[20];

    Emp(const char* name, int gender, const char* rank) {
        strcpy(this->name, name);
        this->gender = gender;
        strcpy(this->rank, rank);
        this->empno = number;
        number++;
    }

    void printInfo() {
        printf("사원번호: %d\n", empno);
        printf("사원명: %s\n", name);
        printf("성별: %s\n", gender == 0 ? "남성" : "여성");
        printf("직급: %s\n", rank);
    }
};

int main() {
    Emp* employee[100];  // ✅ 배열 선언만
    int count = 0;

    while (true) {
        printf("\n명령을 입력하세요\n");
        printf("1. 사원 보기\n");
        printf("2. 사원 추가\n");
        printf("3. 사원 삭제\n");
        printf("4. 프로그램 종료\n");

        int input;
        scanf("%d", &input);
        getchar();  // 버퍼 클리어

        if (input == 1) {
            for (int i = 0; i < count; i++) {
                employee[i]->printInfo();
                printf("---------------\n");
            }
        } else if (input == 2) {
            char* name = getString("사원명 입력해주세요: ");
            int gender = getInt("성별 입력해주세요 (0:남, 1:여): ");
            char* rank = getString("직급을 입력해주세요: ");

            Emp* e = new Emp(name, gender, rank);
            delete[] name;
            delete[] rank;

            employee[count] = e;
            count++;
        } else if (input == 3) {
            int empNo = getInt("삭제할 사원번호를 입력해주세요: ");
            int deleteIndex = -1;
            for (int i = 0; i < count; i++) {
                if (employee[i]->empno == empNo) {
                    delete employee[i];
                    deleteIndex = i;
                    break;
                }
            }
            if (deleteIndex >= 0) {
                for (int i = deleteIndex; i < count - 1; i++) {
                    employee[i] = employee[i + 1];
                }
                count--;
                printf("삭제되었습니다.\n");
            } else {
                printf("해당 번호의 사원이 없습니다.\n");
            }
        } else if (input == 4) {
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("오류입니다. 다시 입력하세요.\n");
        }
    }

    // 남은 메모리 해제
    for (int i = 0; i < count; i++) {
        delete employee[i];
    }

    return 0;
}

Add employee management system using classes and dynamic memory
