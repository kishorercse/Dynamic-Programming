/*
There are N stairs to be climbed in a building. A robot can take only S different leaps each containing certain distinct steps which are passed as the input. The program must
print the number of ways C of steps the robot can take to climb exactly N stairs.

Boundary Condition(s):
1 <= N <= 50
1 <= S <= 10

Input Format:
The first line contains N and S separated by a space.
The second line contains S integer values separated by a space.

Output Format:
The first line contains the C.

Example Input/Output 1:
Input:
5 2
2 3

Output:
2

Explanation:
There are 5 steps. The robot can take 2 or 3 steps at a time.
So the possible ways are
2 3 and 3 2

Example Input/Output 2:
Input:
6 2
1 5

Output:
3

Explanation:
The possible ways are
1 1 1 1 1 1
5 1
1 5
*/
import java.util.*;
public class Hello {

    public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt(), S=sc.nextInt(), leaps[]=new int[N];
		long ways[]=new long[N+1];
		ways[0]=1;
		for(int index=0;index<S;index++) {
		    leaps[index]=sc.nextInt();
		}
		for(int step=1;step<=N;step++) {
		    for(int leapIndex=0;leapIndex<S;leapIndex++) {
		        if (step>=leaps[leapIndex]) {
		            ways[step]+=ways[step-leaps[leapIndex]];
		        }
		    }
		}
		System.out.print(ways[N]);
	}
}
