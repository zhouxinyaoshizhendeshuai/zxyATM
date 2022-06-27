#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"

struct Account{
	int zh;
	char name[20];
	int password;
	double money;
	int status;
	int balance;
};
Account user[6];

int order = 1;           //����˳��ı���
int confirmpassword[6];  //ȷ���õ�����

//�˵�1
void ShowMenu_1()
{
	printf("��ӭʹ�ã�");
	printf("\t\t������\n");
	printf("===========================================\n");
	printf("\t��ѡ����Ĳ�����\n");
	printf("\t1.����\t2.��¼\t3.�˳�ϵͳ\n");
	printf("\t4.��ʾĿǰ�˻�������Ϣ\n");
	printf("��ȷ�����ѡ��");
	printf("===========================================\n");
}
//�˵�2
void ShowMenu_2()
{
	printf("\t\t��ӭʹ��ATM���й���ϵͳ,ף��ʹ����죡\n");
	printf("===============================================\n");
	printf("\t��ѡ��ȷ����Ĳ�����\n");
	printf("\t1.���\t2.ȡ��\t3.��ѯ\t4.ת��\n");
	printf("\t5.��ʧ\t6.���\t7.����\t8.�˳����˵�\n");
	printf("ѡ����ϣ�");
	printf("===============================================\n");
}

//����
void Authoring(Account user[])
{
	user[order].zh = 123456 + order;
	printf("��ʼע���˻�����\n\n");
	printf("�������û�������");
	scanf("%s",&user[order].name);
	printf("���������룺");
	scanf("%d",&user[order].password);
	printf("���ٴ���������ȷ�ϣ�");
	scanf("%d",&confirmpassword[order]);

	if(user[order].password == confirmpassword[order])
	{
		printf("�����ɹ���\n");
		printf("�����˺��ǣ�%d\n\n",user[order].zh);
		order++;
	}
	else
	{
		printf("���벻һ�£�����ʧ�ܣ�\n");
		user[order].password = 0;
		confirmpassword[order] = 0;
	}
}
//���
double Desposit(Account user[],int a)
{
	double desposit_money = 0;
	printf("��������Ҫ�洢�Ľ��Ϊ��");
	scanf("%lf",&desposit_money);

	return user[a].money += desposit_money;
}

//ȡ��
double Draw(Account user[],int b)
{
	double draw_money = 0;
	printf("��������Ҫȡ���Ľ��Ϊ��");
	scanf("%lf",&draw_money);

	if(draw_money < user[b].money)
	{
		return user[b].money -= draw_money;
	}
	else
	{
		printf("�Բ������㣬�޷�ȡ���������˻���Ȼ�����ԣ�лл\n\n");
		return -1;
	}
}

//ת��0
void Transfer(Account user[],int c)
{
	Account target;
	printf("��������Ҫת�˵Ķ����˺�Ϊ��");
	scanf("%d",&target.zh);

	for(int j = 1;j <= 6;j++)
	{
		if(target.zh == user[j].zh)
		{
			double transfer_money = 0;
			printf("��������Ҫת�˵Ľ��Ϊ��");
			scanf("%lf",&transfer_money);

			if(transfer_money < user[c].money)
			{
				user[j].money += transfer_money;
				user[c].money -= transfer_money;
				break;
			}
			else
			{
				printf("�Բ������㣡\n\n");
				break;
			}
		}
	}

	if(target.zh != user[j].zh)
	{
		printf("�Բ���û���ҵ���Ҫת�˵Ķ���\n\n");
		printf("�����ԣ�");
	}
}
void GuaShi(Account user[],int h)
{
	printf("��������Ϊ��%s\n",user[h].name);
    if(user[h].status == 0)
	{
	   user[h].status = 1;
	   printf("��ʧ�ɹ���\n");
	}
}


void JieGua(Account user[],int m)
{
    printf("��������Ϊ��%s\n",user[m].name);
	if(user[m].status == 0)
	{
		printf("���˻���������״̬�������ʧ��\n");
	}
	else if(user[m].status == 1)
	{
		user[m].status = 0;
		printf("�����ʧ�ɹ���\n");
	}
}
void XiaoHu(Account user[],int n)
{
	printf("����������%s\t��%.2fԪ\n",user[n].name,user[n].balance);

	user[n].balance = 0;
	user[n].status = 2;
    printf("ȡ��: %.2fԪ�������ɹ���\n",user[n].balance);

}




//�û�����
int ATMsystem(Account user[],int p)
{
	int q;

	while(1)
	{
		ShowMenu_2();

		printf("��ѡ����Ӧ�˵��");
		scanf("%d",&q);
		printf("\n\n");

		switch(q)
		{
		case 1:{
			Desposit(user,p);
			printf("��ǰ���Ϊ��%.2lf\n\n",user[p].money);
			break;
			   }

		case 2:{
			Draw(user,p);
			printf("��ǰ���Ϊ��%.2lf\n\n",user[p].money);
			break;
			   }

		case 3:{
			printf("��ǰ���Ϊ��%.2lf\n\n",user[p].money);
			break;
			   }

		case 4:{
			Transfer(user,p);
			printf("��ǰ���Ϊ��%.2lf\n\n",user[p].money);
			break;
			   }

		case 5:
			GuaShi(user,p);
			break;
             
		case 6:
			JieGua(user,p);
			break;
		case 7:
			XiaoHu(user,p);
			break;
		case 8:{
			printf("�����˳�����\n\n\n\n\n\n");
			return q;
			   }
		}
	}
}

//��¼
void Enroll(Account user[])
{
	Account user2;
	char mm[10];
	int pass;

	printf("����������˺ţ�");
	scanf("%d",&user2.zh);

	printf("���������벢ȷ�ϣ�");
	for(int i = 0;i < 10;i++)
	{
			mm[i] = getch();
			if(mm[i] == '\r')
				break;
			if(mm[i] >= '0' && mm[i] <= '9')
			{
				printf("*");
			}
	}
	mm[i] = '\0';
	pass = atoi(mm);

	printf("\n\n");

	for(i = 1;i <= 6;i++)
	{
		if(user2.zh == user[i].zh)
		{
			if(pass == user[i].password)
			{
				printf("\n\n\n\n\n\n");
				ATMsystem(user,i);
				break;
			}
			else
			{
				printf("�˺Ż�����������鲢��������\n\n");
				break;
			}
		}
	}
	
}
//��ʾĿǰ�˻�������Ϣ
void Show_accounts(Account user[])
{
	printf("�˺������������£�\n");
	for(int t = 1;t <= 6;t++)
	{
		printf("�˻�Ϊ��%d\t",user[t].zh);
		printf("�û���Ϊ��%s\t",user[t].name);
		printf("����Ϊ��%d\t",user[t].password);
		printf("���Ϊ��%.2lf\t",user[t].money);
		printf("״̬Ϊ��%s\n",user[t].status);
	}

	printf("\n\n");
}

int main()
{
	int h;

	memset(user,0,sizeof(user));

	while(1)
	{
		ShowMenu_1();

		printf("��ѡ����Ӧ�˵��");
		scanf("%d",&h);
		printf("\n\n");

		switch(h)
		{
		case 1:Authoring(user);
			break;

		case 2:Enroll(user);
			break;

		case 3:printf("��лʹ�ã��ټ���\n");
			return 0;

		case 4:Show_accounts(user);
			break;
		}
	}
}

