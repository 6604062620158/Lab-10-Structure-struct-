#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// นิยามโครงสร้าง Student
typedef struct {
    char name[64];
    int score;
} Student;

void addStudent(Student *record, char *name, int score);

int main() {
    Student stuRecord[20]; 
    int numStudent, i;

    // เพิ่มข้อมูลนักเรียน
    addStudent(&stuRecord[0], "Sandking", 65);
    addStudent(&stuRecord[1], "Anti-mage", 72);
    addStudent(&stuRecord[2], "Sniper", 40);
    addStudent(&stuRecord[3], "Tiny", 93); 
    addStudent(&stuRecord[4], "Axe", 60);

    numStudent = 5;

    printf("--- Student Grades ---\n");
    for(i = 0; i < numStudent; i++) {
        // ส่วนที่ต้องเติมเพื่อแสดงผลชื่อและเกรด
        printf("Name: %-10s | Score: %3d | Status: ", stuRecord[i].name, stuRecord[i].score);
        
        if (stuRecord[i].score >= 80) {
            printf("very good\n");
        } else if (stuRecord[i].score >= 60) {
            printf("good\n");
        } else {
            printf("keep trying\n");
        }
    }

    return 0;
}

// ฟังก์ชันเพิ่มข้อมูลนักเรียน
void addStudent(Student *record, char *name, int score) {
    strcpy(record->name, name); 
    record->score = score;
}