#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
void printVector(vector<T> nodes);
bool isFinalState(int elto, int to);
void printWay(int to, int from, int* pai);

int main()
{
// entrada
    int numOfNodes, numOfRels, from, to;
    cin >> numOfNodes;
    cin >> numOfRels;
    
    vector<int> adj[numOfNodes];
    int pai[numOfNodes];

    for (int i = 0; i < numOfRels; i++)
    {
        int place1, place2; 
        cin >> place1;
        cin >> place2;
        // cout << "relação: (" << place1 << "," << place2 << ")" << endl;
        adj[place1 - 1].push_back(place2);
        pai[place2 - 1] = place1;
        // adj[place2-1].push_back(place1);
    }

    cin >> from;
    cin >> to;
    cout << "Lead from " << from << " to " << to << endl;

// busca em largura
    queue<int> fila;
    vector<int> candidatos;
    
    candidatos.push_back(from);
    fila.push(from);
    while (!fila.empty()){
        int cursor = fila.front();
        if(isFinalState(cursor, to)){
            printVector(candidatos);
            printWay(cursor, from, pai);
            cout << "fim" << endl;
            break;
        }
        else {
            fila.pop();
            cout << "não é este elto " << cursor << endl;
            for(int j = 0 ; j < adj[cursor -1].size(); j++) {
                int next = adj[cursor -1][j];
                fila.push(next);
                candidatos.push_back(next);
            }
        }
    }



// saída
    for (int i = 0; i < numOfNodes; i++){
        cout << "adj " << i+1 << ": ";
        printVector<int>(adj[i]);
    }    

    return 0;
}

void printWay(int to, int from, int* pai) {


    int temp = to;
    stack<int> way;

    do{
        way.push(temp);
        temp = pai[to - 1];
    }while(from != from);
    way.push(temp);
    way.push(from);
    while (!way.empty()) {
        cout << way.top();
        way.pop();
        if(!way.empty()) {
            cout << "-";
        }
        
    }
    cout << endl;
    
}

bool isFinalState(int elto, int to) {
    return elto == to;
}

template <typename T>
void printVector(vector<T> nodes)
{
    for (int i = 0; i < nodes.size(); i++)
    {
        cout << nodes[i];
        if (i < nodes.size() - 1)
            cout << "-";
    }
    cout << endl;
}