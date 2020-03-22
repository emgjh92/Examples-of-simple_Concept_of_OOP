#include <stdio.h> 
#include <stdlib.h> // 문자열 변환, 동적 메모리 관리 등의 함수를 위한 헤더파일 
#include <string.h> //문자열 해더 파일 
// 컴파일 환경 windows 7 OS, Dev C++ 5.11 
// 정상 컴파일 가능 
/* This example was created on September 30, 2016*/
/* This is an example for the basic concept of OOP(Object-oriented programming) */

typedef struct Book{ // 구조체 선언부 ==> Linked List
	char name[20];      // 책의 제목 
	char number[20]; // 수량 
	int type;  	//책의 타입 
	struct Book* link; // Link 데이터  
}book;

typedef struct { // head 구조체 선언 
	book* head;
} linkedList_h;

char menu(void); 
linkedList_h* createLinkedList_head(void); //linked list head 를 만든 후 return 
void Add_book(linkedList_h* L); //책 추가 함수 
void Find(linkedList_h* L); // 책 찾기 함수 


int main(void)
{
	char menuNum; // menu number 
	linkedList_h* L; // Linked List head L  
	L = createLinkedList_head();

	while(1)
	{
		fflush(stdin); //clear the Buffer
		menuNum=menu();
		
		switch(menuNum)
		{
		case '1':
			Add_book(L);
			break;
		case '2':
			Find(L);
			break;
		case '3':
			return 0;
		default: 
			printf("\n잘못 입력하였습니다.\n"); //케이스에 벋어나 잘못된 번호를 입력한 경우 
		}
		
	}

	return 0;
}

linkedList_h* createLinkedList_head(void) { //linked list head 를 만든 후 return 
	linkedList_h* L; //  Linked List head L  
	L = (linkedList_h*)malloc(sizeof(linkedList_h)); // malloc을사용한 동적 메모리 할당  
	L->head = NULL; // head를 NULL 값으로 초기화 
	return L; // return L  
}

char menu(void) { //메뉴 함수 
	
	char choice; // user 가 선택하는 번호  

	printf(
		"\n===================\n"
		"1. 도서 등록 \n"
		"2. 도서 검색 \n"
		"3. 종료"
		"\n===================\n"
		"메뉴를 선택하세요 :"
		); //메뉴 항목 
	scanf("%c",&choice);
	return choice;

}

void Add_book(linkedList_h* L) //도서 추가 함수 
{
	book* newNode; // newNode 만들기 
	book* p; // Node p 만들기 
	newNode = (book*)malloc(sizeof(book)); // malloc 를 이용한 메모리 할당 
	int casenumber;
	printf("\n\n\t\t ** 도서정보 등록 **\n\n");
	printf("도서명을 입력하세요(20자 이내) : ");
	scanf("\n%[^'\n']s",newNode->name); //"\n%[^'\n']s" ==> 공백(띄어쓰기)를을 받기 위함 
	
	printf("0 : E-book, 1 : book, 2 : report\n"); 
	printf("\n도서의 유형을 입력하세요 : ");
	scanf("%d",&casenumber);

	if(casenumber==0)
	{
	newNode->type = 0;
	printf("\n\n\t\t도서가 등록되었습니다\n\n");

	}	 
	else if(casenumber==1)
	{
	newNode->type = 1;
	printf("\n도서의 수량을 입력하세요 : ");
	scanf("%s",newNode->number);
	printf("\n\n\t\t도서가 등록되었습니다\n\n"); 
	}	 
	else if(casenumber==2)
	{
	newNode->type = 2;
	printf("\n도서의 수량을 입력하세요 : ");
	scanf("%s",newNode->number);
	printf("\n\n\t\t도서가 등록되었습니다\n\n");
	}

	newNode->link=NULL; // next NODE 를 null로 초기화 


	if(L->head == NULL) // 아무것도 없는 경우 ==> 처음 데이터를 add 하는 경우 
	{
		L->head = newNode; // head에 newNode를 삽입 후 return 
		return;
	}
	
	p = L->head; // p의 기존 링크드리스트 포인터를 가리킴 
	while(p->link != NULL) // 마지막 노드를 찾을때 까지 이동 
	{
		p=p->link; // 다음 노드로 포인터 옮김 
	}
	p->link = newNode; // 마지막 노드에 newNode를 붙임 (L에 newNode를 붙인것 과 같음) 
	
}


void Find(linkedList_h* L) //도서 검색 함수 
{
	book* p; // linked list p 

	char data[20];	
	printf("\n\t==== 도서정보 검색 ====\n\n");
	printf("찾으실 도서명을 입력하세요 : ");
	scanf("\n%[^'\n']s",data); //"\n%[^'\n']s" ==> 공백(띄어쓰기)을 받기 위함 

	p = L->head; // L의 head를 P에 붙임 
	
	
	while(p != NULL) // p가 null 값이 아닐때까지 ==> 끝까지 
	{
		if(strcmp(p->name,data)==0) //만약 입력된 값과 name에 저장된 값이 같은 경우  
		{
			if(p->type==0)
			{printf("\n\n해당 책 유형은 E-Book 입니다\n\n");}	
			else if(p->type==1)		
			{printf("\n\n해당 책 유형은 Book 이며, 책의 수량은 %s권 입니다\n\n",p->number);}
			else if(p->type==2)		
			{printf("\n\n해당 책 유형은 Report 이며, 책의 수량은 %s권 입니다\n\n",p->number);}		
		}
		else 
		{printf("\n\n찾는 책이 없습니다\n\n");}	
			
		p = p->link; // nextnode로 포인터의 위치를 변경 
		
	}
}
