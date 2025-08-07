
/*
Usa un deque de pares cada elemento es un par (valor, cantidad).
T es el tipo generico de dato (puede ser int, long, etc).
Guarda elementos ordenados en sentido creciente con sus conteos comprimidos.
*/
template<class T> struct Queue {
    deque<pair<T, int>> q;

    void push(T x) {
        int ct = 1;
        while (sz(q) and x < q.front().first)
            ct += q.front().second, q.pop_front();
        q.emplace_front(x, ct);
    }
/*Elimina una ocurrencia del elemento mas antiguo en la cola.
Si ese valor tenia second > 1, solo decrementa el contador.
Si no, lo saca del deque completamente.*/
    void pop() {
        if (q.back().second > 1) q.back().second--;
        else q.pop_back();
    }
//Retorna el minimo valor actual en la cola que siempre esta en q.back()
    T min() { return q.back().first; }
};
