//La busqueda binaria se trata de partir una cadena de numeros a la mitad y buscar un valor fijo en este de forma mas eficaz

int n, x;
cin>>n>>x;
vector<int>vec(n);
forn(i,n) cin>>vec[i];
//donde l tiene que ser un valor no valido y r el mayor posible para que tome toda la cadena
int l=-1,r=(n-1),mid=0;

while(r-l>1) {
	mid=l+(r-l)/2;
	if(x<=mid) {
		r=mid;
	} else {
		l=mid;
	}
	cout<<l<<" "<<r<<" "<<mid<<endl;
}
if(x==vec[r]) {
	cout<<"yes"<<endl;
} else cout<<"NO"<<endl;
cout<<l<<" "<<r<<endl;
