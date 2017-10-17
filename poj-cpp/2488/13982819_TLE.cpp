#include <stdio.h>
#include <string.h>

int mapp[30][30];
char road[1000];

int dfs(int h, int w, int a, int b);

int main()
{
        int nCase, h, w, n = 1, l;

        scanf("%d", &nCase);
        while(nCase--){
                scanf("%d%d", &w, &h);
                memset(mapp, 0, sizeof(mapp));
                printf("Scenario #%d:\n", n++);
                if(w==1 && h==1){
                        printf("A1\n");
                        continue;
                }
                if(!dfs(h, w, 0, 0))printf("impossible\n");
                else printf("A1%s\n", road);

        }

        return 0;
}

int dfs(int h, int w, int y, int x)
{
        int a, b, l;
        char str[10];

        mapp[y][x] = 1;
        a = y-2;
        b = x-1;
        if(a>=0 && b>=0 && !mapp[a][b]){
                sprintf(str, "%c%d", a+'A', b+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }

        a = y-2;
        b = x+1;
        if(a>=0 && b<w && !mapp[a][b]){
                sprintf(str, "%c%d", a+'A', b+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }

        a = y-1;
        b = x-2;
        if(a>=0 && b>=0 && !mapp[a][b]){
                sprintf(str, "%c%d", a+'A', b+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }

        a = y-1;
        b = x+2;
        if(a>=0 && b<w && !mapp[a][b]){
                sprintf(str, "%c%d", a+'A', b+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }

        a = y+1;
        b = x-2;
        if(a<h && b>=0 && !mapp[a][b]){
                sprintf(str, "%c%d", a+'A', b+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }

        a = y+1;
        b = x+2;
        if(a<h && b<w && !mapp[a][b]){
                sprintf(str, "%c%d", a+'A', b+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }

        a = y+2;
        b = x-1;
        if(a<h && b>=0 && !mapp[a][b]){
                sprintf(str, "%c%d", a+'A', b+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }

        a = y+2;
        b = x+1;
        if(a<h && b<w && !mapp[a][b]){
                sprintf(str, "%c%d", a+'A', b+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }


        mapp[y][x] = 0;
        l = strlen(road);
        if(l/2 == h*w-1) return 1;
        return 0;
}













