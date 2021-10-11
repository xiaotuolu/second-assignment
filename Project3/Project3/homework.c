#include<stdio.h>
#include<stdlib.h>

FILE *ans;
FILE *exe;

int random(int operate_range)				//生成具体范围内随机数
{
	int rani;
	
	rani = rand() % operate_range;
	return rani;
}


char oper_get(int NO)						//生成随机操作符		
{
	switch (NO)
	{
	case 0:
		return '+';
	case 1:
		return '-';
	case 2:
		return '*';
	case 3:
		return '/';
	}
}


void create_ques2(int max, int num)				//当运算符为1个时的情况
{
	int NO, exc, n=0;
	char type1;								//随机运算符
	int num1, num2;

	/*exe = fopen("Exercises.txt", "a");
	ans = fopen("Answer.txt", "a");
	*/



	NO = random(4);
	type1 = oper_get(NO);

	num1 = random(max);
	num2 = random(max);
	int num3 = num1;
	if (type1 == '/' && num2 == 0) {
		while (1) {
			type1 = oper_get(NO);
			if (type1 == '/')continue;
			else break;
		}
	}
	if (type1 == '+')
		printf("问题%d: %d + %d = %d\n", num+1, num1, num2, num1 + num2);
	else if (type1 == '-') {
		if (num2 > num1) {
			printf("问题%d: %d - %d = %d\n", num + 1, num1, num2, num2-num1);
		}
		else printf("问题%d: %d - %d = %d\n", num + 1, num1, num2, num1-num2);
	}
	else if (type1 == '*') {
		printf("问题%d: %d * %d = %d\n", num + 1, num1, num2, num1 * num2);
	}
	else if (type1 == '/') {
			if(num1==0)("问题%d: %d / %d = 0\n", num + 1, num1, num2);

			else if (num1<num2)
				printf("问题%d: %d / %d = %d / %d\n", num+1, num1, num2, num1 ,num2);
			else if(num1==num2)
				printf("问题%d: %d / %d = 1\n", num + 1, num1, num2);
			else if(num1>num2) {
				while (1) {
					num3 -= num2;
					n++;
					if (num3 == num2) {
						printf("问题%d: %d / %d = %d\n", num + 1, num1, num2, n);
						break;
						}
					else if(num3 < num2) {
						printf("问题%d: %d / %d = %d`%d/%d\n", num + 1, num1, num2, n, num3, num2);
						break;
					}
				}
			}
		}
}


	int main() 
{	
	int express_num,operate_range;
	int operate_num = rand();
	int oper_count = random(1);
	int operate_type = random(3);
	char file1[] = "Exercise.txt", file2[] = "Answer.txt";
	srand((unsigned)time(NULL));
	
	/*FILE* p;
	p = fopen("Exercise.txt", "w");
	fclose(p);
	p = fopen("Answer.txt", "w");
	fclose(p);
	*/
	printf("输入所需题目数量：");
	scanf_s("%d",&express_num);
	printf("输入数字最大范围：");
	scanf_s("%d",&operate_range);
	//random(operate_range);

	for (int i = 0; i < express_num; i++) {
		
			create_ques2(operate_range,i);
		
	}
	return 0;
	







}