int t;
	string es,col;
	cin>>t;
	set<pair<string, string>>sets;
	for(int i=0; i<t; i++){
	    cin>>es;
	    cin>>col;
	    sets.insert({es,col});
	}
	cout<<sets.size()<<endl;
