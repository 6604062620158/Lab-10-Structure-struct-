#include <stdio.h>
#include <string.h>

typedef struct {
    char loginname[64];
    char password[64];
} account;

typedef struct {
    char stdID[16];
    char nameSurname[25];
    account stdACC; // สตรัคเจอร์ account ที่ซ้อนอยู่ข้างใน
} hoststd;

int main() {
    // กำหนดข้อมูลสมมติ 5 คน
    hoststd cs[5] = {
        {"66-040626-0001-1", "MR.A", {"user1", "passwd1"}},
        {"66-040626-0002-2", "MR.B", {"user2", "passwd2"}},
        {"66-040626-0003-3", "MR.C", {"user3", "passwd3"}},
        {"66-040626-0004-4", "MR.D", {"user4", "passwd4"}},
        {"66-040626-0005-5", "MR.E", {"user5", "passwd5"}}
    };

    char inputUser[64], inputPass[64];
    int i, found = 0;

    // รับข้อมูลจากผู้ใช้
    printf("Login Name: ");
    scanf("%s", inputUser);
    printf("Password: ");
    scanf("%s", inputPass);

    // วนลูปตรวจสอบข้อมูลทั้ง 5 คน
    for (i = 0; i < 5; i++) {
        // การเข้าถึงข้อมูลที่ซ้อนกัน: cs[i].stdACC.loginname
        if (strcmp(inputUser, cs[i].stdACC.loginname) == 0 && 
            strcmp(inputPass, cs[i].stdACC.password) == 0) {
            found = 1;
            break; // ถ้าเจอที่ตรงกันแล้วให้หยุดหาทันที
        }
    }

    // แสดงผลลัพธ์
    if (found == 1) {
        printf("Welcome, %s\n", cs[i].nameSurname);
    } else {
        printf("Incorrect login or password\n");
    }

    return 0;
}