
int lis(vector<int>& a) {
    vector<int>dp;
    int b = a.size();
    forn(i, b) {
        auto it = upper_bound(all(dp), a[i]);
        if (it != dp.end()) *it = a[i];
        else dp.push_back(a[i]);
    }
    return sz(dp);
}
main(){
int n;
cin>>n;
vector<int>vec(n);
forn(i,n) cin>>vec[i];
cout<<lis(vec)<<endl;

 }
