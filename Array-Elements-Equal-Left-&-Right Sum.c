/*
The program must accept N integers and print the integers where the sum of all integers present to it's left is equal to the sum of all integers present to it's right.
Note: At least one such integer is always present in the given integers.

Boundary Condition(s):
3 <= N <= 10^6
-10^6 <= Each integer value <= 10^6

Input Format:
The first line contains N.
The second line contains N integers separated by a space.

Output Format:
The first line contains the integer value(s) separated by a space.

Example Input/Output 1:
Input:
6
7 2 1 -5 5 5

Output:
-5 5

Example Input/Output 2:
Input:
4
20 10 50 30

Output:
50
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N;
    scanf("%d",&N);
    int arr[N+1];
    unsigned long long int sum[N+2], totalSum;
    sum[0]=sum[N+1]=0;
    for(int index=1;index<=N;index++)
    {
        scanf("%d",&arr[index]);
        sum[index]=sum[index-1]+arr[index];
    }
    totalSum=sum[N];
    for(int index=1;index<=N;index++)
    {
        if (sum[index-1]==totalSum-sum[index])
        {
            printf("%d ",arr[index]);
        }
    }  

}
