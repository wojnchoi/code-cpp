//failed
#include<stdio.h>

#define ROW 5
#define COL 5

int matrix[ROW][COL] = 
    { 
        {0 , 0 , 3 , 0 , 4 }, 
        {0 , 0 , 5 , 7 , 0 }, 
        {0 , 0 , 0 , 0 , 0 }, 
        {0 , 2 , 6 , 0 , 0 },
		{0 , 0 , 2 , 0 , 5 }, 
    };
int matrix2[ROW][COL] = 
    { 
        {1 , 0 , 3 , 0 , 4 }, 
        {0 , 0 , 4,  0, 0 }, 
        {0 , 0 , 0 , 0 , 0 }, 
        {0 , 2 , 5 , 0 , 0 },
		{0 , 0 , 1 , 0 , 4 }, 
    };
    
int **add_matrix(int A[ROW][COL], int B[ROW][COL])
{
	int **C;
	for(int i=0; i<ROW;i++)
		for(int j=0; j<COL; i++)
			C[i][j] = A[i][j] + B[i][j];
		
	return C;
}

void print_matrix(int **M)
{
	for(int i=0; i<ROW; i++){
		for(int j=0;j<COL; j++)
			printf(" %d ", M[i][j]);
		printf("\n");
	}

}
int main()
{
	int **result = add_matrix(matrix, matrix2);
	print_matrix(result);
	return 0;
}
