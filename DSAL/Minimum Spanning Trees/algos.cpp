#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class MST;

class Graph{

    private:
    int graph[100][100];
    int vertices,edges;

    public:
    Graph(int v,int e);
    void create_graph();
    void display_graph();

    friend class MST;
};

class MST{

    private:
    int mst[100][100];
    int cycle[100];
    int cost;

    public:
    MST(Graph a);

    // helper functions
    int findmin(int dist[],bool selected[],Graph a);
    int find1(int a);
    void Union(int i,int j);

    // algorithms
    void kruskal(Graph a);
    void prim(Graph a);
    void display_mst(Graph a);

};

MST::MST(Graph a){
    cost = 0;
    mst[100][100] = {0};
    for(int i=0;i<a.vertices;i++){
        cycle[i] = i;
    }
}

void MST::Union(int i,int j){
    int a = find1(i);
    int b = find1(j);
    cycle[b] = a;
}

int MST::find1(int index){
    if(cycle[index] == index) return index;
    return find1(cycle[index]);
}

void MST::kruskal(Graph a){
    int v = a.vertices;
    
    while(v>1){
        int min_cost = INT32_MAX;
        int min_v1,min_v2;
        for(int i=0;i<a.vertices;i++){
            for(int j=0;j<a.vertices;j++){
                if(a.graph[i][j]!=0 and find1(i)!=find1(j) and a.graph[i][j]<min_cost ){
                    min_cost = a.graph[i][j];
                    min_v1=i;
                    min_v2 = j;
                }
            }
        }
        Union(min_v1,min_v2);
        mst[min_v1][min_v2] = min_cost;
        mst[min_v2][min_v1] = min_cost;
        v--;
    }
}

int MST::findmin(int dist[],bool selected[],Graph a){
    int min = INT16_MAX,min_index;
    for(int i=0;i<a.vertices;i++){
        if(dist[i]<min and selected[i] == false){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void MST::prim(Graph a){
    int v = a.vertices;
    int dist[v];
    bool selected[v];
    int parent[v];
    for(int i=0;i<v;i++){
        dist[i] = INT16_MAX;
        selected[i] = false;
    }
    dist[0] = 0;
    parent[0] = -1;
    while(v>1){
        int u = findmin(dist,selected,a);
        selected[u] = true;
        for(int i=0;i<a.vertices;i++){
            if(a.graph[u][i] and selected[i]==false and a.graph[u][i]<dist[i]){
                dist[i] = a.graph[u][i];
                parent[i] = u;
            }
        }
        
        v--;
    }
    for(int i=1;i<a.vertices;i++){
        mst[parent[i]][i] = a.graph[i][parent[i]];
        mst[i][parent[i]] = a.graph[i][parent[i]];
    }
}

void MST::display_mst(Graph a){
    for(int i=0;i<a.vertices;i++){
        for(int j=0;j<a.vertices;j++){
            cout<<mst[i][j]<<"  ";
        }
        cout<<endl;
    }
}

Graph::Graph(int v,int e){
    vertices = v;
    edges = e;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++)
            graph[i][j] = 0;
    }
}

void Graph::create_graph(){
    int a,b,weight;
    for(int i=0;i<edges;i++){
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"Enter first vertex: ";
        cin>>a;
        cout<<"Enter second vertex: ";
        cin>>b;
        cout<<"Enter weight of the edge: ";
        cin>>weight;
        
        if(!graph[a-1][b-1]){
            graph[a-1][b-1] = weight;
            graph[b-1][a-1] = weight;
            cout<<"Edge inserted between "<<a<<" and "<<b<<endl;
            cout<<"-------------------------------------------------------"<<endl;
        }
        else {
            cout<<"Edge already exists";
            cout<<"-------------------------------------------------------"<<endl;
        }
    }
}

void Graph::display_graph()
{
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++)
            cout<<graph[i][j]<<"  ";
        cout<<endl;
    }
}

int main(){
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"Create a graph to find mst"<<endl;
    int v1,e1;
     cout<<"-------------------------------------------------------"<<endl;
    cout<<"Enter no. of vertices and edges in the graph: ";
    cin>>v1>>e1;
    Graph a(v1,e1);
    MST b(a);
    a.create_graph();

    int c;
    while(true){
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"1. Display Graph "<<endl;
        cout<<"2. Prims algorithm "<<endl;
        cout<<"3. Kruskals algorithm "<<endl;
        cout<<"4. Display Minimum Spanning Tree "<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"Enter command: ";
        cin>>c;
        switch(c){
            case 1:
            a.display_graph();
            cout<<endl;
            break;
            case 2:
            b.prim(a);
            cout<<endl;
            break;
            case 3:
            b.kruskal(a);
            cout<<endl;
            break;
            case 4:
            b.display_mst(a);
            cout<<endl;
            break;
            case 5:
            cout<<"Exited Successfully"<<endl;
            exit(0);
        }
    }

    return 0;
}

/* Output

-------------------------------------------------------
Create a graph to find mst
-------------------------------------------------------
Enter no. of vertices and edges in the graph: 4 4
-------------------------------------------------------
Enter first vertex: 1
Enter second vertex: 2
Enter weight of the edge: 6
Edge inserted between 1 and 2
-------------------------------------------------------
-------------------------------------------------------
Enter first vertex: 1
Enter second vertex: 4
Enter weight of the edge: 5
Edge inserted between 1 and 4
-------------------------------------------------------
-------------------------------------------------------
Enter first vertex: 4
Enter second vertex: 3
Enter weight of the edge: 7
Edge inserted between 4 and 3
-------------------------------------------------------
-------------------------------------------------------
Enter first vertex: 2
Enter second vertex: 3
Enter weight of the edge: 8
Edge inserted between 2 and 3
-------------------------------------------------------
-------------------------------------------------------
1. Display Graph 
2. Prims algorithm
3. Kruskals algorithm
4. Display Minimum Spanning Tree
5. Exit
-------------------------------------------------------
Enter command: 1
0  6  0  5  
6  0  8  0
0  8  0  7
5  0  7  0

-------------------------------------------------------
1. Display Graph
2. Prims algorithm
3. Kruskals algorithm 
4. Display Minimum Spanning Tree
5. Exit
-------------------------------------------------------
Enter command: 2

-------------------------------------------------------
1. Display Graph
2. Prims algorithm
3. Kruskals algorithm
4. Display Minimum Spanning Tree
5. Exit
-------------------------------------------------------
Enter command: 4
0  6  0  5  
6  0  0  0
0  0  0  7
5  0  7  0

-------------------------------------------------------
1. Display Graph
2. Prims algorithm
3. Kruskals algorithm
4. Display Minimum Spanning Tree
5. Exit
-------------------------------------------------------
Enter command: 3
-------------------------------------------------------
1. Display Graph
2. Prims algorithm
3. Kruskals algorithm
4. Display Minimum Spanning Tree
5. Exit
-------------------------------------------------------
Enter command: 4
0  6  0  5  
6  0  0  0
0  0  0  7
5  0  7  0

-------------------------------------------------------
1. Display Graph
2. Prims algorithm
3. Kruskals algorithm
4. Display Minimum Spanning Tree
5. Exit
-------------------------------------------------------
Enter command: 5
Exited Successfully


*/