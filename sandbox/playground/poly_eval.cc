#include<iostream>

using namespace std;

typedef struct {
    int degree;
    float coef[101];
} polynomial;

typedef struct {
    int expon;
    float coef;
} polynomial2;

polynomial p1 = {3,{1,2,3}};
polynomial2 p2[101] = {{3,1}, {2,2},{1,3}};


int main()
{
    return 0;
}
//첫번째 방법과 두번째 방법으로 각각 특정한 x값에서 다항식의 값을 계산하는 함수 poly_eval(int x)을 작성해보자 