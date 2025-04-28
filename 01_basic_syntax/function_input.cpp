#include <cstdio>

int getInput() {
    int input = 0;
    printf("숫자를 입력해주세요: ");
    fseek(stdin, 0, SEEK_END);
    scanf("%d", &input);
    return input;
}

int main() {
    int input = getInput();
    
    if (input <= 0) {
        printf("숫자를 다시 입력해주세요\n");
    } else {
        for (int i = 0; i < input; i++) {
            printf("A");
        }
        printf("\n");
    }

    input = getInput();

    if (input <= 0) {
        printf("숫자를 다시 입력해주세요\n");
    } else {
        for (int i = 0; i < input; i++) {
            printf("B");
        }
        printf("\n");
    }

    return 0;
}
