/*
The program must accept a string S (consisting of only vowels and consonants) and an integer N. The program must print the number of substring values of length N which have 
equal count of vowels and consonants.
Note: The value of N is always even.

Boundary Condition(s):
1 <= Length of S <= 10^5
2 <= N <= Length of S

Input Format:
The first line contains S.
The second line contains N.

Output Format:
The first line contains an integer representing the number of substring values of length N which have equal count of vowels and consonants.

Example Input/Output 1:
Input:
havenhelljoysorrow
4

Output:
5

Explanation:
There are 5 substring values of length N=4 which have equal count of vowels and consonants.
have, aven, enhe, oyso, orro.

Example Input/Output 2:
Input:
skillrack
2

Output:
4
*/
#include<stdio.h>
#include<stdlib.h>

int isVowel(char ch)
{
    ch=tolower(ch);
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}
int main()
{
    char s[100001];
    int n, len, balance=0, count=0;
    scanf("%s %d",s,&n);
    len=strlen(s);
    for(int index=0;index<n;index++)
    {
        balance+=isVowel(s[index])?1:-1;
    }
    if (balance==0)
        count++;
    for(int index=n;index<len;index++)
    {
        balance+=(isVowel(s[index])?1:-1) + (isVowel(s[index-n])?-1:1);
        if (balance==0)
            count++;
    }
    printf("%d",count);

}
