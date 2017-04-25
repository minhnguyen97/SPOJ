#include <iostream>
#include <climits>

#define MAX 501
#define FOR(i,b,e) for(int i = b;i <= e;i++)
#define DFOR(i,j,b,e) for(int i = b;i <= e; i++) for(int j = b; j <= e;j++)
using namespace std;

int n,m,w;
int a[MAX][MAX];
int d[MAX];
bool ok;

void Init() {
	ok = false;
	cin >> n >> m >> w;
	DFOR(i,j,1,n) a[i][j] = INT_MAX;
	FOR(i,1,m) {
		int u,v,t;
		cin >> u >> v >> t;
		if(a[u][v] > t) {
			a[u][v] = t;
			a[v][u] = t;
		}
	}
	FOR(i,1,w) {
		int u,v,t;
		cin >> u >> v >> t;
		t = t * -1;
		if(a[u][v] > t) 
			a[u][v] = t;
	}
}
void BellmanFord(int s) {
	FOR(i,1,n) d[i] = a[s][i];
	d[s] = 0;
	int k = 1;
	while(k <= n-2) {
		FOR(v,1,n) {
			if(v != s) {
				FOR(u,1,n) {
					if(a[u][v] != INT_MAX && d[v] > d[u] + a[u][v]) {
						d[v] = d[u] + a[u][v];
					}
				}
			}
		}
		k++;
	}
}
void Update(int s) {
	FOR(i,1,n) {
		if((d[i] + a[i][s]) < 0) {
			ok = true;
			break;
		}
	}
}
void Result() {
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}
void process() {
	Init();
	FOR(i,1,n) {
		BellmanFord(i);
		Update(i);
		if(ok) break;
	}
	Result();

}
int main() {
	int test;
	cin >> test;
	while(test--) {
		process();
	}
	return 0;
}