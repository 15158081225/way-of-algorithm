#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 210;
int G[maxn][maxn], cnt, vst[maxn], V, E, pa[maxn];
int tmp[maxn], ft;

int findp(int x)
{
        return pa[x]==x ? x : pa[x] = findp(pa[x]);
}

int dfs(int u)
{
        int s = 1;
        tmp[ft++] = u;
        for(int i=1; i<=V; i++)
                if(G[u][i]) s += dfs(i);
        return s;
}

int cmp(int a, int b)
{
        return a > b;
}

int use[maxn];

void calc()
{
        sort(tmp, tmp+ft, cmp);
        ft--;
        int v = tmp[ft];
        if(vst[v]) return ;
        int cc = dfs(v) + cnt;
        while(use[cc]) cc++;
        use[cc] = 1;
        vst[v] = cc;
}

int main()
{
        int T, u, v;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &V, &E);
                int faild = 0;
                memset(vst, 0, sizeof(vst));
                memset(use, 0, sizeof(use));
                memset(G, 0, sizeof(G));
                for(int i=1; i<=V; i++) pa[i] = i;
                for(int i=0; i<E; i++) {
                        scanf("%d%d", &u, &v);
                        if(G[v][u]) continue;
                        G[v][u] = 1;
                        int x = findp(u);
                        int y = findp(v);
                        if(x!=y) {
                                pa[x] = y;
                        } else faild = 1;
                }
                if(faild) { printf("-1\n"); continue; }
                for(int i=1; i<=V; i++) {
                        if(vst[i]) continue;
                        ft = 0;
                        cnt = 0;
                        for(int j=1; j<=V; j++) if(vst[j]) cnt++;
                        tmp[ft++] = i;
                        while(ft) calc();
                }
                printf("%d", vst[1]);
                for(int i=2; i<=V; i++)
                        printf(" %d", vst[i]);
                printf("\n");
        }

        return 0;
}
