#include<iostream>
using namespace std;
class graph {
public:
    int a[10][10];
    int v[10];
    int n;
    int count;

    graph() {
        for (int i=0; i<10; i++) {
            v[i]=0;
            for (int j=0; j<10; j++) {
                a[i][j]=0;
            }
        }
        count=0;
    }

    void read() {
        int edges;
        cout<<"\nEnter number of cities (vertices): ";
        cin>>n;
        cout<<"Enter number of flights (edges): ";
        cin>>edges;

        for (int k=0; k<edges; k++) {
            int u, v, time;
            cout<<"\nEnter source city (0 to "<<n - 1<<"): ";
            cin>>u;
            cout<<"Enter destination city (0 to "<<n - 1<<"): ";
            cin>>v;
            cout<<"Enter time to travel from "<<u<<" to "<<v<<": ";
            cin>>time;

            a[u][v]=a[v][u]=time;
        }
    }

    void display() {
        cout<<"\nAdjacency Matrix:\n";
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
        }
    }

    void DFS(int i) {
        v[i]=1;
        count++;

        for (int j=0; j<n; j++) {
            if (a[i][j]!=0 && v[j]==0) {
                DFS(j);
            }
        }
    }
};

int main() {
    graph g;
    g.read();
    g.display();
    g.DFS(0);
    if (g.count==g.n)
        cout<<"\nGraph is connected.\n";
    else
        cout<<"\nGraph is not connected.\n";
    return 0;
}

