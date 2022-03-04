/*
There are N stairs to be climbed in a building. A robot can take only S different leaps each containing certain distinct steps which are passed as the input. But T stairs are 
slippery and hence the robot will slip to the bottom stair if it lands on a slippery stair. The slippery stair numbers are passed as the input. The program must print the 
number of ways C of steps the robot can take to climb N stairs.

Boundary Condition(s):
1 <= N <= 50
1 <= S <= 10
1 <= T <= N

Input Format:
The first line contains N, S and T separated by a space.
The second line contains S integer values separated by a space.
The third line contains T integer values separated by a space.

Output Format:
The first line contains the value of C.

Example Input/Output 1:
Input:
5 2 1
2 3
2

Output:
2

Explanation:
There are 5 steps. The robot can take 2 or 3 steps at a time.
So the possible ways are
3 2
1 2 2 (as the robot will slip to step 1 when it lands on step 2 which is slippery)

Example Input/Output 2:
Input:
6 2 1
2 3
2

Output:
3

Explanation:
The possible ways are
1 2 3 (as the robot will slip to step 1 when it lands on step 2 which is slippery)
1 3 2 (as the robot will slip to step 1 when it lands on step 2 which is slippery)
3 3
*/
import java.util.*;
public class Hello {

    public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt(), S=sc.nextInt(), T=sc.nextInt();
		List<Integer> slippery=new ArrayList<>();
		int leaps[]=new int[S];
		long ways[]=new long[N+1];
		ways[0]=1;
		for(int index=0;index<S;index++) {
		    leaps[index]=sc.nextInt();
		}
    for(int ctr=1;ctr<=T;ctr++) {
        slippery.add(sc.nextInt());
    }
    for(int step=1;step<=N;step++) {
        for(int leapIndex=0;leapIndex<S;leapIndex++) {
            if (step>=leaps[leapIndex]) {
                ways[step]+=ways[step-leaps[leapIndex]];
            }
        }
        if(slippery.contains(step)) {
            int nonSlippery=step-1;
            while(nonSlippery>0 && slippery.contains(nonSlippery)) {
                nonSlippery--;
            }
            if (nonSlippery>0) {
                ways[nonSlippery]+=ways[step];
            }
            ways[step]=0;
        }
    }
    System.out.print(ways[N]);
        
	}
}
