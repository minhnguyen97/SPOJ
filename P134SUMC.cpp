//Thu 20 Apr 2017 11:12:29 PM ICT 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define FOR(i,b,e) for(int i = b;i <= e;i++)
#define MAX_N 20001
#define MAX_M 50001

int n,m;
bool chuaxet[MAX_N];
vector<vector<int> > adj(MAX_N);

void Init() {
	cin >> n >> m;
	int u,v;
	FOR(i,1,m) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void InitSeen() {
	FOR(i,1,n) chuaxet[i] = true;
}
void BFS(int u) {
	queue<int> q;
	chuaxet[u] = false;
	q.push(u);
	while(!q.empty()){
		int s = q.front();
		q.pop();
		for(int t =0;t < adj[s].size();t++) {
			if(chuaxet[adj[s].at(t)]) {
				q.push(adj[s].at(t));
				chuaxet[adj[s].at(t)] = false;
			}
		}
	}
}
int ConectedGraph() {
	int solt = 0;
	FOR(i,1,n) {
		if(chuaxet[i])  {
			solt++;
			BFS(i);
		}
	}
	return solt;
}
void process() {
	FOR(i,1,n) {
		InitSeen();
		chuaxet[i] = false;
		int res = ConectedGraph();
		cout << res<<endl;
	}
}
int main(){
	Init();
	process();
	return 0;
}
