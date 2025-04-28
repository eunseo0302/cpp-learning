#include <cstdio>

float getinput();
char getChar();

int main() {
    
    float input1 = getinput();
    float input2 = getinput();
    char cal = getChar();
    
    
    switch(cal) {
        case '+':
            printf("%.3f", input1 + input2);
            break;
        case '-':
            printf("%.3f", input1 - input2);
            break;
        case '*':
            printf("%.3f", input1 * input2);
            break;
        case '/':
        if (input2 == 0) {
            printf("오류입니다");
        }
        else {
            printf("%.3f", input1 / input2);
        }
            break;
        case '%':
            float result;
            result = (int)input1 % (int)input2;
            printf("%.3f", result);
            break;
            
        default:
            printf("오류입니다");
            break;
        
    }
    
    return 0;
}

float getinput() {
    float a;
    printf("입력하세요:");
    fseek(stdin, 0, SEEK_END);
    scanf("%f", &a);
    return a;
}

char getChar() {
    char p;
    printf("연산자를 입력하세요:");
    fseek(stdin, 0, SEEK_END);
    scanf(" %c", &p);
    return p;
}
