#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
        int V, N, f[35000], v[35000], w[35000], i, j;

        scanf("%d%d", &N, &V);
        for(i=0; i<N; i++){
                scanf("%d%d", &v[i], &w[i]);
        }
        for(i=0; i<N; i++){
                for(j=V; j>=v[i]; j--){
                        f[j] = max(f[j], f[j-v[i]]+w[i]);
                }
        }
        printf("%d\n", f[V]);

        return 0;
}