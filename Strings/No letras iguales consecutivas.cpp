//Genera un string el cual No tiene letras repetidas consecutivas y acomodado lexicograficamente (orden alfabetico)

string s;
cin>>s;
int n=s.size();
vector<int>vec(26,0); //las 26 letras del abecedario
    for (char c : s) vec[c - 'A']++;
    int maxi = *max_element(all(vec));
    if (maxi > (n + 1) / 2) { //si la cadena es impar no se puede
        cout << -1 << endl;
        return 0;
    }

    string ans = "";
    char prev = '#';

    forn(i,n){
        for (int j = 0; j < 26; j++) {
            if (vec[j] == 0) continue;
            char acu = 'A' + j;
            if (acu == prev) continue;
            vec[j]--;
            bool ban = true;
            int maxF = *max_element(all(vec));
            if (maxF > (n - i - 1 + 1) / 2) ban = false;
            vec[j]++;

            if (ban) {
                ans += acu;
                prev = acu;
                vec[j]--;
                break;
            }
        }
    }

    cout << ans << endl;
    
