#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long ul;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


vector<vi> adj;
vector<bool> visited;

void dfs(int start){
	visited[start]=true;
	for(auto u:adj[start]) {
		if(!visited[u]) dfs(u);
	}
	return;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin>>n>>m;

adj=vector<vi>(n);
for(int i=0; i<m; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	adj[a].pb(b);
	adj[b].pb(a);
}

visited=vector<bool>(n,false);
dfs(0);

bool connected=true;
for(int i=0; i<n; i++){
	if(!visited[i]) {
		cout<<i+1<<endl;
		if(connected) connected=false;
	}
}
if(connected) cout<<"Connected";

return 0;	
}
