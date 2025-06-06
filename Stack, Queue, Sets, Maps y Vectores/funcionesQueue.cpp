//Tipos de queue
queue<int>name;
priority_queue<int>name2; //Trabaja con valores maximos
priority_queue<int, vector<int>, greater<int>> name; //trabaja con valores minimos
deque<int>name;
queue<pair<int, deque<int>>> name;
queue<pair<int, list<int>>> name;

//Funciones para queue
name.push(x);     // Agrega al final
name.pop();        // Elimina el primero
name.front();      // Primer elemento
name.back();       // ultimo elemento
name.empty();      // Verifica si esta vacia
name.size();       // Cantidad de elementos

//Funciones para priority_queue
name2.push(5);
name2.push(8);
name2.push(3);
name2.top();       // Retorna el mayor (8)
name2.pop();       // Elimina el mayor
 
//Funciones para el deque
name3.push_back(1);    // Al final
name3.push_front(2);   // Al inicio
name3.pop_back();      // Elimina al final
name3.pop_front();     // Elimina al inicio
name3.front();         // Primer elemento
name3.back();          // Último elemento
name3[0];              // Acceso directo por índice
