int t, c, q, y;
cin>>t;
while(t--) {
	queue<int> name;
	cin>>c;
	while(c--) {
		cin>>y;
		if(y==1) {
			cin>>q;
			name.push(q);
		}
		if(y==2) {
//verifica si esta vacio, si si, borra la cola
			if(!name.empty())
				name.pop();
		}
		if (y == 3) {
			if (!name.empty()) {
				queue<int> temp = name;
				int acu = 0;
				while (!temp.empty()) {
					acu += temp.front();
					temp.pop();
				}
				cout<<acu<<endl;
			} else {
				cout<<"Empty!"<<endl;
			}
		}
	}
}

