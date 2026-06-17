# 영준이의 진짜 BFS (D6)

## 문제 요약

N개의 노드로 이루어진 트리가 주어진다.  
루트(1번)에서 BFS 탐색 순서를 구하고, 연속된 두 노드 사이의 거리 합을 구하라.

> 트리에서 두 노드 A, B 사이의 거리 = `depth[A] + depth[B] - 2 * depth[LCA(A, B)]`

---

## 핵심 개념

### 희소 배열 (Sparse Table for LCA)

`parent[k][i]` = 노드 i의 **2^k번째 조상**

| k | 의미 |
|---|---|
| 0 | 바로 위 부모 (직접 조상) |
| 1 | 2번째 위 조상 (부모의 부모) |
| 2 | 4번째 위 조상 |
| k | 2^k번째 위 조상 |

**점화식:**

```
parent[k][i] = parent[k-1][ parent[k-1][i] ]
```

> i의 2^k번째 조상 = (i의 2^(k-1)번째 조상)의 2^(k-1)번째 조상

BFS로 `parent[0]`(직접 부모)과 `depth`를 채운 뒤, 위 점화식으로 나머지를 채운다.

**k의 상한:** `2^maxK > N`을 만족하는 최솟값. N ≤ 100,000이면 maxK = 17로 충분.

```java
int maxK = 0;
while ((1 << maxK) <= N) maxK++;
parent = new int[maxK + 1][N + 1];
```

---

### LCA (최소 공통 조상, Lowest Common Ancestor)

두 노드 A, B의 공통 조상 중 가장 깊은 노드.

희소 배열을 이용하면 O(log N)에 구할 수 있다.

#### 알고리즘

**1단계: 깊이 맞추기**  
더 깊은 노드를 위로 끌어올려 두 노드의 depth를 같게 만든다.

```
깊이 차이 = 7 → 4칸 점프 → 2칸 점프 → 1칸 점프
(이진수로 7 = 111₂, 즉 4+2+1)
```

```java
for (int k = maxK; k >= 0; k--) {
    if (depth[b] - depth[a] >= (1 << k)) {
        b = parent[k][b];
    }
}
```

**2단계: 같은 노드면 종료**  
깊이를 맞췄는데 a == b라면 그 노드가 LCA.

**3단계: 조상이 달라지는 순간까지 동시에 점프**  
`parent[k][a] != parent[k][b]`인 동안 두 노드를 동시에 올린다.  
반복이 끝나면 두 노드는 LCA 바로 아래에 위치.

```java
for (int k = maxK; k >= 0; k--) {
    if (parent[k][a] != parent[k][b]) {
        a = parent[k][a];
        b = parent[k][b];
    }
}
return parent[0][a]; // LCA
```

---

## 풀이 흐름

```
1. 트리 입력 (루트 = 1)
2. BFS → 탐색 순서(order) + depth + parent[0] 세팅
3. 희소 배열 완성 (parent[k][i] 채우기)
4. order의 연속된 두 노드마다 LCA 구해 거리 누적
5. 결과 출력
```

## 시간 복잡도

| 단계 | 복잡도 |
|---|---|
| BFS | O(N) |
| 희소 배열 구축 | O(N log N) |
| LCA 쿼리 (N-1회) | O(N log N) |
| **전체** | **O(N log N)** |
