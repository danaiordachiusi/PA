#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class p3 {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	vector<int> v;

	void read_input() {
		ifstream fin("p3.in");
		fin >> n;
		for (int i = 1, e; i <= n; i++) {
			fin >> e;
			v.push_back(e);
		}
		fin.close();
	}

	long long get_result(){
		long long r;
		int i = 0, j = 0;
		long long dp[n][n];
		int k, s = 0, dif;

		for(k = 0;k < n; k++) {
			s += v[k];		//suma elementelor din vector
		}

		for(i = 0;i < n; i++) {
			dp[i][i] = v[i];		//caz de baza
		}
		for(i = 0;i  < n - 1; i++) {
			dp[i][i + 1] = max(v[i],v[i +  1]);		//caz de baza
		}

		for(dif = 2;dif < n;dif++) {
			for(i = 0, j = i + dif;; i++, j++) {
				if(j == n)	break;		//conditia de oprire

				dp[i][j] = max (v[i] + min(dp[i + 2][j], dp[i + 1 ][j - 1]),
								v[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
			}

		}

		r = s - dp[0][n - 1];

		return dp[0][n - 1] - r;
	}
		void print_output(long long result) {
		ofstream fout("p3.out");
		fout << result;
		fout.close();
	}
};

int main() {
	p3 task;
	task.solve();
	return 0;
}