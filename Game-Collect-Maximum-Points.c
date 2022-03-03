/*
A game has a board with an RxC matrix having R rows and C columns containing positive integer values as cell values. A player can start from the top-left cell and perform the
following two navigations after collecting the points in that cell.
- The player can move to the right cell.
- The player can move to the bottom cell.
The player cannot come back to the previous row or column. The player navigates until he reaches the bottom-right cell. The program must print the maximum points a player can
collect from the given RxC matrix as the output.

Boundary Condition(s):
2 <= R, C <= 50
0 <= Each integer value <= 1000

Input Format:
The first line contains R and C separated by a space.
The next R lines, each containing C integers separated by a space.

Output Format:
The first line contains the maximum points a player can collect from the given RxC matrix.

Example Input/Output 1:
Input:
4 5
4 2 9 6 1
7 9 6 5 4
5 7 3 8 8
7 4 9 9 4

Output:
53

Explanation:
The navigation of the player to collect the maximum points is given below.
4 -> 7 -> 9 -> 7 -> 4 -> 9 -> 9 -> 4
The maximum points a player can collect from the 4x5 matrix is 53 (4+7+9+7+4+9+9+4).
Hence the output is 53

Example Input/Output 2:
Input:
3 3
48 64 47
63 33 14
44 82 52

Output:
289
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX(x,y) ((x>y)?x:y)

int main()
{
    int R,C;
    scanf("%d%d",&R,&C);
    int mat[R][C];
    for(int row=0;row<R;row++)
    {
        for(int col=0;col<C;col++)
        {
            scanf("%d",&mat[row][col]);
        }
    }
    for(int row=1;row<R;row++)
    {
        mat[row][0]+=mat[row-1][0];
    }
    for(int col=1;col<C;col++)
    {
        mat[0][col]+=mat[0][col-1];
    }
    for(int row=1;row<R;row++)
    {
        for(int col=1;col<C;col++)
        {
            mat[row][col]+=MAX(mat[row][col-1],mat[row-1][col]);
        }
    }
    printf("%d",mat[R-1][C-1]);
}
