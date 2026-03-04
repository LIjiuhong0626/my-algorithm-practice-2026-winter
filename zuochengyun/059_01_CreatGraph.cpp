#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 点的最大数量
const int MAXN = 11;
// 边的最大数量 (无向图需要 2 倍空间)
const int MAXM = 21;

// --- 1. 邻接矩阵方式 ---
int graph1[MAXN][MAXN];

// --- 2. 邻接表方式 ---
// 存储结构：vector[u] = { {v1, w1}, {v2, w2}, ... }
struct Edge {
    int to;
    int weight;
};
vector<Edge> graph2[MAXN]; //

// --- 3. 链式前向星方式 ---
// head[u] 存储节点 u 最后加入的那条边的编号
int head[MAXN];
int nxt[MAXM]; // next 是 C++ 关键字，建议改用 nxt[i] 意思是编号为i的边的下一个边 编号为几
int to[MAXM];// to[i] 编号为i的边指向的点
int weight[MAXM];
int cnt;

/**
 * 初始化图结构
 */
void build(int n) {
    // 邻接矩阵清空
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            graph1[i][j] = 0;
        }
    }
    // 邻接表清空
    for (int i = 0; i <= n; i++) {
        graph2[i].clear();
    }
    // 链式前向星清空
    cnt = 1;
    fill(head, head + n + 1, 0);
}

/**
 * 链式前向星加边
 */
void addEdge(int u, int v, int w) {
    // u -> v, 权重为 w
    //cnt 就是边的编号
    nxt[cnt] = head[u]; // 现在这条边的下一个边指向
    to[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt;// 把该边的编号加入head

    cnt++;
}

/**
 * 建立有向带权图
 */
void directGraph(const vector<vector<int>>& edges) {
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        // 1. 邻接矩阵
        graph1[u][v] = w;
        // 2. 邻接表
        graph2[u].push_back({v, w});
        // 3. 链式前向星
        addEdge(u, v, w);
    }
}

/**
 * 建立无向带权图
 */
void undirectGraph(const vector<vector<int>>& edges) {
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        // 1. 邻接矩阵
        graph1[u][v] = w;
        graph1[v][u] = w;
        // 2. 邻接表
        graph2[u].push_back({v, w});
        graph2[v].push_back({u, w});
        // 3. 链式前向星
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
}

/**
 * 遍历并打印
 */
void traversal(int n) {
    cout << "邻接矩阵遍历 :" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << graph1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "邻接表遍历 :" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << "(邻居、边权) : ";
        for (auto& e : graph2[i]) {
            cout << "(" << e.to << "," << e.weight << ") ";
        }
        cout << endl;
    }

    cout << "链式前向星 :" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << "(邻居、边权) : ";
        // 核心遍历逻辑：从 head[i] 开始，沿着 nxt 指针走到底
        for (int ei = head[i]; ei > 0; ei = nxt[ei]) {// 类似链表
            cout << "(" << to[ei] << "," << weight[ei] << ") ";
        }
        cout << endl;
    }
}

int main() {
    // 示例 1: 有向带权图
    int n1 = 4;
    vector<vector<int>> edges1 = { {1, 3, 6}, {4, 3, 4}, {2, 4, 2}, {1, 2, 7}, {2, 3, 5}, {3, 1, 1} };
    build(n1);
    directGraph(edges1);
    traversal(n1);

    cout << "==============================" << endl;

    // 示例 2: 无向带权图
    int n2 = 5;
    vector<vector<int>> edges2 = { {3, 5, 4}, {4, 1, 1}, {3, 4, 2}, {5, 2, 4}, {2, 3, 7}, {1, 5, 5}, {4, 2, 6} };
    build(n2);
    undirectGraph(edges2);
    traversal(n2);

    return 0;
}