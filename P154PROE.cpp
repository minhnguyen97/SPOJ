#include <iostream>
#include <cmath>
#include <queue>

#define MAX 51
using namespace std;

long long res;
int n,m;

bool g[MAX][MAX] = {false};
bool chuaxet[MAX];

void Init() {
	cin >> n >> m;
	int u,v; 
	for(int i = 1; i <= n;i++) chuaxet[i] = true;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		g[u][v] = true;
		g[v][u] = true;
	}
}

int BFS(int u) {
	int dem = 1;
	queue<int> q;
	q.push(u);
	chuaxet[u] = false;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for (int t = 1; t <= n; ++t){
			if(chuaxet[t] && g[v][t]) {
				dem++;
				q.push(t);
				chuaxet[t] = false;
			}
		}
	}
	return dem;
}
void process() {
	res = 1;
	for (int i = 1; i <= n; ++i)
	{
		if(chuaxet[i]) {
			int t = BFS(i);
			res *= pow(2,t-1);
		}
	}
}
void Result() {
	cout << res;
}
int main() {
	Init();
	process();
	Result();
	return 0;
}