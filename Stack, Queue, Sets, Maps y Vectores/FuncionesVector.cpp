//tipos de vector
vector<int>name
vector<pair<int,int>name;
 //metodos de un vector
name.push_back(); //Insertar un elemento al final
name.pop_back(); //elimina el ultimo elemento
name.size(); //devuelve el tamanio del vector
name.empty(); //Retorna true si el vector esta vacio
name.clear(); //Elimina todo los elementos del vector
name.at(i); //Devuelve el valor que esta en esa posicion
name.front(); //devuelve el primer valor
name.back(); //devuelve el ultimo valor 
name.insert(pos, val); // inserta un valor en una posicion espeficica
name.erase(vec.begin() + pos); //elimina un elemento de una posicion especifica
//"vec.erase(vec.begin()+i)" y el for "for(int i = 0; i < sz(vec);)" si no se pone asi da error :(
name.erase(star,end); //elimina los elementos de ese rango
name.resize(n); //cambia el tamanio del vector a n elementos
name.assign(n,val); //Asigna n elementos con valor val
name.swap(otrovec); //Intercambia el contenido con el otrovec
begin()/end() // retorna los iteradores del inicio y final
rbegin()/rend() //Iteradores al inverso, para recorrer de atras hacia adelante
name.emplace(pos,arg); //inserta una posicion y un valor
name.emplace_back(); //Inserta valores al final, creando posiciones para este
