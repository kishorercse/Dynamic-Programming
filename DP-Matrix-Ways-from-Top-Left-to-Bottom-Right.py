"""
The number of rows R and columns C of a matrix are passed as the input. The program must print the number of ways W to traverse from the top left cell of the matrix to the 
bottom right cell of the matrix. From any given cell, the movement can be either to the right cell or the bottom cell.

Boundary Condition(s):
2 <= R, C <= 100

Input Format:
The first line contains R and C separated by a space.

Output Format:
The first line contains the number of ways W.

Example Input/Output 1:
Input:
2 2

Output:
2

Example Input/Output 2:
Input:
3 4

Output:
10

Example Input/Output 3:
Input:
20 15

Output:
818809200
"""
r,c=map(int,input().split())
m=[[0]*c for _ in range(r)]
for i in range(c):
    m[0][i]=1
for i in range(r):
    m[i][0]=1
for i in range(1,r):
    for j in range(1,c):
        m[i][j]=m[i][j-1]+m[i-1][j]
print(m[r-1][c-1])
