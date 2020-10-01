
/*----------------ͷ�ļ�--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

/*----------------------------------*
	   ѧ����Ϣ-�ṹ�����
*-----------------------------------*/

typedef struct student
{
	char number[20];  //ѧ��
	char name[20];    //����
	float dailyScore;   //ƽʱ�ɼ�
	float experiScore;  //ʵ��ɼ�
	float finalScore;   //��ĩ�ɼ�
	float generalScore; //�����ɼ�

}SS;


/*----------------��������-------------*/

//1.1�ֶ�����ѧ����������
void readData(SS stu[], int N)
{
	printf("�밴�����¸�ʽ����ѧ����Ϣ��ѧ�� ���� ƽʱ�ɼ� ʵ��ɼ� ��ĩ�ɼ�\n");
	for (int i = 0; i < N; ++i)
	{
		printf("��%d��ѧ��:", i + 1);
		scanf("%s %s %f %f %f", stu[i].number, stu[i].name, &stu[i].dailyScore, &stu[i].experiScore, &stu[i].finalScore);
		printf("\n");
	}
	printf("------�ɼ�¼�����!--------\n");

}

//1.2���ļ����ȡѧ����������
SS* readDataFromFile(int *N)
{
	printf("\n\n------��һ��: ���ļ���ȡѧ���ĳɼ���Ϣ--------\n\n");
	SS *stu;// �����¿ռ�,��ȡ�ļ��е�ÿ��ѧ����Ϣ
	FILE *fp = NULL;
	int count = 0;
	int index = 0;
	fp = fopen("data.txt", "r");
	//1.��ȡѧ����Ŀ
	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}
	printf("ѧ����ĿΪ:%d\n\n", count);
	//2.������ѧ������洢�ռ�
	stu = (SS*)malloc(count * sizeof(SS));

	//3.��ȡÿ��ѧ������Ϣ
	int i = 0;
	printf("   ѧ��       ����  ƽʱ�ɼ�  ʵ��ɼ�  ��ĩ�ɼ�\n\n");
	while ((!feof(fp)))
	{
		fscanf(fp, "%s %s %f %f %f", stu[i].number, stu[i].name, &stu[i].dailyScore, &stu[i].experiScore, &stu[i].finalScore);
		printf("%s %7s %8.2f %8.2f %9.2f\n\n", stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiScore, stu[i].finalScore);
		++i;
	}
	printf("------�ɼ�¼�����!--------\n");
	fclose(fp);
	return stu;
}

//2.����N��ѧ�����Ե������ɼ�
void calcuScore(SS stu[], int N)
{
	printf("\n\n------�ڶ���: ����ÿ��ѧ���������ɼ�--------\n\n");
	printf("   ѧ��      �����ɼ�\n\n");
	for (int i = 0; i < N; ++i)
	{
		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.2*stu[i].experiScore + 0.6*stu[i].finalScore;  //�����ܳɼ�����ʽ���ܳɼ�=0.2*ƽʱ�ɼ�+0.2*ʵ��ɼ�+0.6*��ĩ�ɼ�
		printf("%s %8.2f\n\n", stu[i].number, stu[i].generalScore);
	}
	printf("\n------�ܳɼ��������!--------\n");
}


//3.���������ɼ�����
int cmpBigtoSmall(const void *a, const void *b)
{
	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);
	return (*aa).generalScore < (*bb).generalScore;
}

void sortScore(SS stu[], int N)
{
	qsort(stu, N, sizeof(SS), cmpBigtoSmall);    //C++ �Դ���������
}

//4.����һ���ĸ�ʽ���N��ѧ������Ϣ
void printOut(SS stu[], int N)
{
	printf("\n------������: �����ܳɼ����ѧ��������Ϣ!------\n\n");
	printf("����   ѧ��\t   ����  ƽʱ�ɼ�  ʵ��ɼ� ��ĩ�ɼ� �����ɼ�\n");
	for (int i = 0; i < N; ++i)
	{
		printf("%2d   %s %7s %8.2f %8.2f %8.2f %8.2f\n", i + 1, stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiScore, stu[i].finalScore, stu[i].generalScore);
	}
	printf("\n------ �����ܳɼ����ѧ��������Ϣ���!--------\n\n");
}



//5.��ѯ������ѧ�ſɲ�ѯĳ��ѧ���ĳɼ���Ϣ
void inquiry(SS stu[], int N)
{
	printf("\n------���Ĳ�: ����ѧ�Ų�ѯĳ��ѧ���ĳɼ���Ϣ!------\n\n");
	printf("������Ҫ��ѯѧ����ѧ�ţ�\n");
	char ID[20];
	scanf("%s", ID);
	for (int i = 0; i < N; ++i)
	{
		if (strcmp(stu[i].number, ID) == 0)
		{
			printf("����   ѧ��\t   ����  ƽʱ�ɼ�  ʵ��ɼ� ��ĩ�ɼ� �����ɼ�\n");
			printf("%2d   %s %7s %8.2f %8.2f %8.2f %8.2f\n", i + 1, stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiScore, stu[i].finalScore, stu[i].generalScore);
			printf("\n------ ��ѯ���!--------\n\n");
			return;
		}
	}
	printf("\n------ ��ѧ�Ų�����!--------\n\n");
}



//7.������ͳ��ȫ��ѧ���ɼ��ľ�ֵ�ͱ�׼������Գɼ��ֲ���Ҫ����
void analyse(SS stu[], int N)
{
	printf("\n------���岽: ͳ��ȫ��ѧ���ɼ��ľ�ֵ�ͱ�׼������Գɼ��ֲ���Ҫ����!------\n\n");
	float sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += stu[i].generalScore;
	}
	sum = sum / (float)N;
	printf("ȫ��ѧ���ɼ��ľ�ֵΪ��%.2f\n", sum);
	float variance = 0;
	for (int i = 0; i < N; ++i)
	{
		variance += (stu[i].generalScore - sum)*(stu[i].generalScore - sum);
	}
	variance = sqrt(variance / (float)N);
	printf("ȫ��ѧ���ɼ��ı�׼����Ϊ��%.2f\n", variance);
	printf("\n------ͳ��ȫ��ѧ���ɼ��ľ�ֵ�ͱ�׼������Գɼ��ֲ���Ҫ�������!--------\n");
}

/*----------------------------------*
		������
*-----------------------------------*/

int main()
{

	printf("******************************\n");
	printf("       ѧ���ɼ��������ϵͳ        \n");
	printf("******************************\n\n");

	/*-1.������ʼ��-*/
	int N = 0;            //ѧ������
	SS  *pstu = NULL;    //ѧ������-�ṹ������ָ��ʵ��

	//2.��ȡѧ����Ϣ
	pstu = readDataFromFile(&N);

	/*-3.����ѧ���ܳɼ����ܳɼ�=0.2*ƽʱ�ɼ�+0.2*ʵ��ɼ�+0.6*��ĩ�ɼ�)--*/
	calcuScore(pstu, N);

	/*-4.����ѧ���ɼ�����-*/
	sortScore(pstu, N);

	/*-5.�����������ѧ����Ϣ-*/
	printOut(pstu, N);

	/*-6.ͨ��ѧ�Ų�ѯѧ����Ϣ-*/
	inquiry(pstu, N);

	/*-7.�����������ѧ����Ϣ-*/
	analyse(pstu, N);

	/*-6.�ͷŶ�̬�ڴ�ռ�-*/
	free(pstu);


	system("pause");
	return 0;
}
