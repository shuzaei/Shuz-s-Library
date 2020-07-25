vector<pair<char, vector<ll>>> Trie;
void trie_init(vector<string> T) {
    Trie.push_back({'0', {}});
    rep(i, T.size()) {
        ll id = 0;
        rep(j, T[i].size()) {
            each(k, Trie[id].second) {
                if (Trie[k].first == T[i][j]) {
                    id = k;
                    goto next;
                }
            }
            Trie[id].second.push_back(Trie.size());
            id = Trie.size();
            Trie.push_back({T[i][j], {}});
        next:;
        }
        Trie[id].second.push_back(Trie.size());
        Trie.push_back({'0', {i}});
    }
}

vector<ll> find(string S) {
    vector<ll> V;
    ll id = 0;
    rep(i, S.size()) {
        each(j, Trie[id].second) {
            if (Trie[j].first == S[i]) {
                id = j;
                goto success;
            }
        }
        break;
    success:;
        each(j, Trie[id].second) {
            if (Trie[j].first == '0') {
                V.push_back(Trie[j].second[0]);
            }
        }
    }
    return V;
}