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
    int result = 0;
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result += (str[i] - '0');
        }
    }
    
    printf("%d", result);
    
    return 0;
}

Add problem solving: sum digits in a string
