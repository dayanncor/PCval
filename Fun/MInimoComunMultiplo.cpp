int gcd(int a, int b) {
	return b==0? a : gcd(b,a%b);
}
int lcm(int a, int b) {
	return a/gcd(a,b)*b;
}
main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	while(cin>>s) {
		if(s=="*")break;
		int m = 1;
		int n = s.size();
		vector<int>no;
		for(int i=0; i<n; i++) {
			int num = i+1;
			if(s[i]=='Y') {
				m = lcm(m, num);
			} else {
				no.push_back(num);
			}
		}
		bool yes = true;
		for(int i : no) {
			if(m%i==0) {
				yes = false;
				break;
			}
		}
		if(yes) {
			cout<<m<<endl;
		} else {
			cout<<"-1"<<endl;
		}
	}
	return 0;
}
