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
			printf("错误选择\n");
			system("pause");
			system("cls");
		}
	}while(k);
	return 0;
}
int menu()
{
	int n=0;
	printf("   早餐管理系统\n");
	printf("*******************\n");
	printf("1:输入菜单餐品总数\n");
	printf("2:菜单价格录入\n");
	printf("3:点餐\n");
	printf("4:计算和打印账单\n");
	printf("0:退出\n");
	printf("*******************\n");
	printf("请选择: ");
	scanf("%d",&n);
	return n;
}
int getN()
{
	int N;
	printf("请输入菜单餐品总数(最高为100种)\n");
	scanf("%d",&N);
	system("pause");
	system("cls");	
	return N;
}
void getData(struct menuItemType menuList[100],int N)
{
	int i;
	printf("本餐馆共可以提供%d种菜品，下面开始录入数据\n",N);
	for(i=0;i<N;i++)
	{
		printf("请输入第%d种菜品的名称和价格:",i+1);
		scanf("%s%f",menuList[i].menuItem,&menuList[i].menuPrice);
	}
	printf("早餐数据录入完毕!\n\n");
	system("pause");
	system("cls");
}
void showMenu(struct menuItemType menuList[100],int food[100],int N)
{
	int i,j,num;
	char f[20];
	printf("以下是所提供的早餐品种:\n");
	for(i=0;i<N;i++)
	{
		printf("%-20s  $%4.2f\n",menuList[i].menuItem,menuList[i].menuPrice);
	}
	printf("请输入你想点的餐品总数(同种餐品重复计算总数):");
	scanf("%d",&num);
	printf("请点餐(请输入早餐名)\n");
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
	printf("点餐完毕!\n\n");
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
	printf("序号   名称              份数    价格\n");
	for(i=0;i<N;i++)
	{
		if(food[i]>0)
		{
			printf("%d      %-20s%d    $%4.2f\n",k,menuList[i].menuItem,food[i],food[i]*menuList[i].menuPrice);
			k++;
		}
	}
	printf("    税费                        $%4.2f\n",tax);
	printf("    总计                        $%4.2f\n",amount);
	printf("**************************************\n");
	printf("账单打印完毕!\n\n");
	k=1;
	if((fp=fopen("bill.txt","w"))==NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	fprintf(fp,"    Welcome to Johnny's Restaurant\n");
	fprintf(fp,"**************************************\n");
	fprintf(fp,"序号   名称              份数    价格\n");
	for(i=0;i<N;i++)
	{
		if(food[i]>0)
		{
			fprintf(fp,"%d        %-20s%d      $%4.2f\n",k,menuList[i].menuItem,food[i],food[i]*menuList[i].menuPrice);
			k++;
		}
	}
	fprintf(fp,"    税费                             $%4.2f\n",tax);
	fprintf(fp,"    总计                             $%4.2f\n",amount);
	fprintf(fp,"**************************************\n");
    fclose(fp);
	system("pause");
	system("cls");
}