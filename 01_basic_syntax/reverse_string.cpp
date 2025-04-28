#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

int main() {
    
    char input[100];
    printf("문자를 입력하세요:");
    fseek(stdin, 0, SEEK_END);
    scanf("%99[^\n]", input);
    
    
    int index;
    
    for (int i = 0; ; i++) {
        if (input[i] == '\0') {
            index = i;
            break;
        }
    }
    
    for (int i = index - 1; i >= 0 ; i--) {
        printf("%c", input[i]);
    }
    
    
    return 0;
}
