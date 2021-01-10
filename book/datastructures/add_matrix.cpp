//failed
#include<stdio.h>
#include<stdlib.h>

#define MAX_TERMS 100

typedef struct {
	int row;
	int col;
	int val;
} element;

typedef struct {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
} Matrix;
int getterm(Matrix A, Matrix B)
{
	int terms=0;
	for(int i=0; i<A.rows;i++)
		for(int j = 0; j < A.cols; j++)
		{
			if(A.data[i].col != B.data[j].col && A.data[i].row != B.data[j].row)
				terms++;
			else if(A.data[i].col == B.data[j].col && A.data[i].row == B.data[j].row)
				terms++;
		}
	return terms;
}
Matrix add_matrix(Matrix A, Matrix B)
{
	Matrix C;
	int index=0;
	if(A.rows != B.rows || A.cols != B.cols || A.terms != B.terms){
		fprintf(stderr, "error\n");
		exit(1);
	} else {
		C.rows = A.rows;
		C.cols = A.cols;
		C.terms = getterm(A, B);
			printf("%d", C.terms);
		for(int i=0; i < C.terms; i++) {
			for(int j=0; j<C.cols;j++) {
				if(A.data[index].val == 0) {
					C.data[index].val = B.data[index].val;
					C.data[index].col = B.data[index].col;
					C.data[index].row = B.data[index].row;
				} else if(B.data[index].val == 0){
					C.data[index].val = A.data[index].val;
					C.data[index].col = A.data[index].col;
					C.data[index].row = A.data[index].row;
				} else {
					C.data[index].val = A.data[index].val + B.data[index].val;
					C.data[index].col = A.data[index].col;
					C.data[index].row = A.data[index].row;
				}
				index++;
			}
		}
	}
	return C;
}
void print_matrix(Matrix m)
{
	printf("===========\n");
	for(int i=0;i<m.terms;i++)
		printf("(%d %d %d) \n", m.data[i].row, m.data[i].col,m.data[i].val);
	printf("===========\n");
}
int main()
{
	Matrix s1 = {{  {0,3,7},
					{1,0,9},
					{1,5,8},
					{3,0,6},
					{3,1,5},
					{4,5,1},
					{5,2,2}},
					6,
					6,
					7};
	
	Matrix s2 = {{  {0,0,5},
					{1,0,4},
					{1,4,8},
					{2,0,6},
					{3,5,5},
					{4,5,6},
					{5,2,3}},
					6,
					6,
					7};					
	
	Matrix result = add_matrix(s1, s2);
	print_matrix(result);

	return 0;
}
