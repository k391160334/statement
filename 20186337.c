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
		printf("%d��° ����� ���θ����� �̸�(�ҹ���),�������(���ͷ� ����),����,�ּ�,��ȭ��ȣ ���� �Է��Ͻÿ�\n(�� �׸��� ���ͷ� �����Ͻÿ�, �׸� �Է��ϰ� ������ �̸����� 0�Է�)\n", i + 1);
		printf("�̸�: ");
		gets(person[i].name);

		if (person[i].name[0] == '0') {
			personNum = i;
			printf("\n");
			break;
		}
		printf("����⵵: ");
		gets(birth[i].year);
		printf("�����: ");
		gets(birth[i].month);
		printf("�����: ");
		gets(birth[i].day);
		printf("����(f,m): ");
		gets(person[i].sex);
		printf("�ּ�: ");
		gets(person[i].address);
		printf("��ȭ��ȣ: ");
		gets(person[i].phone);
		printf("\n");	
	}                                             //����� �Է� �ʱ�ȭ
	
	printf("�̸�\t\t�������\t\t����\t\t�ּ�\t\t��ȭ��ȣ\n");
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
	printf("�̸�\t\t�������\t\t����\t\t�ּ�\t\t��ȭ��ȣ\n");
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
	
	printf("�̸�\t\t�������\t\t����\t\t�ּ�\t\t��ȭ��ȣ\n");
		for (int i = 0; i < personNum; i++) {
			printf("%s\t\t%s-%s-%s\t\t%s\t\t%s\t\t%s\n", person[i].name, birth[i].year, birth[i].month, birth[i].day, person[i].sex, person[i].address, person[i].phone);
		}
	printf("\n");
	
	
}