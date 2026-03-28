
    int t;
    cin >> t;

    map<string, set<pair<int,string>>> habitats;

    while (t--) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            string habitat, name;
            int size;
            cin >> habitat >> name >> size;

            habitats[habitat].insert({size, name});
        } 
        else if (cmd == "ask") {
            string habitat;
            cin >> habitat;

            auto &s = habitats[habitat];

            auto smallest = *s.begin();
            auto largest = *s.rbegin();

            cout << smallest.second << " " << largest.second << "\n";
        }
    }

    return 0;
}
