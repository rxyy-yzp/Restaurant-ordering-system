#include"stdio.h"
#include"string.h"
#include"stdlib.h"
int menu();
int getN();
void getData(struct menuItemType menuList[100],int N);
void showMenu(struct menuItemType menuList[100],int food[100],int N);
void printCheck(struct menuItemType menuList[100],int food[100],int N);
struct menuItemType
{
	char menuItem[20];
	float menuPrice;
}menuList[100];
int main()
{
	int i,N=0,k=0;
    int food[100]={0};
	do{
		k=menu();
		switch(k)
		{
		case 0:
			break;
		case 1:
			N=getN();
			break;
		case 2:
			getData(menuList,N);
			break;
		case 3:
			showMenu(menuList,food,N);
			break;
		case 4:
			printCheck(menuList,food,N);
			break;
		default:
			printf("����ѡ��\n");
			system("pause");
			system("cls");
		}
	}while(k);
	return 0;
}
int menu()
{
	int n=0;
	printf("   ��͹���ϵͳ\n");
	printf("*******************\n");
	printf("1:����˵���Ʒ����\n");
	printf("2:�˵��۸�¼��\n");
	printf("3:���\n");
	printf("4:����ʹ�ӡ�˵�\n");
	printf("0:�˳�\n");
	printf("*******************\n");
	printf("��ѡ��: ");
	scanf("%d",&n);
	return n;
}
int getN()
{
	int N;
	printf("������˵���Ʒ����(���Ϊ100��)\n");
	scanf("%d",&N);
	system("pause");
	system("cls");	
	return N;
}
void getData(struct menuItemType menuList[100],int N)
{
	int i;
	printf("���͹ݹ������ṩ%d�ֲ�Ʒ�����濪ʼ¼������\n",N);
	for(i=0;i<N;i++)
	{
		printf("�������%d�ֲ�Ʒ�����ƺͼ۸�:",i+1);
		scanf("%s%f",menuList[i].menuItem,&menuList[i].menuPrice);
	}
	printf("�������¼�����!\n\n");
	system("pause");
	system("cls");
}
void showMenu(struct menuItemType menuList[100],int food[100],int N)
{
	int i,j,num;
	char f[20];
	printf("���������ṩ�����Ʒ��:\n");
	for(i=0;i<N;i++)
	{
		printf("%-20s  $%4.2f\n",menuList[i].menuItem,menuList[i].menuPrice);
	}
	printf("�����������Ĳ�Ʒ����(ͬ�ֲ�Ʒ�ظ���������):");
	scanf("%d",&num);
	printf("����(�����������)\n");
	getchar();
	for(i=0;i<num;i++)
	{
		gets(f);
		for(j=0;j<N;j++)
		{
			if(strcmp(f,menuList[j].menuItem)==0)
			{
				food[j]++;
				break;
			}
		}
	}
	printf("������!\n\n");
	system("pause");
	system("cls");
}
void printCheck(struct menuItemType menuList[100],int food[100],int N)
{
	int i,k=1;
	float sum=0,tax=0,amount=0;
	FILE *fp;
	for(i=0;i<N;i++)
	{
		sum=sum+(food[i])*(menuList[i].menuPrice);
	}
	tax=sum*0.05;
	amount=sum+tax;
	printf("\n    Welcome to Johnny's Restaurant\n");
	printf("**************************************\n");
	printf("���   ����              ����    �۸�\n");
	for(i=0;i<N;i++)
	{
		if(food[i]>0)
		{
			printf("%d      %-20s%d    $%4.2f\n",k,menuList[i].menuItem,food[i],food[i]*menuList[i].menuPrice);
			k++;
		}
	}
	printf("    ˰��                        $%4.2f\n",tax);
	printf("    �ܼ�                        $%4.2f\n",amount);
	printf("**************************************\n");
	printf("�˵���ӡ���!\n\n");
	k=1;
	if((fp=fopen("bill.txt","w"))==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	fprintf(fp,"    Welcome to Johnny's Restaurant\n");
	fprintf(fp,"**************************************\n");
	fprintf(fp,"���   ����              ����    �۸�\n");
	for(i=0;i<N;i++)
	{
		if(food[i]>0)
		{
			fprintf(fp,"%d        %-20s%d      $%4.2f\n",k,menuList[i].menuItem,food[i],food[i]*menuList[i].menuPrice);
			k++;
		}
	}
	fprintf(fp,"    ˰��                             $%4.2f\n",tax);
	fprintf(fp,"    �ܼ�                             $%4.2f\n",amount);
	fprintf(fp,"**************************************\n");
    fclose(fp);
	system("pause");
	system("cls");
}