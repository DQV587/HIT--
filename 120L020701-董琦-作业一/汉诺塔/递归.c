#include<stdio.h>
int i = 0;
int main()
{
	void hanoi(int n, char one, char two, char three);
	int n;
	printf("Please enter the number of discs:");
	scanf_s("%d", &n);
	hanoi(n, 'a', 'c', ' b');
	printf("\tTotal:%d\n", i);
	return 0;
} 
void hanoi(int n, char one, char two, char three)
{
	void move(int n, char x, char y);
	if (n == 1) move(n, one, three);
	else
	{
		hanoi(n - 1, one, three, two);
		move(n, one, three);
		hanoi(n - 1, two, one, three);
	}
}
void move(int n, char x, char y)
{
	i++;
	printf("%2d-(%2d):%c==>%c\n", i, n, x, y);
}