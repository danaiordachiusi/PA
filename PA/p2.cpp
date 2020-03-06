#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class p2 {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, k;
	vector<int> v;

	void read_input() {
		ifstream fin("p2.in");
		fin >> n;
		fin >> k;
		for (int i = 1, e; i <= n; i++) {
			fin >> e;
			v.push_back(e);
		}
		fin.close();
	}

	int get_result(){
		
		int dp[n][k + 1] = {};
		int i, j;
		sort(v.begin(), v.end(),std::greater<int>()); //sortare descrescatoare
		dp[0][0] = v[0];	//caz de baza
		for(i = 1;i < n;i++) {
			if(i % 2 == 0) 
				dp[i][0] = dp[i - 1][0] + v[i];		//pozitie para
			else
				dp[i][0] = dp[i - 1][0] - v[i];		//pozitie impara
		}

		for(j = 1;j <= k; j++) 
			for(i = j;i < n; i++){ 
				if((i - j) % 2 == 0)
					dp[i][j] = max(dp[i - 1][j] + v[i],		//se aduna deoarece
									dp[i - 1][j - 1]);		//e mutarea lui
				else										//Tuzgu
					dp[i][j] = max(dp[i - 1][j] - v[i],		//se scade la
									dp[i - 1][j - 1]);		//mutarea Ritzei

			}
				
		

		return dp[n - 1][k];

	}
		void print_output(int result) {
		ofstream fout("p2.out");
		fout << result;
		fout.close();
	}
};

int main() {
	p2 task;
	task.solve();
	return 0;
}