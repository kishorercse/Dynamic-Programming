"""
The number of rows R and columns C of a matrix are passed as the input. The cell values (represented by integers) of the matrix is also passed as the input. The program must 
print the number of ways W to traverse from the top left cell of the matrix to the bottom right cell of the matrix passing only through the cells having odd integer values. 
From any given cell, the movement can be either to the right cell or the bottom cell.

Boundary Condition(s):
2 <= R, C <= 100

Input Format:
The first line contains R and C separated by a space.
The next R lines contain C integer values each separated by a space.

Output Format:
The first line contains the number of ways W.

Example Input/Output 1:
Input:
3 3
1 5 3
2 5 7
7 8 9

Output:
2

Explanation:
The two possible paths are 1->5->3->7->9 and 1->5->5->7->9

Example Input/Output 2:
Input:
5 5
21 81 5 29 21
84 52 73 95 21
70 83 99 11 63
19 45 22 27 59
67 69 96 80 61

Output:
9
"""
r,c=map(int,input().split())
m=[list(map(int,input().split())) for _ in range(r)]
dp=[[0]*c for i in range(r)]
if m[0][0]%2!=0:
    dp[0][0]=1
for i in range(1,r):
    if m[i][0]%2!=0:
        dp[i][0]=dp[i-1][0]
for i in range(1,c):
    if m[0][i]%2!=0:
        dp[0][i]=dp[0][i-1]
for i in range(1,r):
    for j in range(1,c):
        if m[i][j]%2!=0:
            dp[i][j]=dp[i-1][j]+dp[i][j-1]
print(dp[r-1][c-1])
