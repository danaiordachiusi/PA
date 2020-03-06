#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


class p1 {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	vector<int> v;

	void read_input() {
		ifstream fin("p1.in");
		fin >> n;
		for (int i = 1, e; i <= n; i++) {
			fin >> e;
			v.push_back(e);
		}
		fin.close();
	}
	int get_result() {
		sort(v.begin(),v.end());	//sortarea vectorului
		int t = 0,r = 0;
		int i;
		for(i = v.size() - 1;i >= 0;i -=2 ) {	//incepe de la ultimul element
			t += v[i];		//Scorul lui Tuzgu
			r += v[i - 1];	//Scorul Ritzei

		}
		int dif = t - r;	//diferenta de scor

		return dif;
	}

	void print_output(int result) {
		ofstream fout("p1.out");
		fout << result;
		fout.close();
	}
};

int main() {
	p1 task;
	task.solve();
	return 0;
}