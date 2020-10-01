
/*----------------头文件--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

/*----------------------------------*
	   学生信息-结构体设计
*-----------------------------------*/

typedef struct student
{
	char number[20];  //学号
	char name[20];    //姓名
	float dailyScore;   //平时成绩
	float experiScore;  //实验成绩
	float finalScore;   //期末成绩
	float generalScore; //总评成绩

}SS;


/*----------------函数定义-------------*/

//1.1手动输入学生基本数据
void readData(SS stu[], int N)
{
	printf("请按照如下格式输入学生信息：学号 姓名 平时成绩 实验成绩 期末成绩\n");
	for (int i = 0; i < N; ++i)
	{
		printf("第%d个学生:", i + 1);
		scanf("%s %s %f %f %f", stu[i].number, stu[i].name, &stu[i].dailyScore, &stu[i].experiScore, &stu[i].finalScore);
		printf("\n");
	}
	printf("------成绩录入完毕!--------\n");

}

//1.2从文件里读取学生基本数据
SS* readDataFromFile(int *N)
{
	printf("\n\n------第一步: 从文件读取学生的成绩信息--------\n\n");
	SS *stu;// 开辟新空间,存取文件中的每个学生信息
	FILE *fp = NULL;
	int count = 0;
	int index = 0;
	fp = fopen("data.txt", "r");
	//1.获取学生数目
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
	printf("学生数目为:%d\n\n", count);
	//2.给所有学生分配存储空间
	stu = (SS*)malloc(count * sizeof(SS));

	//3.读取每条学生的信息
	int i = 0;
	printf("   学号       姓名  平时成绩  实验成绩  期末成绩\n\n");
	while ((!feof(fp)))
	{
		fscanf(fp, "%s %s %f %f %f", stu[i].number, stu[i].name, &stu[i].dailyScore, &stu[i].experiScore, &stu[i].finalScore);
		printf("%s %7s %8.2f %8.2f %9.2f\n\n", stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiScore, stu[i].finalScore);
		++i;
	}
	printf("------成绩录入完毕!--------\n");
	fclose(fp);
	return stu;
}

//2.计算N个学生各自的总评成绩
void calcuScore(SS stu[], int N)
{
	printf("\n\n------第二步: 计算每个学生的总评成绩--------\n\n");
	printf("   学号      总评成绩\n\n");
	for (int i = 0; i < N; ++i)
	{
		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.2*stu[i].experiScore + 0.6*stu[i].finalScore;  //计算总成绩，公式：总成绩=0.2*平时成绩+0.2*实验成绩+0.6*期末成绩
		printf("%s %8.2f\n\n", stu[i].number, stu[i].generalScore);
	}
	printf("\n------总成绩计算完毕!--------\n");
}


//3.根据总评成绩排名
int cmpBigtoSmall(const void *a, const void *b)
{
	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);
	return (*aa).generalScore < (*bb).generalScore;
}

void sortScore(SS stu[], int N)
{
	qsort(stu, N, sizeof(SS), cmpBigtoSmall);    //C++ 自带的排序函数
}

//4.按照一定的格式输出N个学生的信息
void printOut(SS stu[], int N)
{
	printf("\n------第三步: 根据总成绩输出学生排名信息!------\n\n");
	printf("排名   学号\t   姓名  平时成绩  实验成绩 期末成绩 总评成绩\n");
	for (int i = 0; i < N; ++i)
	{
		printf("%2d   %s %7s %8.2f %8.2f %8.2f %8.2f\n", i + 1, stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiScore, stu[i].finalScore, stu[i].generalScore);
	}
	printf("\n------ 根据总成绩输出学生排名信息完毕!--------\n\n");
}



//5.查询：输入学号可查询某个学生的成绩信息
void inquiry(SS stu[], int N)
{
	printf("\n------第四步: 输入学号查询某个学生的成绩信息!------\n\n");
	printf("请输入要查询学生的学号：\n");
	char ID[20];
	scanf("%s", ID);
	for (int i = 0; i < N; ++i)
	{
		if (strcmp(stu[i].number, ID) == 0)
		{
			printf("排名   学号\t   姓名  平时成绩  实验成绩 期末成绩 总评成绩\n");
			printf("%2d   %s %7s %8.2f %8.2f %8.2f %8.2f\n", i + 1, stu[i].number, stu[i].name, stu[i].dailyScore, stu[i].experiScore, stu[i].finalScore, stu[i].generalScore);
			printf("\n------ 查询完毕!--------\n\n");
			return;
		}
	}
	printf("\n------ 该学号不存在!--------\n\n");
}



//7.分析：统计全班学生成绩的均值和标准方差，并对成绩分布简要分析
void analyse(SS stu[], int N)
{
	printf("\n------第五步: 统计全班学生成绩的均值和标准方差，并对成绩分布简要分析!------\n\n");
	float sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += stu[i].generalScore;
	}
	sum = sum / (float)N;
	printf("全班学生成绩的均值为：%.2f\n", sum);
	float variance = 0;
	for (int i = 0; i < N; ++i)
	{
		variance += (stu[i].generalScore - sum)*(stu[i].generalScore - sum);
	}
	variance = sqrt(variance / (float)N);
	printf("全班学生成绩的标准方差为：%.2f\n", variance);
	printf("\n------统计全班学生成绩的均值和标准方差，并对成绩分布简要分析完毕!--------\n");
}

/*----------------------------------*
		主函数
*-----------------------------------*/

int main()
{

	printf("******************************\n");
	printf("       学生成绩管理分析系统        \n");
	printf("******************************\n\n");

	/*-1.变量初始化-*/
	int N = 0;            //学生总数
	SS  *pstu = NULL;    //学生数组-结构体数组指针实现

	//2.读取学生信息
	pstu = readDataFromFile(&N);

	/*-3.计算学生总成绩（总成绩=0.2*平时成绩+0.2*实验成绩+0.6*期末成绩)--*/
	calcuScore(pstu, N);

	/*-4.根据学生成绩排名-*/
	sortScore(pstu, N);

	/*-5.按照排名输出学生信息-*/
	printOut(pstu, N);

	/*-6.通过学号查询学生信息-*/
	inquiry(pstu, N);

	/*-7.按照排名输出学生信息-*/
	analyse(pstu, N);

	/*-6.释放动态内存空间-*/
	free(pstu);


	system("pause");
	return 0;
}
