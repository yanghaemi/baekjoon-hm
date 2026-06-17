// package swea.D6.영준이의진짜BFS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
    static int N;
    static List<Integer>[] list;
    static long answer;

    // lca를 위한 배열들
    static int[] depth;
    static int[][] parent;  // parent[k][i] : i번 노드의 2^k 번째 부모
    static int maxK;        // N에 따른 최대 2^k 승수 (log2(N))

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());
        for(int tc=1;tc<=T;tc++){

            N = Integer.parseInt(br.readLine());

            answer = 0; // 거리
            list = new ArrayList[N+1];

            for(int i=1;i<=N;i++){
                list[i] = new ArrayList<>();
            }

            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i=2;i<=N;i++){
                int parent = Integer.parseInt(st.nextToken());
                list[parent].add(i); 
                list[i].add(parent);
            }

            // LCA 초기화 세팅
            // N이 100,000일 때 2^17 = 131,072이므로 maxK는 17 정도면 충분
            maxK=0;
            while((1<<maxK)<=N){
                maxK++;
            }
            depth = new int[N+1];
            parent = new int[maxK+1][N+1];
            // -----------

            List<Integer> order = bfs( 1);

            // 희소 배열 완성하기 (2^k 번째 부모들을 dp로 채우기)
            // i의 2^k번째 부모는 -> (i의 2^(k-1)번째 부모)의 2^(k-1)번째 부모와 같다.
            for(int k=1; k<= maxK; k++){
                for(int i=1;i<=N;i++){
                    parent[k][i] = parent[k-1][parent[k-1][i]];
                }
            }

            for (int i = 0; i < order.size() - 1; i++) {
                int from = order.get(i);
                int to = order.get(i + 1);

                int lca = getLCA(from, to); // 공통 조상 찾기
                
                // 트리에서의 두 노드 간 최단 경로 길이: (A 깊이) + (B 깊이) - 2 * (LCA 깊이)
                answer += (depth[from] + depth[to] - 2 * depth[lca]);
            }

            System.out.println("#"+tc+" "+answer);
        }
    }

    private static int getLCA(int a, int b) {
        // 1. 무조건 b가 더 깊은 노드가 되도록 스왑
        if (depth[a] > depth[b]) {
            int temp = a; a = b; b = temp;
        }

        // 2. 두 노드의 깊이(depth) 맞추기 (b를 위로 끌어올림)
        // 예: 깊이 차이가 7이면, 4칸 점프 -> 2칸 점프 -> 1칸 점프 순으로 맞춰집니다.
        for (int k = maxK; k >= 0; k--) {
            if (depth[b] - depth[a] >= (1 << k)) {
                b = parent[k][b];
            }
        }

        // 깊이를 맞췄는데 둘이 똑같은 노드라면 그 노드가 바로 LCA
        if (a == b) return a;

        // 3. 깊이는 같은데 노드가 다르다면? 조상이 달라지는 순간까지 동시에 위로 점프!
        for (int k = maxK; k >= 0; k--) {
            if (parent[k][a] != parent[k][b]) {
                a = parent[k][a];
                b = parent[k][b];
            }
        }

        // 반복문이 끝나면 두 노드는 LCA 바로 직전 자식 위치에 나란히 서게 됩니다.
        // 따라서 바로 한 칸 위 부모(2^0)를 반환하면 그게 최소 공통 조상입니다.
        return parent[0][a];    
    }

    static List<Integer> bfs(int idx){
        Queue<Integer> q = new ArrayDeque<>();

        boolean[] visited = new boolean[N+1];
        List<Integer> order = new ArrayList<>();
        q.offer(idx);
        visited[idx] = true;
        depth[idx] = 0;

        while(!q.isEmpty()){
            int cur = q.poll();

            order.add(cur);

            for(int next : list[cur]){
                if(visited[next]) continue;
                depth[next] = depth[cur] + 1; // 내 깊이 + 1
                parent[0][next] = cur;

                q.offer(next);
                visited[next] = true;

            }
        }

        return order;
    }
}
