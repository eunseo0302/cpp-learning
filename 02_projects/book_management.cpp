#include <cstdio>
#include <cstring>

class Book {
public:
    char* title;
    char* author;
    int ID;
    
    Book(const char* title, const char* author, int ID) {
        this->title = new char[strlen(title) + 1];
        this->author = new char[strlen(author) + 1];
        strcpy(this->title, title);
        strcpy(this->author, author);
        this->ID = ID;
    }
    
    ~Book() {
        delete[] title;
        delete[] author;
    }
    
    void printInfo() {
        printf("ID: %d\n", ID);
        printf("제목: %s\n", title);
        printf("저자: %s\n", author);
    }
};

char* getChar(const char* prompt) {
    char* input = new char[100];
    printf("%s", prompt);
    scanf(" %[^\n]", input);
    return input;
}

int getInt(const char* prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

int main() {
    char* title;
    char* author;
    int ID;
    Book* books[3];
    
    for(int i = 0; i < 3; i++) {
        printf("[%d번째 책 정보 입력]\n", i + 1);
        title = getChar("제목: ");
        author = getChar("저자: ");
        ID = getInt("ID: ");
        
        books[i] = new Book(title, author, ID);
        delete[] title;
        delete[] author;
    }
    
    printf("[등록된 책 목록]\n");
    
    for(int i = 0; i < 3; i++) {
        books[i]->printInfo();
        delete books[i];
    }
    
    return 0;
}

Add book management program using dynamic memory and classes
