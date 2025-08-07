
int n, a, b;
cin>>n;
cin>>a;
cin>>b;
vector<int> vec(n);
vector<int> prefix(n + 1, 0);
forn(i,n) cin>>vec[i];
// el partial realiza el prefixsum
partial_sum(all(vec), prefix.begin()+1);
// prefix[i + 1] = prefix[i] + vec[i];
set<array<int,2>> name;
//este tipo de set es un conjunto de pares ordenados de enteros, sin duplicados,
//y ordenados automaticamente.
int maxi= -1e18;
forn(i, n + 1) {
	if(i >= a) name.insert({prefix[i - a],i - a});
	if(sz(name)) maxi = max(maxi, prefix[i] - (*name.begin())[0]);
	if(i >= b) name.erase({prefix[i - b],i-b});


}
cout << maxi << endl;

   
