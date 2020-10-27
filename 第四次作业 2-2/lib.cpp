#include "lib.h"
#pragma once
HANDLE hMain_Out;
HANDLE hMain_In;
CONSOLE_CURSOR_INFO info;
int iBeans = 0;
int level = 1;
//extern short wall[17][24];
short wall[17][24] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	 0,-1,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
	 0,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,-1,0,0,0,0,0,-1,-1,-1,0,0,
	 0,-1,0,0,0,-1,0,0,0,0,0,0,0,-1,0,0,0,0,0,-1,0,0,0,0,
	 0,-1,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,0,-1,0,-1,-1,-1,-1,-1,-1,-1,0,0,
	 0,-1,0,0,-1,0,-1,0,0,0,0,-1,0,-1,-1,-1,0,0,0,0,0,0,0,0,
	 0,-1,-1,-1,-1,-1,-1,0,0,0,0,-1,0,0,0,-1,0,0,0,0,0,0,0,0,
	 0,-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,0,
	 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,0,0,-1,0,0,0,0,
	 0,0,0,0,0,0,-1,0,0,0,0,0,0,0,-1,0,-1,0,0,-1,0,0,0,0,
	 0,0,0,0,0,0,-1,0,0,0,0,0,0,0,-1,0,-1,-1,-1,-1,0,-1,-1,0,
	 0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,-1,0,0,
	 0,0,0,0,0,-1,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,-1,0,0,
	 0,0,-1,-1,-1,-1,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,
	 0,-1,-1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,
	 0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
