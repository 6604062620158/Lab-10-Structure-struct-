#include <stdio.h>

typedef struct {
    char name[64]; // ชื่อนักเรียน
    char ans[10];  // กระดาษคำตอบ
} Student;

int checkscore(Student *s);

int main() {
    int i;
    // ข้อมูลนักเรียน 6 คน
    Student std[6] = {
        {"AAA", {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}}, // 7
        {"BBB", {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'}}, // 6
        {"CCC", {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'}}, // 5
        {"DDD", {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'}}, // 4
        {"EEE", {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}}, // 8
        {"FFF", {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}}  // 7
    };

    for (i = 0; i < 6; i++) {
        // เติมพารามิเตอร์ใน printf: 
        // 1. std[i].name เพื่อแสดงชื่อ
        // 2. checkscore(&std[i]) เพื่อส่งที่อยู่ของ struct ไปตรวจคะแนน
        printf("%s => %d\n", std[i].name, checkscore(&std[i]));
    }
    
    return 0;
}

// ฟังก์ชันสำหรับตรวจคะแนน
int checkscore(Student *s) {
    // เฉลยคำตอบ (Answer Key)
    char key[10] = {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'};
    int score = 0;
    int i;

    // วนลูปเทียบคำตอบนักเรียนกับเฉลยทีละข้อ
    for (i = 0; i < 10; i++) {
        if (s->ans[i] == key[i]) {
            score++;
        }
    }
    return score;
}