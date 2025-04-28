#include <cstdio>

class Vector3 {
public:
    float x, y, z;  // 축 이름을 x, y, z로 수정
    
    Vector3(float x, float y, float z) {  // 매개변수 이름 수정
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    Vector3() {  // 기본 생성자
        x = 0;
        y = 0;
        z = 0;
    }
    
    void printInfo() {
        printf("%.2f, %.2f, %.2f\n", x, y, z);  // 보기 좋게 줄바꿈 추가
    }
};

// 연산자 오버로딩
Vector3 operator+(Vector3& v1, Vector3& v2) {
    return Vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

int main() {
    Vector3 v1(10, 20, 30);
    Vector3 v2(50, 2, 6);
    Vector3 result = v1 + v2;
    result.printInfo();
    return 0;
}
