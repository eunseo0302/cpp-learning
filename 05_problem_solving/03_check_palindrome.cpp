// [회문 판별하기]
// 문제 설명: 입력받은 문자열이 앞뒤로 같은지 판별하는 프로그램 (대소문자 구분 X)
// 주요 개념: string, tolower, for문, 조건문
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
        str[i] = tolower(str[i]);
    }
    
    bool isPalindrome = true;
    
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - i - 1]) {
            isPalindrome = false;
            break;
        }
    }
    
    if (isPalindrome) {
        printf("회문입니다\n");
    } else {
        printf("회문이 아닙니다\n");
    }
    
    return 0;
}
