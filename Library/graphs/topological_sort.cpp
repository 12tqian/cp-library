#include<bits/stdc++.h>

// if size of std::vector is n, then it is a DAG

std::vector<int> topo_sort(std::vector<std::vector<int>> adj) {
    int n = (int) adj.size();
    std::vector<int> in(n);
    std::vector<int> res;
    std::list<int> todo;
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            ++in[j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (!in[i]) {
            todo.push_back(i);
        }
    }
    while (!todo.empty()) {
        int x = todo.front();
        todo.pop_front();
        res.push_back(x);
        for (int nxt : adj[x]) {
            if (!(--in[nxt])) {
                todo.push_back(nxt);
            }
        }
    }
    return res;
}

int main() {
    return 0;
}
