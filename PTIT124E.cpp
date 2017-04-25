#include <iostream>
#include <queue>
#define MAX 1001
#define FOR(i,b,e) for(int i = b; i<= e;i++)

using namespace std;

int k,n,m;
int A[MAX][MAX] = {0};

bool chuaxet[MAX];
bool appoint[MAX];
int p[MAX];

void Init() {
	cin >> k >> n >> m;
	FOR(i,1,k) cin >> p[i];
	FOR(i,1,m) {
		int a,b;
		cin >> a >> b;
		A[a][b] =1;
	}
	FOR(i,1,n) {
		chuaxet[i] = true;
		appoint[i] = true;
	}
}
void ReInit() {
	FOR(i,1,n) chuaxet[i] = true;
}

void Update() {
	FOR(i,1,n) if(chuaxet[i]) appoint[i] = false;
}
void Result() {
	int count = 0;
	FOR(i,1,n) if(appoint[i]) count++;
	cout << count;
}
void BFS(int u) {
	ReInit();
	chuaxet[u] = false;
	queue<int> q;
	q.push(u);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		FOR(t,1,n) {
			if(A[v][t] && chuaxet[t]) {
				q.push(t);
				chuaxet[t] = false;
			}
		}
	}
}
void process(){
	Init();
	FOR(i,1,k) {
		BFS(p[i]);
		Update();
	}
	Result();
}
int main() {
	process();
	return 0;
}