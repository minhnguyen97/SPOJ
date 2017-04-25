#include <iostream>
#include <queue>

using namespace std;

#define MAX 101

#define FOR(i,b,e) for(int i = b; i <= e;i++)

int n;
int A[MAX][MAX];
bool chuaxet[MAX];

void Init() {
	FOR(i,1,n) {
		FOR(j,1,n) {
			cin >> A[i][j];
		}
	}
	FOR(i,1,n) chuaxet[i] = true;
}

void Group(int u) {
	int mem[MAX];
	int n_mem = 1;
	mem[1] = u;
	chuaxet[u] = false;
	FOR(i,1,n) {
		if(chuaxet[i]) {
			bool ok = true;
			FOR(j,1,n_mem) {
				if(A[i][mem[j]] == 1)  {
					ok = false;
					break;
				}
			}
			if(ok) {
				n_mem++;
				mem[n_mem] = i;
				chuaxet[i] = false;
			}
		}
	}
}
int Relation() {
	int group =0;
	FOR(i,1,n) {
		if(chuaxet[i]) {
			group++;
			Group(i);
		}
	}
	return group;
}


int main() {
	cin >> n;
	while(n) {
		Init();
		int s = Relation();
		if(s <= 2) cout << "YES" << endl;
		else cout << "NO" << endl;;
		cin >> n;
	}
	return 0;
}