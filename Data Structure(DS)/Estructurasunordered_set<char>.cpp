/* Este codigo por medio del unordered_set, elimina todas las vocales y la letra 'y' (mayúsculas y minúsculas).
Convierte todas las letras restantes a minúsculas.
Ante cada letra restante, pone un punto . delante. */

    string s,axu="";
    cin>>s;
    unordered_set<char> let = {'a', 'o', 'y', 'e', 'u', 'i','A', 'O', 'Y', 'E', 'U', 'I'};
                 for(char x: s){
                     if(let.find(x) == let.end()){
             axu += '.';
            axu += tolower(x);
                      }
               
}
  cout<<axu<<endl;
  return 0;
}
