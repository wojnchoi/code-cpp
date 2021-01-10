#include<stdio.h>

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
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a)
{
	SparseMatrix b;
	
	int bindex;
	b.rows = a.rows;
	b.cols = a.cols;
	b.terms = a.terms;
	
	if(a.terms >0) {
		bindex = 0;
		for(int c = 0; c<a.cols;c++){
			for(int i=0; i<a.terms;i++)
			{
				if(a.data[i].col == c) {
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].val = a.data[i].val;
					bindex++;
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a)
{
	printf("=================\n");
	for(int i=0;i<a.terms;i++) {
		printf("(%d, %d, %d) \n", a.data[i].row,a.data[i].col,a.data[i].val);
	}
	printf("=================\n");
}

int main()
{
	SparseMatrix m = {{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},
						6,6,7};
						
	SparseMatrix result = matrix_transpose2(m);
	matrix_print(result);
	return 0;
}














