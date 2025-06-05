#include <iostream>
#include <vector>
#include <algorithm> // Importante para el sort
#include <queue>

using namespace std;

// Era solo usar estructuras asdasdaa
struct Tri {
    int beneficio = 0;
    int limite = 0; 
    int indice = 0;
};


int comparar(const Tri& TAREA1, const Tri& TAREA2) {

    return TAREA1.limite < TAREA2.limite;

}

void maximizarBeneficio(vector<Tri>& TAREAS) {

    sort(TAREAS.begin(), TAREAS.end(), comparar);

    priority_queue<int> HEAP;
    int beneficio_total = 0;
    vector<int> RESPUESTAS;

    
    for (Tri tarea : TAREAS) {
        if (HEAP.size() < tarea.limite) {

            HEAP.push(tarea.beneficio);
            beneficio_total = beneficio_total + tarea.beneficio;

        }
        else if (!HEAP.empty() && HEAP.top() < tarea.beneficio) {
            beneficio_total -= HEAP.top();
            HEAP.pop();
            HEAP.push(tarea.beneficio);
            beneficio_total += tarea.beneficio;
        }
    }

    cout << beneficio_total << endl;

    while (!HEAP.empty()) {
        for (int i = 0; i < TAREAS.size(); i++) {
            if (HEAP.top() == TAREAS[i].beneficio) {
                cout << TAREAS[i].indice << " ";
            }
        }
        HEAP.pop();
    }
    cout << endl;
}

int main() {

    int n = 0;
    cin >> n;
    int b = n;

    vector<Tri> tareas(b);
    for (int i = 0; i < b; i++) {
        cin >> tareas[i].beneficio >> tareas[i].limite;
        tareas[i].indice = i + 1;
    }

    maximizarBeneficio(tareas);
    return 0;


}