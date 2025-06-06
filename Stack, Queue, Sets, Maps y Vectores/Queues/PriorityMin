int t, c, v;
cin>>t;
  priority_queue<int, vector<int>, greater<int>> name;
while(t--){
    int mini=1e18;
    cin>>c;
    if(c==1){
        cin>>v;
        name.push(v);
    }else if(c==2){
        if(!name.empty()){
            name.pop();
        }
    }else if(c==3){
        if(!name.empty()){
        mini=min(mini, name.top());
        cout<<mini<<endl;
        }else{
            cout<<"Empty!"<<endl;
        }

    }
}
