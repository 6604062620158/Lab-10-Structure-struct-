#include <stdio.h> 
#include <stdlib.h> 

struct Books { 
    int BookID; 
    char BookTitle[50]; 
} ComputerBook; 

// ประกาศ Prototype รับค่าเป็น Pointer ของ struct Books
void DisplayData(struct Books *CBook); 

int main() { 
    printf("Enter Book ID :");      
    scanf("%d", &ComputerBook.BookID); 
    
    printf("Enter Book Title :");   
    scanf("%s", ComputerBook.BookTitle); 
    
    // ส่ง "ตำแหน่งที่อยู่" (Address) ของ ComputerBook โดยใช้เครื่องหมาย &
    DisplayData(&ComputerBook); 
    
    return 0; 
} 

// ฟังก์ชันรับพารามิเตอร์เป็น Pointer (struct Books *CBook)
void DisplayData(struct Books *CBook) { 
    // การเข้าถึงข้อมูลผ่าน Pointer ทำได้ 2 รูปแบบตามโจทย์
    printf("Book ID : %d \n", (*CBook).BookID); 
    printf("Book Title : %s \n", CBook->BookTitle); 
}

/*  ทดสอบรันโปรแกรมและเขียนผลลัพท์พร้อมอธิบายโปรแกรม
(*CBook).BookID คือ การเข้าถึงสมาชิกภายในสตรัคเจอร์ผ่าน Pointer โดยใช้เครื่องหมาย * เพื่อกระโดดไปยังที่อยู่ของข้อมูล (Dereferencing) แล้วจึงใช้จุด . เพื่อระบุตัวแปรภายใน หมายเหตุ: ต้องใส่วงเล็บครอบ *CBook เพราะเครื่องหมาย . มีลำดับความสำคัญสูงกว่า *

CBook->BookTitle คือการเข้าถึงสมาชิกภายในสตรัคเจอร์ผ่าน Pointer โดยใช้สัญลักษณ์ลูกศร (->) ซึ่งเป็นวิธีที่ สั้นและนิยมที่สุด ในภาษา C เมื่อตัวแปรนั้นเป็น Pointer มีความหมายเหมือนกับ (*CBook).BookTitle ทุกประการ
*/