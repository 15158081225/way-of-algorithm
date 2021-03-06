#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int maps[110][110], dp[110][110], F, V;

int main()
{
	int i, j;

	scanf("%d%d", &F, &V);
	for(i=1; i<=F; i++) {
		for(j=1; j<=V; j++) {
			scanf("%d", &maps[i][j]);
		}
	}
	for(i=0; i<=F; i++) for(j=0; j<=V; j++) dp[i][j] = -99999;
	for(i=1; i<=F; i++) {
		for(j=1; j<=V; j++) {
			dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+maps[i][j]);
		}
	}
	printf("%d\n", dp[F][V]);

	return 0;
}