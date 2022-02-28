/*
The program must accept a matrix of size R*C. The matrix contains only 1's and 0's. The cell value 1 indicates the presence of a path. The cell value 0 indicates the presence
of a stone (i.e., no path). The movement from one cell to another can be to the right or bottom directions. The program must print yes if there is a path from the top left cell
to the bottom right cell and also the number of paths available. Else the program must print no as the output.

Boundary Condition(s):
2 <= R, C <= 15

Input Format:
The first line contains R and C separated by a space.
The next R lines, each contains C integers separated by a space.

Output Format:
The first line contains the string value "yes" followed by the number of paths available or the string value "no".

Example Input/Output 1:
Input:
4 5
1 1 1 1 0
0 1 0 1 1
1 1 0 1 0
1 1 1 1 1

Output:
yes 2

Explanation:
There are 2 paths from the top left cell to the bottom right cell.
The path 1 is highlighted below.
1 1 1 1 0
0 1 0 1 1
1 1 0 1 0
1 1 1 1 1
The path 2 is highlighted below.
1 1 1 1 0
0 1 0 1 1
1 1 0 1 0
1 1 1 1 1

Example Input/Output 2:
Input:
4 5
1 1 1 1 0
0 1 0 1 1
1 1 0 1 1
1 1 1 1 1

Output:
yes 4

Example Input/Output 3:
Input:
4 5
1 1 1 1 0
0 1 0 0 1
1 1 0 1 1
1 1 0 1 1

Output:
no
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int mat[r][c], path[r][c];
    for(int row=0;row<r;row++)
    {
        for(int col=0;col<c;col++)
        {
            scanf("%d",&mat[row][col]);
            path[row][col]=0;
        }
    }
    for(int col=0;col<c;col++)
    {
        if (mat[0][col]==0)
            break;
        path[0][col]=1;
    }
    for(int row=1;row<r;row++)
    {
        if (mat[row][0]==0)
            break;
        path[row][0]=1;
    }
    for(int row=1;row<r;row++)
    {
        for(int col=1;col<c;col++)
        {
            if (mat[row][col]==1)
                path[row][col]=path[row-1][col]+path[row][col-1];
        }
    }
    if (path[r-1][c-1]==0)
        printf("no");
    else
        printf("yes %d",path[r-1][c-1]);

}
