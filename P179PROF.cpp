#include <iostream> 
#include <queue>
#define MAX 10001;

#define FOR(i,b,e) for(int i = b;i<=e;i++) 
#define DFOR(i,j,b,e) for(int i = b;i<=e;i++) for(int j = b;j<=e;j++) 
using namespace std;

int n,m;
int ke[MAX][MAX];
int truoc[MAX];
bool chuaxet[MAX];
void Init() {
	cin >> n >> m;
	int u,v;
	FOR(i,j,1,n) ke[i][j] = 0;
	FOR(i,1,m) {
		cin >> u >> v;
		ke[u][v]++;
	}
	FOR(i,1,n) {
		truoc[i]= 0;
		chuaxet[i] = true;
	}
}
void ReInit() {
	FOR(i,1,n) {
		truoc[i]= 0;
		chuaxet[i] = true;
	}
}
bool LengthBFS(int s,int t) {
	queue q;
	q.push(s);
	chuaxet[s] = false;
	while(!q.empty()) {
		int u = front();
		q.pop();
		FOR(i,1,n) {
			if(chuaxet[i] && a[u][i] > 0) {
				push(i);
				a[u][i]--;
			}
		}
	}

}
int main() {

	return 0;
}