/*
There are N stairs to be climbed in a building. A robot can take only S different leaps each containing certain distinct steps which are passed as the input. But T stairs are
damaged and hence the robot cannot land on those stairs. The damaged stair numbers are passed as the input. The program must print the number of way C of steps the robot can 
take to climb N stairs.

Boundary Condition(s):
1 <= N <= 50
1 <= S <= 10
1 <= T <= N

Input Format:
The first line contains N, S and T separated by a space.
The second line contains S integer values separated by a space.
The third line contains T integer values separated by a space.

Output Format:
The first line contains the C.

Example Input/Output 1:
Input:
5 2 1
2 3
2

Output:
1

Explanation:
There are 5 steps. The robot can take 2 or 3 steps at a time.
So the possible way is
3 2
(2 3 is not possible as step 2 is damaged.)

Example Input/Output 2:
Input:
10 2 3
2 3
2 4 6

Output:
2

Explanation:
The possible ways are
3 5 7 10
3 5 8 10
*/
import java.util.*;
public class Hello {

    public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt(), S=sc.nextInt(), T=sc.nextInt();
		int leaps[]=new int[S];
		for(int index=0;index<S;index++) {
		    leaps[index]=sc.nextInt();
		}
		List<Integer> damaged=new ArrayList<>();
		for(int ctr=1;ctr<=T;ctr++) {
		    damaged.add(sc.nextInt());
		}
		long ways[]=new long[N+1];
		ways[0]=1;
		for(int step=1;step<=N;step++) {
		    if (!damaged.contains(step)){
    		    for(int leapIndex=0;leapIndex<S;leapIndex++) {
    		        if (step>=leaps[leapIndex]) {
    		            ways[step]+=ways[step-leaps[leapIndex]];
    		        }
    		    }
		    }
		}
		System.out.print(ways[N]);
	}
}
