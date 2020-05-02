#include <bits/stdc++.h>

using namespace std;

int main() {
	for(int i = 1; i <= 17; ++i) {
		stringstream ff, stdfile;
		ff << "sol.exe < ";
		ff << i; stdfile << i;
		ff << ".in > my.out"; stdfile << ".out";
		double tb = time(0);
//		cout << ff.str() << '\n';
//		cout << stdfile.str() << '\n';
		system( ff.str().data() );		// or .str().c_str()
		double te = time(0);
		if(system(("fc my.out " + stdfile.str()).data())) {
			cout << "WA on #" << i << "." << endl; 
		} else {
			cout << "AC on #" << i << ", time = " << (te - tb) << "s." << endl;
		}
	}
	return 0;
}
