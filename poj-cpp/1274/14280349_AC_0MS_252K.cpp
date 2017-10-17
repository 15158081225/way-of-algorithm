#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 99999999
#define MAX_V 500

using namespace std;

struct edge {
        int to, cap, rev;
        edge(int t, int c, int r) {
                to = t; cap = c; rev = r;
        }
        edge(){}
};

vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int from, int to, int cap)
{
        G[from].push_back(edge(to, cap, G[to].size()));
        G[to].push_back(edge(from, 0, G[from].size()-1));
}

void bfs(int s)
{
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()) {
                int v = que.front(); que.pop();
                for(int i=0; i<G[v].size(); i++) {
                        edge &e = G[v][i];
                        if(e.cap>0 && level[e.to]<0) {
                                level[e.to] = level[v]+1;
                                que.push(e.to);
                        }
                }
        }
}

int dfs(int v, int t, int f)
{
        if(v==t) return f;
        for(int &i=iter[v]; i<G[v].size(); i++) {
                edge &e = G[v][i];
                if(e.cap>0 && level[v]<level[e.to]) {
                        int d = dfs(e.to, t, min(f, e.cap));
                        if(d>0) {
                                e.cap -= d;
                                G[e.to][e.rev].cap += d;
                                return d;
                        }
                }
        }
        return 0;
}

int max_flow(int s, int t)
{
        int flow = 0;
        for(;;) {
                bfs(s);
                if(level[t]<0) return flow;
                memset(iter, 0, sizeof(iter));
                int f;
                while((f = dfs(s, t, INF))>0) {
                        flow += f;
                }
        }
}

int N, M;

int main()
{
        int i, t, n;

        while(~scanf("%d%d", &N, &M)) {
                for(i=0; i<=M+N+1; i++) G[i].clear();
                for(i=1; i<=N; i++) add_edge(0, i, 1);
                for(i=1; i<=N; i++) add_edge(N+i, N+M+1, 1);
                for(i=1; i<=N; i++) {
                        scanf("%d", &n);
                        while(n--) {
                                scanf("%d", &t);
                                add_edge(i, N+t, 1);
                        }
                }
                printf("%d\n", max_flow(0, N+M+1));
        }

        return 0;
}