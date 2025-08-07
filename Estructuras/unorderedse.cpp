/*
contar cuántos valores distintos hay en una lista de enteros, desordenados. 
*/
main() {
    int t,x;
  cin>>t;
  unordered_set<int>set;
     for(int i = 0; i < t; i++){
        cin>>x;
        set.insert(x);
 
}
cout<<set.size()<<endl;
}
