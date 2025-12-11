void dfs(int u, int p) {
    vis[u] = true;      
    for (int v : g[u]) {
      
        if (v == p) {
            // No regresar por el mismo borde por donde llegamos
            continue;
        }

        if (!vis[v]) {
            dfs(v, u);  // Exploro el hijo, ahora u es el padre borde Expansion

        } else {
           //borde de retorno
        }
    }
}
