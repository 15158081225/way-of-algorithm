#include <stdio.h>
#include <string.h>

int M, N, maps[50][50], tmp[50][50], f[50][50], minf=9999999;
int dy[5] = {0,  0, 0, 1, -1};
int dx[5] = {1, -1, 0, 0,  0};

void cal(int q);
int value(int y, int x);

int main()
{
        int i, j;

        memset(f, 0, sizeof(f));
        scanf("%d%d", &M, &N);
        for(i=0; i<M; i++) {
                for(j=0; j<N; j++) {
                        scanf("%d", &maps[i][j]);
                }
        }

        for(i=0; i<(1<<M); i++) {
                cal(i);
        }
        for(i=0; i<M; i++) {
                for(j=0; j<N; j++) {
                        if(f[i][j]==1) {
                                for(i=0; i<M; i++) {
                                        printf("%d", f[i][0]);
                                        for(j=1; j<N; j++) printf(" %d", f[i][j]);
                                        printf("\n");
                                }
                                return 0;
                        }
                }
        }
        printf("IMPOSSIBLE\n");

        return 0;
}

int value(int y, int x)
{
        int i, sum=maps[y][x];

        for(i=0; i<5; i++) {
                if(y+dy[i]>=0 && x+dx[i]<N) sum += tmp[y+dy[i]][x+dx[i]];
        }
        if(sum%2) return 1;
        else return 0;
}

void cal(int q)
{
        int i, j, res = 0;

        memset(tmp, 0, sizeof(tmp));
        for(i=0; i<M; i++) {
                if((1<<i)&q) {
                        tmp[i][N-1] = 1;
                }
        }
        for(i=N-2; i>=0; i--) {
                for(j=0; j<M; j++) {
                        if(value(j, i+1)) {
                                tmp[j][i] = 1;
                                res ++;
                        }
                }
        }
        int ok = 1;
        for(i=0; i<M; i++) {
                for(j=0; j<N; j++) {
                        if(value(i, j)) ok = 0;
                }
        }
        if(ok && res<minf) {
                minf = res;
                memcpy(f, tmp, sizeof(tmp));
        }
}



/**<

1 2
1 0



 */
