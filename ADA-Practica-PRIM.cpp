#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

template<typename T>
class Graph {
    map<T, vector<pair<T, int>>> ady;

public:

    void insertEdge(const T& u, const T& v, int w = 1) {
        ady[u].emplace_back(v, w);
        ady[v].emplace_back(u, w);
    }

    void PRIM(const T& start) const {
        typedef tuple<int, T, T> ET;
        priority_queue<ET, vector<ET>, greater<ET>> PRIORITYQUEUE;
        set<T> VISITADOS;
        int W = 0;

        VISITADOS.insert(start);
        for (auto& e : ady.at(start)) {
            PRIORITYQUEUE.emplace(e.second, start, e.first);
        }

        while (!PRIORITYQUEUE.empty()) {
            ET current = PRIORITYQUEUE.top();
            PRIORITYQUEUE.pop();

            int w = get<0>(current);
            T v = get<2>(current);

            if (!VISITADOS.insert(v).second) {
                continue;
            }

            W = W + w;
            for (auto& e : ady.at(v)) {
                if (!VISITADOS.count(e.first)) {
                    PRIORITYQUEUE.emplace(e.second, v, e.first);
                }
            }
        }

        cout << "PRIM : " << W << endl;
    }
};

int main() {
    Graph<char> G;

    G.insertEdge('A', 'B', 2);
    G.insertEdge('A', 'C', 3);
    G.insertEdge('A', 'D', 3);
    G.insertEdge('B', 'C', 4);
    G.insertEdge('B', 'E', 3);
    G.insertEdge('C', 'D', 5);
    G.insertEdge('C', 'E', 1);
    G.insertEdge('C', 'F', 6);
    G.insertEdge('D', 'F', 7);
    G.insertEdge('E', 'F', 8);
    G.insertEdge('F', 'G', 9);

    G.PRIM('A');
}
