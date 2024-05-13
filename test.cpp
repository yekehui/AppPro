#include<iostream>
using namespace std;

const int MAX = 20;
class Map {
	bool va[MAX];
	int mat[MAX][MAX];
	int vNum;
	void DFS(int v) {
		int w, i, k;

		va[v] = true;
		sum++;

		int *adj = new int[vNum];

		for (i = 0; i < vNum; i++)
			adj[i] = -1;

		k = 0;

		for (i = 0; i < vNum; i++) {
			if (mat[v][i]) {
				adj[k++] = i;
			}
		}

		i = 0;
		for (w = adj[i++]; w >= 0; w = adj[i++]) {

			if (!va[w])
				DFS(w);
		}
	}
public:
	int sum;
	void SetMat(int vnum, int mx[MAX][MAX]) {
		int i, j;
		vNum = vnum;
		for (i = 0; i < MAX; i++) {
			for (j = 0; j < MAX; j++) {
				mat[i][j] = 0;
			}
		}

		for (i = 0; i < MAX; i++) {
			for (j = 0; j < vNum; j++) {
				mat[i][j] = mx[i][j];
			}
		}
	}
	void DFSTraverse(int v) {


		for (int i = 0; i < vNum; i++)
			va[i] = false;
		int k = 0;

		DFS(v);
	}
	int tf() {
		for (int i = 0; i < vNum; i++) {
			for (int j = 0; j < vNum; j++)
				va[j] = false;
			sum = 0;
			DFSTraverse(i);
			if (sum != vNum)
				return 0;
		}

		return 1;
	}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		int mx[MAX][MAX];
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> mx[i][j];
		Map* map = new Map();
		map->SetMat(n, mx);

		if (map->tf())
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
	return 0;
}