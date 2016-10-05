// C program for Knight Tour problem
#include<stdio.h>
#define N 8

int sol[N][N];
int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
/* A utility function to check if i,j are valid indexes
   for N*N chessboard */
bool isSafe(int x, int y)
{
    return ( x >= 0 && x < N && y >= 0 &&  y < N && sol[x][y] == -1);
}

/* A utility function to print solution matrix sol[N][N] */
void printSolution()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

/* A recursive utility function to solve Knight Tour
   problem */
int solveKTUtil(int x, int y, int movei)
{
   int k, next_x, next_y;
   if (movei == N*N)
       return true;

   /* Try all next moves from the current coordinate x, y */
   for (k = 0; k < 8; k++)
   {
       next_x = x + xMove[k];
       next_y = y + yMove[k];
       if (isSafe(next_x, next_y))
       {
         sol[next_x][next_y] = movei;
         if (solveKTUtil(next_x, next_y, movei+1))   return true;
         else  sol[next_x][next_y] = -1;// backtracking
       }
   }
   return false;
}

/* Driver program to test above functions */
int main()
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    sol[0][0]  = 0;
    if(solveKTUtil(0, 0, 1))
        printSolution();
    else
        printf("Solution doesn't exist\n");
    return 0;
}

