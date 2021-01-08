#include<stdio.h>
#include <math.h>
typedef struct Point{
	int x;
	int y;
}Point;

void get_distance(Point p1, Point p2)
{
	double result = (p2.x - p1.x) * (p2.x - p1.x)  + (p2.y - p1.y) * (p2.y - p1.y);
	printf("%.0f\n", sqrt(result));
}
int main()
{
	Point p1 = {1,2}, p2 = {9,8};
	get_distance(p1, p2);
	return 0;
}
