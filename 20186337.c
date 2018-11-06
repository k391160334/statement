#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996)

typedef struct personalStatement {
	char name[20];
	struct birth {
		char year[8];
		char month[4];
		char day[4];
	};
	char sex[4];
	char address[20];
	char phone[12];
}PersonalStatement;

int main() {
	PersonalStatement person[10];
	struct birth birth[10];
	int personNum=0;
	for (int i = 0; i < 10; i++) {
		printf("%d번째 사람의 개인명세서를 이름(소문자),생년월일(엔터로 구분),성별,주소,전화번호 별로 입력하시오\n(각 항목은 엔터로 구분하시오, 그만 입력하고 싶으면 이름란에 0입력)\n", i + 1);
		printf("이름: ");
		gets(person[i].name);

		if (person[i].name[0] == '0') {
			personNum = i;
			printf("\n");
			break;
		}
		printf("출생년도: ");
		gets(birth[i].year);
		printf("출생월: ");
		gets(birth[i].month);
		printf("출생일: ");
		gets(birth[i].day);
		printf("성별(f,m): ");
		gets(person[i].sex);
		printf("주소: ");
		gets(person[i].address);
		printf("전화번호: ");
		gets(person[i].phone);
		printf("\n");	
	}                                             //사용자 입력 초기화
	
	printf("이름\t\t생년월일\t\t성별\t\t주소\t\t전화번호\n");
	for (int i = 0; i <personNum; i++) {
		printf("%s\t\t%s-%s-%s\t\t%s\t\t%s\t\t%s\n", person[i].name, birth[i].year, birth[i].month, birth[i].day, person[i].sex, person[i].address, person[i].phone);
	}
	printf("\n");


	PersonalStatement temp;
	struct birth tempp;
	for (int i = 0; i < personNum - 1; i++) {
		for (int j = 0; j < personNum - 1 - i; j++) {
			if (strcmp(person[j].name, person[j+1].name)>0){
					temp = person[j];
					person[j] = person[j + 1];
					person[j + 1] = temp;
					tempp = birth[j];
					birth[j] = birth[j + 1];
					birth[j + 1] = tempp;
			}
		}
	}
	printf("이름\t\t생년월일\t\t성별\t\t주소\t\t전화번호\n");
	for (int i = 0; i <personNum; i++) {
			printf("%s\t\t%s-%s-%s\t\t%s\t\t%s\t\t%s\n", person[i].name, birth[i].year, birth[i].month, birth[i].day, person[i].sex, person[i].address, person[i].phone);
	}
	printf("\n");

	PersonalStatement temp2;
	struct birth tempp2;
	for (int i = 0; i < personNum - 1; i++) {
		for (int j = 0; j < personNum - 1 - i; j++) {
			if ((atoi(birth[j].year)*10000+atoi(birth[j].month)*100+atoi(birth[j].day))> (atoi(birth[j+1].year) * 10000 + atoi(birth[j+1].month) * 100 + atoi(birth[j+1].day))){
				temp2 = person[j];
				person[j] = person[j + 1];
				person[j + 1] = temp2;
				tempp2 = birth[j];
				birth[j] = birth[j + 1];
				birth[j + 1] = tempp2;
			}
		}
	}
	
	printf("이름\t\t생년월일\t\t성별\t\t주소\t\t전화번호\n");
		for (int i = 0; i < personNum; i++) {
			printf("%s\t\t%s-%s-%s\t\t%s\t\t%s\t\t%s\n", person[i].name, birth[i].year, birth[i].month, birth[i].day, person[i].sex, person[i].address, person[i].phone);
		}
	printf("\n");
	
	
}