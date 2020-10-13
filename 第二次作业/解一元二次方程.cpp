#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double eps = 1e-6;

int main()
{
	double a, b, c, det, x1, x2;
	printf("Please enter three coefficients:\n"); //提示输入一元二次方程的各项参数
	scanf("%lf%lf%lf", &a, &b, &c);
	det = b * b - 4 * a*c; /*计算Δ*/
	cout << det << endl;
	if (det > 0) {
		x1 = (-b + sqrt(det)) / 2.0 / a; /*计算公式*/
		x2 = (-b - sqrt(det)) / 2.0 / a;
		printf("x1 = %.2lf, x2 = %.2lf\n", x1, x2);
	}
	else if (fabs(det) < eps) {  //浮点型判断Δ是否为 0 
		x1 = -b / 2.0 / a;
		printf("x1 = x2 = %.2lf\n", x1);
	}
	else {  /*如果Δ < 0 , 计算复数解*/
		double t1;
		x1 = -b / 2.0 / a;
		t1 = sqrt(-det) / 2.0 / a;
		printf("x1 = %.2lf+%.2lfi, x2 = %.2lf-%.2lfi\n", x1, t1, x1, t1);
	}
	system("pause");
	return 0;
}