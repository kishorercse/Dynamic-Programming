/*
The program must accept an integer matrix of size R*C and an integer K as the input. The program must print the sum of integers in the K*K sub-matrix which has the minimum sum 
S among the all possible K*K sub-matrices of the given R*C matrix as the output.

Boundary Condition(s):
2 <= R, C <= 1000
2 <= K <= R and C

Input Format:
The first line contains R and C separated by a space.
The next R lines, each containing C integers separated by a space.
The (R+2)nd line contains K.

Output Format:
The first line contains S.

Example Input/Output 1:
Input:
5 4
8 4 9 7
4 0 5 2
3 5 9 6
3 0 0 4
8 8 6 1
3

Output:
29

Explanation:
The 3*3 sub-matrix which has the minimum sum is given below.
4 0 5
3 5 9
3 0 0

Example Input/Output 2:
Input:
4 4
10 80 50 70
40 30 50 50
50 70 30 20
70 10 40 70
2

Output:
150
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MIN(x,y) ((x<y)?x:y)
int main()
{
    int R, C, K;
    scanf("%d%d",&R,&C);
    int rowSum[R][C+1], minSum=INT_MAX;
    for(int row=0;row<R;row++)
    {
        rowSum[row][0]=0;
        for(int col=1;col<=C;col++)
        {
            int temp;
            scanf("%d",&temp);
            rowSum[row][col]=temp+rowSum[row][col-1];
        }
    }
    scanf("%d",&K);
    for(int row=0;row<=R-K;row++)
    {
        for(int col=K;col<=C;col++)
        {
            int sum=0;
            for(int srow=row;srow<row+K;srow++)
            {
                sum+=rowSum[srow][col]-rowSum[srow][col-K];
            }
            minSum=MIN(sum,minSum);
        }
    }
    printf("%d",minSum);
}
