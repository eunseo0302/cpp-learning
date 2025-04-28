#include <cstdio>
#include <map>
#include <string>

int getInteger(const char* prompt) {
    printf("%s", prompt);
    int input;
    scanf("%d", &input);
    getchar();  // ← 여기에 이거 한 줄 추가! '\n' 제거
    return input;
}

std::string getString(const char* prompt) {
    printf("%s", prompt);
    char str[100];
    scanf("%99[^\n]", str);
    getchar();  // 버퍼 정리
    return str;
}

int main() {
    std::map<std::string, std::string> member;

    for(;;) {
        printf("\n1. 회원가입\n");
        printf("2. 회원출력\n");
        printf("3. 프로그램 종료\n");
        int input = getInteger("숫자를 입력하세요: ");

        switch(input) {
            case 1: {
                std::string ID = getString("ID를 입력하세요: ");
                std::string password = getString("비밀번호를 입력하세요: ");
                if (member.count(ID) == 1) {
                    printf("이미 존재하는 아이디입니다\n");
                } else {
                    member[ID] = password;
                    printf("회원가입이 완료되었습니다\n");
                }
                break;
            }

            case 2: {
                for (auto it = member.begin(); it != member.end(); it++) {
                    printf("ID: %s\n", it->first.c_str());
                }
                break;
            }

            case 3:
                printf("프로그램을 종료합니다\n");
                return 0;

            default:
                printf("숫자를 다시 입력하세요\n");
                break;
        }
    }

    return 0;
}
