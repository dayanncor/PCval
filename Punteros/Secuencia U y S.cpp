 int n;
 cin>>n;
 vector <int> vec(n);
forn(i,n) cin>>vec[i];
set<int>s;
int l=0,cont=0;
int maxi=0;
forn(i,n){
    while(s.count(vec[i])){
//cuando es set, para borrar es con un name.erase()
        s.erase(vec[l++]); 
    }
        s.insert(vec[i]); 
        cont=s.size();
//toma el valor mas grande, comparando esas dos variables
     maxi= max(maxi, cont); 
    }
   cout<<maxi<<endl;

