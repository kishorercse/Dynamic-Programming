/*
The program must accept an integer matrix of size R*C and an integer K as the input. The program must print the sum of integers in the K*K sub-matrix which has the maximum sum 
S among the all possible K*K sub-matrices in the given R*C matrix as the output.

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
4 5
10 20 80 40 55
90 50 90 200 65
60 20 5 20 12
10 50 40 60 8
3

Output:
567

Explanation:
The 3*3 sub-matrix which has the maximum sum is given below.
80 40 55
90 200 65
5 20 12

Example Input/Output 2:
Input:
4 3
4 9 8
2 4 4
5 7 3
7 6 8
2

Output:
25
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX(x,y) ((x>y)?x:y)

int main()
{
    int R, C, K;
    scanf("%d%d",&R,&C);
    int rowSum[R][C+1], maxSum=INT_MIN;
    for(int row=0;row<R;row++)
    {
        rowSum[row][0]=0;
    }
    for(int row=0;row<R;row++)
    {
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
            maxSum=MAX(sum,maxSum);
        }
    }
    printf("%d",maxSum);
}
