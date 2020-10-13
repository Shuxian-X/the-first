#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-6;

int main()
{
	double a, b, c, det, x1, x2;
	printf("Please enter three coefficients:\n"); //��ʾ����һԪ���η��̵ĸ������
	scanf("%lf%lf%lf", &a, &b, &c);
	det = b * b - 4 * a*c; /*���㦤*/
	cout << det << endl;
	if (det > 0) {
		x1 = (-b + sqrt(det)) / 2.0 / a; /*���㹫ʽ*/
		x2 = (-b - sqrt(det)) / 2.0 / a;
		printf("x1 = %.2lf, x2 = %.2lf\n", x1, x2);
	}
	else if (fabs(det) < eps) {  //�������жϦ��Ƿ�Ϊ 0 
		x1 = -b / 2.0 / a;
		printf("x1 = x2 = %.2lf\n", x1);
	}
	else {  /*����� < 0 , ���㸴����*/
		double t1;
		x1 = -b / 2.0 / a;
		t1 = sqrt(-det) / 2.0 / a;
		printf("x1 = %.2lf+%.2lfi, x2 = %.2lf-%.2lfi\n", x1, t1, x1, t1);
	}
	system("pause");
	return 0;
}