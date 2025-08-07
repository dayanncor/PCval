#define int int64_t

int PasarMins(const string& s){
     int n1=stoi(s.substr(0, 2)); //castea a int la sub cadena, que inicia en 0 y toma los 2 valores siguientes
     int n2=stoi(s.substr(3, 2));
     return n1*60+n2;
}
main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,in,fin;
        cin>>n>>m;
        int ans=0;
        while(n--){
            string s,e;
            cin>>s>>e;
          in=PasarMins(s);
          fin=PasarMins(e);
            ans += (fin-in);
        }
            if(ans>=m*60){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            
        }
    }
  return 0;
}
