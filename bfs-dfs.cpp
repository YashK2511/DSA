#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct node {
    public:
    node *next;
    int data;
};

class matrix {
    public:
    int n, i, j, p, t, c, c1, count;
    int M[30][30];
    int visited[10], visited1[10];
    node *list[10], *nnode, *temp;
    int n1, m;

    // Adjacency List Creation
    void create() {
        cout << "\nEnter the number of vertices: ";
        cin >> n1;

        for (int i = 0; i < n1; i++) {
            cout << "\nEnter the name of vertex: ";
            list[i] = new node;
            cin >> list[i]->data;
            list[i]->next = NULL;

            cout << "\nEnter the number of vertices connected to " << list[i]->data << ": ";
            cin >> m;

            temp = list[i];
            for (int j = 0; j < m; j++) {
                nnode = new node;
                cout << "Enter the name of vertex connected to " << list[i]->data << ": ";
                cin >> nnode->data;
                nnode->next = NULL;
                temp->next = nnode;
                temp = nnode;
            }
        }

        // Display adjacency list
        for (int i = 0; i < n1; i++) {
            temp = list[i];
            cout << temp->data << "->";
            temp = temp->next;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Adjacency Matrix Creation
    void read() {
        cout << "\nEnter the number of vertices: ";
        cin >> n;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                M[i][j] = 0;
            }
        }

        cout << "\nEnter how many paths exist: ";
        cin >> p;

        for (i = 1; i <= p; i++) {
            cout << "\nEnter the source city: ";
            cin >> c;
            cout << "Enter the destination city: ";
            cin >> c1;
            M[c][c1] = M[c1][c] = 1;
        }
    }

    // Display Adjacency Matrix
    void display() {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
    }

    // DFS Traversal using Adjacency Matrix
    void DFS() {
        stack<int> s1;
        int v1, v2, v3;
        int flag;
        count = 0;

        cout << "\nEnter the starting vertex: ";
        cin >> v1;

        s1.push(v1);
        visited[v1] = 1;

        while (!s1.empty()) {
            v2 = s1.top();
            cout << v2 << " ";
            count++;
            flag = 0;

            for (v3 = 1; v3 <= n; v3++) {
                if (v1 != v3 && M[v2][v3] != 0 && visited[v3] == 0) {
                    s1.push(v3);
                    visited[v3] = 1;
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                s1.pop();
            }

            if (count == n)
                break;
        }
    }

    // BFS Traversal using Adjacency List
    void BFS() {
        queue<int> q;
        int v, s;

        cout << "\nEnter the starting vertex: ";
        cin >> v;

        q.push(v);
        visited1[v] = 1;

        while (!q.empty()) {
            s = q.front();
            cout << s << " ";
            q.pop();

            for (int i = 0; i < n1; i++) {
                if (list[i]->data == s) {
                    temp = list[i]->next;
                    break;
                }
            }

            while (temp != NULL) {
                if (visited1[temp->data] == 0) {
                    q.push(temp->data);
                    visited1[temp->data] = 1;
                }
                temp = temp->next;
            }
        }
    }
};

int main() {
    matrix m;
    cout << "\n****** Adjacency Matrix ******";
    m.read();
    m.display();

    // Initialize visited arrays
    for (int i = 1; i <= 10; i++) {
        m.visited[i] = 0;
    }

    for (int i = 0; i < 10; i++) {
        m.visited1[i] = 0;
    }

    m.count = 1;

    cout << "\nDFS Traversal: ";
    m.DFS();

    cout << "\n****** Adjacency List ******";
    m.create();

    cout << "\nBFS Traversal: ";
    m.BFS();

    return 0;
}