/**********************************
* ����:
* �ж��û���ǽ��ײ��Ե�ʳ��
***********************************/
int IsKnock(WALL *pWall, BODY *pBody, FOOD *pFood, int TYPE)
{
	if (KNOCK_WALL == TYPE)
	{
		int i;
		for (i = 0; i < pWall->len; ++i)
		{
			if (IsOver(pBody->pos, pWall->pos[i], KNOCK_WALL))
				return 1; //��ǽ��ײ
		}
	}
	else if (KNOCK_FOOD == TYPE)
	{
		int i;
		for (i = 1; i <= pFood->len; ++i)
		{
			if (IsOver(pFood->pos[i], pBody->pos, KNOCK_WALL))
				return i; //��ʳ����ײ
		}
	}
	return 0;
}
/**********************************
* ����:
* �û��ƶ�
***********************************/
int Move(FOOD *pFood, WALL *pWall, BODY *pBody)
{
	BODY prePos = *pBody;
	// POS prePos = pBody->pos;
	int iKey = GetKey();
	if (-1 == iKey) //�û��˳�
		return -1;
	if (iKey)
	{
		pBody->Direction = iKey + 4;
		iKey = 0;
	}
	if (0 == iKey)
	{
		if (DIRECTION_UP == pBody->Direction)
			--pBody->pos.y;
		else if (DIRECTION_DOWN == pBody->Direction)
			++pBody->pos.y;
		else if (DIRECTION_LEFT == pBody->Direction)
			--pBody->pos.x;
		else if (DIRECTION_RIGHT == pBody->Direction)
			++pBody->pos.x;
	}

	if (IsKnock(pWall, pBody, pFood, KNOCK_WALL))
	{
		*pBody = prePos;
		return 0;
	}
	int ix = IsKnock(pWall, pBody, pFood, KNOCK_FOOD);
	if (ix)
	{
		++iBeans;
		//ɾ�����Ե���ʳ��
		int i;
		for (i = ix; i <= (pFood->len - 1); ++i)
			pFood->pos[i] = pFood->pos[i + 1];
		--(pFood->len);
		if (0 == pFood->len) //�������
		{
			++level;
			return 1;
		}
	}
	Print(&prePos.pos, PRINT_CLEAN); //��ɾ����һ�����
	Print(&pBody->pos, PRINT_BODY);
	return 0;
}
/**********************************
* ����:
* �ж�2���Ƿ��غ�
***********************************/
int IsOver(POS pos1, POS pos2, int TYPE)
{
	if (KNOCK_WALL == TYPE) //pos1,the body. pos2,the wall
		if ((pos1.x == pos2.x && pos1.y == pos2.y) || (pos2.x + 1 == pos1.x && pos2.y == pos1.y))
			return 1;
	return 0;
}
/**********************************
* ����:
* ����ǽ
***********************************/
void MakeWall(WALL *pWall)
{
	int x, y;
	int ix = 0;
	for (x = 0; x <= 16; ++x)
	{
		for (y = 0; y <= 23; ++y)
		{
			if (0 == wall[x][y])
			{
				pWall->pos[ix].x = 2 * y;
				pWall->pos[ix].y = x;
				Print(&pWall->pos[ix++], PRINT_WALL);
			}
		}
	}
	pWall->len = ix; //����ǽ������
}
/**********************************
* ����:
* ��ɳ�ʼ������
***********************************/
void Init(FOOD *pFood, WALL *pWall, BODY *pBody, HALL *pHall)
{
	//�õ�����̨��׼����������
	hMain_Out = GetStdHandle(STD_OUTPUT_HANDLE);
	hMain_In = GetStdHandle(STD_INPUT_HANDLE);
	//���ع��
	GetConsoleCursorInfo(hMain_Out, &info);
	info.bVisible = FALSE;
	SetConsoleCursorInfo(hMain_Out, &info);
	//��ʼ���ṹ��
	pFood->len = 0;
	pWall->len = 0;
	pHall->len = 0;
	//�ı����̨��С
	system("mode con cols=50 lines=21");
	//���Ƚṹ�帳ֵ
	int x, y;
	int ix = 0;
	for (x = 0; x < 17; ++x)
	{
		for (y = 0; y < 24; ++y)
		{
			if (wall[x][y]) //��ǽ
			{
				pHall->pos[ix].x = 2 * y;
				pHall->pos[ix++].y = x;
			}
		}
	}
	pHall->len = ix;
	pBody->pos.x = 2;
	pBody->pos.y = 1;
	pBody->Direction = DIRECTION_DOWN;
	printf("%d %d\n", pHall->pos[0].x, pHall->pos[0].y);
	//���ʳ��
	int i;
	MakeFood(pHall, pFood);
	for (i = 1; i <= 7; ++i)
	{
		Print(&pFood->pos[i], PRINT_FOOD, i);
	}
}
/**********************************
* ����:
* �õ��û�����
***********************************/
int GetKey()
{
	if (GetAsyncKeyState(VK_UP))
		return KEY_UP;
	if (GetAsyncKeyState(VK_DOWN))
		return KEY_DOWN;
	if (GetAsyncKeyState(VK_LEFT))
		return KEY_LEFT;
	if (GetAsyncKeyState(VK_RIGHT))
		return KEY_RIGHT;
	if (GetAsyncKeyState(VK_ESCAPE))
		return -1; //�û��˳�
	return 0;//�û�û����Ч����
}
/**********************************
* ����:
* ��ɴ�ӡ����
***********************************/
void Print(POS *p, int TYPE, int ix)
{
	COORD pos;
	pos.X = p->x;
	pos.Y = p->y;
	SetConsoleCursorPosition(hMain_Out, pos);
	if (PRINT_WALL == TYPE)
		printf("��");
	else if (PRINT_FOOD == TYPE)
		printf("%d", ix);
	else if (PRINT_BODY == TYPE)
		printf("\1");
	else if (PRINT_CLEAN == TYPE)
		printf(" ");
}
/**********************************
* ����:
* ��ʾ�ȼ� ��ʣ�ඹ����
***********************************/
void ShowScore(BODY *pBody, FOOD *pFood)
{
	COORD pos;
	pos.X = 0;
	pos.Y = 18;
	SetConsoleCursorPosition(hMain_Out, pos);
	printf("\tBeans left : %d | pos : x=%d,y=%d\n", pFood->len, pBody->pos.x, pBody->pos.y);
	printf("\t\tLevel : %d", level);
	// for(int i = 1 ; i <= pFood->len ; ++i)
	//  printf("(x=%d,y=%d)",pFood->pos[i].x,pFood->pos[i].y);
}
/**********************************
* ����:
* ����ʳ��
***********************************/
void MakeFood(HALL *pHall, FOOD *pFood)
{
	srand((unsigned)time(NULL));
	int tot;
	for (tot = 1; tot <= 7; ++tot)
	{
		int ixFood = rand() * pHall->len / RAND_MAX;
		pFood->pos[tot].x = pHall->pos[ixFood].x;
		pFood->pos[tot].y = pHall->pos[ixFood].y;
	}
	pFood->len = 7;
}