#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e4+10;
vector<pair<int,int> > G[maxn];
int inDeg[maxn];
int dp[maxn];
int n,m;
void topsort(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(inDeg[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(int i=0;i<G[tmp].size();i++){
			int v = G[tmp][i].first;
			int c = G[tmp][i].second;
			inDeg[v]--;
			if(inDeg[v]==0){
				q.push(v);
			}
			dp[v]= max(dp[v], dp[tmp] + c);
		}
		G[tmp].clear();
	}
}


int main(){
	int T;
	int u,v,c;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		memset(inDeg,0,sizeof(inDeg));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
		while(m--){
			scanf("%d%d%d",&u,&v,&c);
			G[u].push_back(make_pair(v,c));
			inDeg[v]++;
		}
		topsort();
		int maxValue=-1;
		for(int i=1;i<=n;i++){
			if(dp[i] > maxValue) maxValue = dp[i];
		}
		printf("%d\n",maxValue);	
	}
	
	return 0;
} 
