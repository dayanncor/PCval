 int acu=0,m,l,r;
    string s;
    cin>>s;
    cin>>m;
 
    int tam= s.size();
vector<int>sum(tam + 1, 0);
for (int i = 1; i < tam; i++) {
        sum[i + 1] = sum[i];
        if (s[i] == s[i - 1]) {
            sum[i + 1]++;
        }
    }
 while(m--){
        cin>>l;
        cin>>r;
            acu= sum[r] - sum[l];;
            cout<<acu<<endl;
        }
