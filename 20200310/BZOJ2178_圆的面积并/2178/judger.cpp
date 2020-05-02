#include <bits/stdc++.h>

using namespace std;

int main() {
	double att = 0;
	for(int i = 1; i <= 2; ++i) {
//		stringstream ff("sol.exe < "), stdfile;
//		ff << i; stdfile << i;
//		ff << ".in > my.out"; stdfile << ".out";
//		double tb = time(0);
//		system( ff.str().data() );		// or .str().c_str()
//		double te = time(0);
//		if(system(("fc my.out " + stdfile.str()).data())) {
//			cout << "WA on #" << i << "." << endl; 
//		} else {
//			cout << "AC on #" << i << ", time = " << (te - tb) << "ms." << endl;
//		}
		double tb = time(0);
		system("sol.exe < 1.in > 1.ans");
		double te = time(0);
		att += te - tb;
	}
	cout << (att / 2) << '\n';
	return 0;
}
