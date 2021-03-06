#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

typedef pair<int, int> P;
char str[128][128][30];
P prev[128][128];

void print(P ans, int h)
{
        if(ans.first==0 && ans.second==0) { printf("%d\n", h); return; }
        else print(prev[ans.first][ans.second], h+1);
        printf("%s\n", str[ans.first][ans.second]);
}

int main()
{
        int A, B, C;
        queue<P> que;
        P ans = P(-1, -1);
        for(int i=0; i<16384; i++) prev[0][i] = P(-1, -1);
        scanf("%d%d%d", &A, &B, &C);
        que.push(P(0, 0));
        while(!que.empty()) {
                P t = que.front(); que.pop();
                int a = t.first, b = t.second;
                //printf("%d %d\n", a, b);
                if(t.first==C || t.second==C) { ans = t; break; }

                if(prev[A][b].first==-1 && prev[A][b].second==-1) {
                        que.push(P(A, b));
                        prev[A][b] = P(a, b);
                        strcpy(str[A][b], "FILL(1)");
                }

                if(prev[a][B].first==-1 && prev[a][B].second==-1) {
                        que.push(P(a, B));
                        prev[a][B] = P(a, b);
                        strcpy(str[a][B], "FILL(2)");
                }

                if(prev[a][0].first==-1 && prev[a][0].second==-1) {
                        que.push(P(a, 0));
                        prev[a][0] = P(a, b);
                        strcpy(str[a][0], "DROP(1)");
                }
                
                if(prev[0][b].first==-1 && prev[0][b].second==-1) {
                        que.push(P(0, b));
                        prev[0][b] = P(a, b);
                        strcpy(str[0][b], "DROP(2)");
                }

                if(prev[a>B-b?a+b-B:0][a>B-b?B:b+a].first==-1 && prev[a>B-b?a+b-B:0][a>B-b?B:b+a].second==-1) {
                        que.push(P(a>B-b?a+b-B:0, a>B-b?B:b+a));
                        prev[a>B-b?a+b-B:0][a>B-b?B:b+a] = P(a, b);
                        strcpy(str[a>B-b?a+b-B:0][a>B-b?B:b+a], "POUR(1,2)");
                }

                if(prev[b>A-a?A:a+b][b>A-a?b+a-A:0].first==-1 && prev[b>A-a?A:a+b][b>A-a?b+a-A:0].second==-1) {
                        que.push(P(b>A-a?A:a+b, b>A-a?b+a-A:0));
                        prev[b>A-a?A:a+b][b>A-a?b+a-A:0] = P(a, b);
                        strcpy(str[b>A-a?A:a+b][b>A-a?b+a-A:0], "POUR(2,1)");
                }
        }
        if(ans.first==-1 && ans.second==-1) printf("impossible\n");
        else print(ans, 0);

        return 0;
}



/**
#include <stdio.h>
#include <string.h>

int A, B, C, path[30], H;
const int maxh = 30;
int dp[100][128][128];

int dfs(int h, int a, int b)
{
        int z;
        if(a==C || b==C) return dp[h][a][b] = 1;
        if(h==H) return 0;
        if(dp[h][a][b]!=-1) return dp[h][a][b];
        path[h] = 1;
        if(dfs(h+1, A, b)) return 1;
        path[h] = 2;
        if(dfs(h+1, a, B)) return 1;
        path[h] = 3;
        if(dfs(h+1, 0, b)) return 1;
        path[h] = 4;
        if(dfs(h+1, a, 0)) return 1;
        path[h] = 5;
        if(dfs(h+1, a>B-b?a+b-B:0, a>B-b?B:b+a)) return 1;
        path[h] = 6;
        if(dfs(h+1, b>A-a?A:a+b, b>A-a?b+a-A:0)) return 1;
        return dp[h][a][b] = 0;
}

int main()
{
        scanf("%d%d%d", &A, &B, &C);
        for(H=1; H<maxh; H++) {
                memset(dp, -1, sizeof(dp));
                if(dfs(0, 0, 0)) break;
        }
        if(H==maxh) printf("impossible\n");
        else {
                printf("%d\n", H);
                for(int i=0; i<H; i++) {
                        if(path[i]==1) printf("FILL(1)\n");
                        else if(path[i]==2) printf("FILL(2)\n");
                        else if(path[i]==3) printf("DROP(1)\n");
                        else if(path[i]==4) printf("DROP(2)\n");
                        else if(path[i]==5) printf("POUR(1,2)\n");
                        else if(path[i]==6) printf("POUR(2,1)\n");
                }
        }

        return 0;
}
*/





