#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
//��ʶ�û����µķ����
#define KEY_UP    WM_USER + 1
#define KEY_DOWN   WM_USER + 2
#define KEY_LEFT   WM_USER + 3
#define KEY_RIGHT   WM_USER + 4
//��ʶ�û���ǰ�˶�����
#define DIRECTION_UP  WM_USER + 5
#define DIRECTION_DOWN  WM_USER + 6
#define DIRECTION_LEFT  WM_USER + 7
#define DIRECTION_RIGHT  WM_USER + 8
//��ʶҪ��ӡ��Ԫ������
#define PRINT_WALL   WM_USER + 9
#define PRINT_FOOD   WM_USER + 10
#define PRINT_BODY   WM_USER + 11
#define PRINT_CLEAN   WM_USER + 12
#define KNOCK_WALL   WM_USER + 13
#define KNOCK_FOOD   WM_USER + 14
struct POS
{
	int x;
	int y;
};
struct WALL
{
	POS pos[9999];
	int len;
};
struct FOOD
{
	POS pos[8];
	int len;
	int IsHidden;
};
struct BODY
{
	POS pos;
	int Direction;
};
struct HALL {
	POS pos[200];
	int len;
};
void Init(FOOD *pFood, WALL *pWall, BODY *pBody, HALL *pHall);
//����һЩ��ʼ������
void Print(POS *pos, int TYPE, int ix = 0);
//��ɴ�ӡ����
void MakeWall(WALL *pWall);
//����ǽ
void MakeFood(HALL *pHall, FOOD *pFood);
//����ʳ��
int Move(FOOD *pFood, WALL *pWall, BODY *pBody);
//�û��ƶ�
void ShowScore(BODY *pBody, FOOD *pFood);
//��ʾ�ȼ� ��ʣ�ඹ����
int IsOver(POS pos1, POS pos2, int TYPE);
//�ж�2���Ƿ��غ�
int IsKnock(WALL *pWall, BODY *pBody, FOOD *pFood, int TYPE);
//�ж��Ƿ�ײǽ���Ե�����
int GetKey();
//�õ��û�����