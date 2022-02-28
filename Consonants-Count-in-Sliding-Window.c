/*
The program must accept an integer K and a string S containing only alphabets as the input. The program must print the count of consonants in each sliding window of size K in
the string S as the output.

Boundary Condition(s):
1 <= K <= Length of S <= 10^5

Input Format:
The first line contains K.
The second line contains S.

Output Format:
The first line contains the count of consonants in each sliding window of size K in the string S.

Example Input/Output 1:
Input:
3
pineapple

Output:
2 1 1 1 2 3 2

Explanation:
The sliding window size K = 3.
1st window is pin -> 2 consonants
2nd window is ine -> 1 consonant
3rd window is nea -> 1 consonant
4th window is eap -> 1 consonant
5th window is app -> 2 consonants
6th window is ppl -> 3 consonants
7th window is ple -> 2 consonants

Example Input/Output 2:
Input:
2
PROGRAMMING

Output:
2 1 1 2 1 1 2 1 1 2
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
    int k;
    char s[100001];
    scanf("%d %s",&k,s);
    int len=strlen(s), count=0;
    for(int index=0;index<k;index++)
    {
        if (!isVowel(s[index]))
        {
            count++;
        }
    }
    printf("%d ",count);
    for(int index=k;index<len;index++)
    {
        if (!isVowel(s[index-k]))
            count--;
        if (!isVowel(s[index]))
            count++;
        printf("%d ",count);
    }

}
