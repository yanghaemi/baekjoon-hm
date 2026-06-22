package 공통조상;

import java.io.*;
import java.util.*;

public class Solution{
    static int maxK;
    static List<Integer>[] list;
    static int[] depth;
    static int[][] parent;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for(int tc=1;tc<=T;tc++){

            StringTokenizer st = new StringTokenizer(br.readLine());
            int V = Integer.parseInt(st.nextToken());
            int E = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());


            list = new List[V+1];
            depth = new int[V+1];
            
            maxK = 14;  // 2^14 > 10000
            parent = new int[maxK+1][V+1];

            for(int i=1;i<=V;i++){
                list[i] = new ArrayList<>();
            }

            st = new StringTokenizer(br.readLine());
            for(int i=0;i<E;i++){
                int p = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());

                list[p].add(c);
                parent[0][c] = p;
            }

            getDepth(1, V);

            // 희소배열 만들기
            for(int k=1; k <= maxK;k++){
                for(int i=1; i<=V; i++){
                    parent[k][i] = parent[k-1][parent[k-1][i]];
                }
            }

            // LCA (최소 공통 조상)

            int lca = getLCA(a, b);
            
            System.out.println("#"+tc+" "+lca+" "+getSize(lca, V));
        }
    }

    private static int getLCA(int a, int b) {
        if(depth[a] > depth[b]){
            int temp = a; a = b; b = temp;
        }

        for(int i=maxK;i>=0;i--){
            if(depth[b]-depth[a] >= (1<<i)) {
                b = parent[i][b];
            }
        }

        if(a == b) return a;

        for(int i=maxK;i>=0;i--){
            if(parent[i][a] != parent[i][b]){
                a = parent[i][a];
                b = parent[i][b];
            }
        }

        return parent[0][a];
    }
    
    static int getSize(int idx, int size) {
        Queue<Integer> q = new ArrayDeque<>();
        // boolean visited[] = new boolean[size+1];
        // visited[idx] = true;
        q.offer(idx);
        
        int cnt = 0;
        
        while(!q.isEmpty()) {
            int cur = q.poll();
            cnt ++;
            for(int next : list[cur]) {
                // if(visited[next]) continue;
                
                // visited[next] = true;
                q.offer(next);
            } 
        }
        
        return cnt;
    }

    static void getDepth(int idx, int size){
        Queue<Integer> q = new ArrayDeque<>();
        boolean visited[] = new boolean[size+1];
        visited[idx] = true;
        q.offer(idx);
        depth[idx] = 0;

        while(!q.isEmpty()){
            int cur = q.poll();
            
            for(int next : list[cur]){
                if(visited[next]) continue;

                depth[next] = depth[cur] + 1;
                visited[next] = true;
                q.offer(next);
            }
        }
    }
}