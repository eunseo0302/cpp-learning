#include <cstdio>
#include <string>
#include <map>

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

int main() {
    std::map<std::string, std::string> dict;
    
    for(;;) {
        printf("\n1. 단어 입력\n");
        printf("2. 단어 검색\n");
        printf("3. 프로그램 종료\n");
        int input = getInteger("숫자를 입력하세요: ");
        if (input == 1) {
            std::string word = getString("단어를 입력하세요: ");
            std::string def = getString("의미를 입력하세요: ");
            dict[word] = def;
        }
        else if (input == 2) {
            std::string word = getString("찾을 단어를 입력하세요: ");
            if (dict.count(word) == 1) {
                printf("%s\n", dict[word].c_str());
            }
            else {
                printf("단어가 없습니다");
            }
        }
        else if (input == 3) {
            printf("프로그램을 종료합니다");
            return 0;
        }
        else {
            printf("다시 숫자를 입력하세요");
        }
    }
    
    return 0;
}
