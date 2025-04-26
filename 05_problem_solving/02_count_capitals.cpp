// [대문자 개수 세기]
// 문제 설명: 입력받은 문자열에서 대문자의 개수를 세는 프로그램
// 주요 개념: string, for문, 조건문
// 작성자: Eunseo Chung

#include <cstdio>
#include <string>

std::string getString(const char* prompt) {
    printf("%s", prompt);
    char str[100];
    scanf("%99[^\n]", str);
    return str;
}

int main() {
    std::string str = getString("Enter a string: ");
    int output = 0;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            output++;
        }
    }
    
    printf("대문자 개수: %d\n", output);
    
    return 0;
}

Add problem solving: count capital letters in string
