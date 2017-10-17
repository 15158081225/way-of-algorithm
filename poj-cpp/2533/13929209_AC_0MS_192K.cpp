#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    int num[2000], g[2000], d[2000], N, i, j, maxs=0;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &num[i]);
    }
    for(i=0; i<=N; i++) g[i] = 99999999;
    for(i=0; i<N; i++){
        int k = lower_bound(g+1, g+N+1, num[i])-g;
        d[i] = k;
        g[k] = num[i];
        maxs = max(maxs, d[i]);
    }
    printf("%d\n", maxs);

    return 0;
}
