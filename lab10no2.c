#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentRecord {
    char name[64];
    int age;
};

// ประกาศ Prototype ของฟังก์ชัน
void displayRecord(struct studentRecord student);
void addAge(struct studentRecord *student, int age);

int main () {
    struct studentRecord student[5];
    char tempName[64]; 
    int i;

    // ส่วนการกำหนดค่าเริ่มต้นให้กับ Array ของ Structure
    for(i = 0; i < 5; i++) {
        sprintf(tempName, "Student%d", i); // สร้างชื่อ Student0, Student1, ...
        strcpy(student[i].name, tempName);
        student[i].age = i + 15;           // อายุเริ่มต้น 15, 16, 17, ...
    }

    // เรียกฟังก์ชันบวกอายุเพิ่มคนละ 10 ปี
    for(i = 0; i < 5; i++)
        addAge(&student[i], 10);

    // แสดงผลลัพธ์ทั้งหมด
    for(i = 0; i < 5; i++)
        displayRecord(student[i]);

    return 0;
}

// (1) ฟังก์ชันสำหรับแสดงค่าในสตรัคเจอร์
void displayRecord(struct studentRecord student) {
    printf("Name : %s, Age : %d\n", student.name, student.age);
}

// (2) ฟังก์ชันสำหรับบวกอายุเพิ่ม (ต้องใช้ Pointer เพื่อให้ค่าเปลี่ยนจริง)
void addAge(struct studentRecord *student, int age) {
    // ใช้เครื่องหมาย -> เพื่อเข้าถึงสมาชิกผ่าน Pointer
    student->age = student->age + age;
}