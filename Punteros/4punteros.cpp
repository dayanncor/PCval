//aplicacion de pairs y 4 punteros
	int n, x;
    bool des=false;
	cin >> n >> x;
    map<int,pair<int,int>>mp;
	vector<pair<int,int>> vec(n);
	forn(i, n){
         cin >> vec[i].first;
        vec[i].second= i+1;
    }
    sort(vec.begin(), vec.end());
    forn(i,n){
        for(int j=(i+1); j < n ; j++){
            if(mp.count(x-vec[i].first-vec[j].first)){
                auto a=vec[i].second;
                auto b=vec[j].second;
                /*se utiliza el first y second, para referise a las posiciones
                del pair, first 1, second 2*/
                auto c=mp[x-vec[i].first-vec[j].first].second;
                auto d=mp[x-vec[i].first-vec[j].first].first;

                if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d){
                    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                    des=true;
                return 0;
                }
             }
            mp[vec[i].first+vec[j].first]={vec[i].second,vec[j].second};
        }
    }
        if(des==false){
            cout<<"-1"<<endl;
    }
