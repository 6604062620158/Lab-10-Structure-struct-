#include <stdio.h> 
#include <stdlib.h> 

struct Books { 
    int BookID; 
    char BookTitle[50]; 
} ComputerBook; // ประกาศตัวแปร ComputerBook เป็น Global

void DisplayData(struct Books CBook); 

int main() { 
    printf("Enter Book ID :");      
    // เติม &ComputerBook.BookID เพราะ scanf ต้องการที่อยู่ (Address) ของตัวแปร int
    scanf("%d", &ComputerBook.BookID); 
    
    printf("Enter Book Title :");   
    scanf("%s", ComputerBook.BookTitle); 
    
    DisplayData(ComputerBook); // ส่งข้อมูลไปยังฟังก์ชัน DisplayData 
    return 0; 
} 

void DisplayData(struct Books CBook) { 
    // ใช้ CBook ซึ่งเป็นชื่อพารามิเตอร์ของฟังก์ชันนี้ในการเข้าถึงข้อมูล
    printf("Book ID : %d \n", CBook.BookID); 
    printf("Book Title : %s \n", CBook.BookTitle); 
}

/*  void DisplayData(struct Books CBook) คือ ฟังก์ชันที่ทำหน้าที่แสดงผลข้อมูลของหนังสือ 
โดยมีการระบุว่าฟังก์ชันนี้ไม่คืนค่ากลับ (void) และรับอาร์กิวเมนต์เป็นสตรัคเจอร์ชนิด struct Books 
พารามิเตอร์ที่รับคือตัวแปร CBook ซึ่งเป็น สำเนา (Copy) ของตัวแปร ComputerBook ที่ถูกส่งมาจากฟังก์ชัน main 
โดยเป็นการส่งค่าแบบ Pass by Value (หากมีการแก้ไขค่า CBook ภายในฟังก์ชันนี้ จะไม่มีผลกระทบต่อ ComputerBook ตัวจริงใน mainเข้ามา


*/