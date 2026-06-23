// package 01Knapsack;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) throws IOException{
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));

        int T=Integer.parseInt(br.readLine());

        for(int tc=1;tc<=T;tc++){

            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            int[] V = new int[N+1];
            int[] C = new int[N+1];

            for(int i=1;i<=N;i++){
                st = new StringTokenizer(br.readLine());

                V[i] = Integer.parseInt(st.nextToken());
                C[i] = Integer.parseInt(st.nextToken());
            }

            int[][] dp = new int[N+1][K+1];

            for(int i=1;i<=N;i++){
                for(int w=1;w<=K;w++){
                    if(w >= V[i]){
                        dp[i][w] = Math.max(dp[i-1][w], dp[i-1][w-V[i]]+C[i]);
                    }else{
                        dp[i][w] = dp[i-1][w]; // i번째 부피보다 한계 부피가 작으면 i번째는 못 선택하는 걸로 확정
                    }
                }
            }

            System.out.println("#"+tc+" "+dp[N][K]);
        }
    }
}
