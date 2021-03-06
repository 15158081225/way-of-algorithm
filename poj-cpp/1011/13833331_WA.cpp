#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int low, high, n, stk[64], use[64], ok;

int dfs(int a, int nth, int s, int cnt);

int cmp(int a, int b){
    return a>b;
}

int main(){
    int i;

    while(scanf("%d", &n)!=EOF){
        if(n==0) break;

        high = 0;
        for(i=0; i<n; i++){
            scanf("%d", &stk[i]);
            high += stk[i];
        }
        sort(stk, stk+n, cmp);
        low = stk[0];
        for(i=low; i<high; i++){
            if(high%i) continue;
            memset(use, 0, 256);
            ok = 0;
            dfs(i, 0, 0, 0);
            if(ok==1) break;
        }
        printf("%d\n", i);
    }

    return 0;
}

int dfs(int a, int nth, int s, int cnt){
    int jd, t;

    if(cnt==high/a){
        ok = 1;
        return 0;
    }
    for(int i=0; i<n; i++){
        if(use[i]==1) continue;
        if(i>0 && stk[i]==stk[i-1] && use[i-1]==0) continue;
        s += stk[i];
        if(s>a){
            s -= stk[i];
            continue;
        }
        nth++;
        if(s==a){
            cnt++;
            s = 0;
            t = nth;
            nth = 0;
        }
        use[i] = 1;
        jd = dfs(a, nth, s, cnt);
        if(jd==0) return 0;
        if(s==0){
            cnt--;
            s = a-stk[i];
            nth = t-1;
            continue;
        }
        use[i] = 0;
        s -= stk[i];
        nth--;
        //if(nth==-1) return 0;
    }
    return 1;
}