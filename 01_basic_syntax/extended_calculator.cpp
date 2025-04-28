#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

float getFloat();
char getChar();

int main() {
    float input1;
    float input2;
    char oper;
    bool valid = true;
    
    input1 = getFloat();
    input2 = getFloat();
    oper = getChar();
    
    float result;
    int w;
    
    switch(oper) {
        case '+':
        result = input1 + input2;
        break;
        case '-':
        result = input1 - input2;
        break;
        case '*':
        result = input1 * input2;
        break;
        case '/':
        if (input2 != 0) {
            result = input1 / input2;
        }
        else {
            valid = false;
        }
        break;
        case '%':
        result = (int)input1 % (int)input2;
        break;
        case 'p':
        result = pow(input1, input2);
        break;
        case 'x':
        valid = false;
        break;
        case 'r':
        srand(time(0));
        result = rand() % 6;
        
        break;
        default:
        valid = false;
        break;
        
    }
    if (valid) {
        printf("%f", result);
        
    }
    else {
        printf("오류입니다");
    }
    
    return 0;
}

float getFloat(){
    float a;
    printf("실수를 입력하세요: ");
    fseek(stdin, 0, SEEK_END);
    scanf("%f", &a);
    return a;
}

char getChar(){
    char a;
    printf("연산자를 입력하세요: ");
    fseek(stdin, 0, SEEK_END);
    scanf(" %c", &a);
    return a;
}
