/*
A boy can have either a chocolate(C) or an ice-cream(I) on a given day. But to avoid catching cold, his mom has prevented him from having ice-cream on consecutive days. As the 
boy was adamant, his mom gave a relaxation that on every Kth day, the boy can have ice-cream even if he ate ice-cream the previous day. The program must print the number of 
ways W in which the boy can have chocolate or ice-cream over the period of N days.

Boundary Condition(s):
1 <= N <= 50
2 <= K <= 100

Input Format:
The first line contains N and K separated by a space.

Output Format:
The first line contains W.

Example Input/Output 1:
Input:
3 2

Output:
6

Explanation:
The 6 ways to have over three days are
C C C
C C I
C I C
I C C
I C I
I I C (as K=2, on the second day ice-cream can be had even on successive days)
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    long long int choc=1, ice=1, temp;
    for(int day=2;day<=n;day++)
    {
        temp=choc;
        choc=choc+ice;
        if (day%k==0)
            ice=temp+ice;
        else
            ice=temp;
    }
    printf("%lld",choc+ice);
    

}
