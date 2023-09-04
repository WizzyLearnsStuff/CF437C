#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int adj_dists[1001] = {-1};
	vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, false));

	int dists[1001] = {0};

	for (int i = 1; i <= n; i++) {
		cin >> dists[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj_dists[a] += dists[b];
		adj_dists[b] += dists[a];
		adj[a][b] = true;
		adj[b][a] = true;
	}

	long long int cost = 0;

	for (int i = 1; i <= n; i++) {
		int mi = 0;
		int marg = 0;

		for (int j = 1; j <= n; j++) {
			if (dists[j] == -1) continue;
			mi = dists[j];
			marg = j;
			break;
		}

		for (int j = marg + 1; j <= n; j++) {
			if (dists[j] == -1) continue;
			if (mi < dists[j]) {
				mi = dists[j];
				marg = j;
			}
		}
		
		cost += adj_dists[marg];
		adj_dists[marg] = -1;
		for (int k = 1; k <= n; k++) {
			if (adj_dists[k] == -1) continue;
			adj_dists[k] -= adj[k][marg] * dists[marg];
		}
		dists[marg] = -1;
	}

	cout << cost;
}
