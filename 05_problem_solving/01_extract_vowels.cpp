// [모음만 추출하기]
// 문제 설명: 입력받은 문자열에서 모음(a, e, i, o, u)만 출력하는 프로그램
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
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            printf("%c", str[i]);
        }
    }
    
    return 0;
}

Add problem solving: extract vowels from string
