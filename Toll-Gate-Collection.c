/*
There is a national highway which is of length N kilometers. K toll gates are currently present in the highway. But due to a recent court order, the government can collect fee
only at toll gates which are separated by more than D kilometers. The distance of these K toll gates from the starting point and the fee collected in each of these K toll gates
are passed as input. The program must print the maximum revenue that the government can collect in a one way trip (from start to ending point).

Boundary Condition(s):
5 <= N <= 1000
1 <= D <= 1000
2 <= K <= 100
1 <= Fee collected at each toll gate<= 500.

Input Format:
The first line contains N and D separated by a space.
The second line contains K.
The third line contains the distance in kilometers from the starting point for the K toll gates, with the values separated by a space.
The fourth line contains the fee collected at the K toll gates, with the values separated by a space.

Output Format:
The first line will contain the the maximum revenue that can be collected from start to end.

Example Input/Output 1:
Input:
200 50
5
60 70 120 130 140
50 70 50 30 20

Output:
100

Explanation:
There are 5 tollgates present at 60, 70, 120, 130 and 140 kms respectively.
As the tollgates should be separated by more than 50kms, the maximum revenue will be obtained when the tollgates at 60th km and 120th km are selected as the total revenue is 
50+50 = Rs.100.
The tollgates at 70th and 120th kms cannot be chosen to give 70+50 = Rs.120 revenue as they are not separated by more than 50 kms.

Example Input/Output 2:
Input:
200 40
5
60 70 120 130 180
50 70 50 30 20

Output:
140

Explanation:
There are 5 tollgates present at 60, 70, 120, 130 and 180 kms respectively.
As the tollgates should be separated by more than 40 kms, the maximum revenue will be obtained when the tollgates at 70th km, 120th km and 180th km are selected as the total 
revenue is 70+50+20 = Rs.140.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a>b)?a:b)
int main()
{
    int N, D, K;
    scanf("%d%d%d",&N,&D,&K);
    int dist[K], fee[K], revenue[N+1];
    for(int index=0;index<K;index++)
    {
        scanf("%d",&dist[index]);
    }
    for(int index=0;index<K;index++)
    {
        scanf("%d",&fee[index]);
    }
    int diff=D+1, tollIndex=0;
    revenue[0]=0;
    for(int km=1;km<=N;km++)
    {
        if (dist[tollIndex]==km)
        {
            if (km<=diff)
            {
                revenue[km]=MAX(revenue[km-1],fee[tollIndex]);
            }
            else
            {
                revenue[km]=MAX(revenue[km-1],fee[tollIndex]+revenue[km-diff]);
            }
            tollIndex++;
            if (tollIndex==K)
            {
                break;
            }
        }
        else
        {
            revenue[km]=revenue[km-1];
        }
    }
    printf("%d",revenue[dist[K-1]]);
    
}
