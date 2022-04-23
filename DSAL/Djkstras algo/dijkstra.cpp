#include<bits/stdc++.h>

using namespace std;

class Graph{

    private:
    int graph[100][100];
    int vertices,edges;

    public:
    Graph(int v,int e);
    void create_graph();
    void display_graph();
    int findmin(int dist[],bool selected[]);
    void shortest_path();
};

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

int Graph::findmin(int dist[],bool selected[]){
    int min = INT16_MAX,min_index;
    for(int i=0;i<vertices;i++){
        if(dist[i]<=min and selected[i] == false){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void Graph::shortest_path(){
    int dist[vertices];
    bool selected[vertices];
    for(int i=0;i<vertices;i++){
        dist[i] = INT16_MAX;
        selected[i] = false;
    }
    dist[0] = 0;

    for(int j=0;j<vertices-1;j++){
    int u = findmin(dist,selected);
    selected[u]  = true;
    
    for(int i=0;i<vertices;i++){
        if (!selected[i] && graph[u][i] && dist[u] != INT16_MAX
                && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
    }
    }

    for(int i=0;i<vertices;i++){
        cout<<"Distance of source(1) to "<<i+1<<" is: "<<dist[i]<<endl;
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
    a.create_graph();

    int c;
    while(true){
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"1. Display Graph "<<endl;
        cout<<"2. Shortest Path"<<endl;
        cout<<"3. Exit "<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        cout<<"Enter command: ";
        cin>>c;
        switch(c){
            case 1:
            a.display_graph();
            cout<<endl;
            break;
            case 2:
            a.shortest_path();
            cout<<endl;
            break;
            case 3:
            cout<<"Exited Successfully"<<endl;
            exit(0);
            break;
        }
    }

    return 0;
}

/*

Output

-------------------------------------------------------
Create a graph to find mst
-------------------------------------------------------
Enter no. of vertices and edges in the graph: 5 7
-------------------------------------------------------
Enter first vertex: 1
Enter second vertex: 2
Enter weight of the edge: 3
Edge inserted between 1 and 2
-------------------------------------------------------
-------------------------------------------------------
Enter first vertex: 1
Enter second vertex: 3
Enter weight of the edge: 7
Edge inserted between 1 and 3
-------------------------------------------------------
-------------------------------------------------------
Enter first vertex: 3
Enter second vertex: 2
Enter weight of the edge: 1
Edge inserted between 3 and 2
-------------------------------------------------------
-------------------------------------------------------
Enter first vertex: 3 
Enter second vertex: 4
Enter weight of the edge: 2
Edge inserted between 3 and 4
-------------------------------------------------------
-------------------------------------------------------
Enter first vertex: 2
Enter second vertex: 4
Enter weight of the edge: 5
Edge inserted between 2 and 4
-------------------------------------------------------     
-------------------------------------------------------     
Enter first vertex: 2
Enter second vertex: 5
Enter weight of the edge: 1
Edge inserted between 2 and 5
-------------------------------------------------------     
-------------------------------------------------------     
Enter first vertex: 4
Enter second vertex: 5
Enter weight of the edge: 7
Edge inserted between 4 and 5
-------------------------------------------------------     
-------------------------------------------------------     
1. Display Graph
2. Shortest Path
3. Exit
-------------------------------------------------------     
Enter command: 1
0  3  7  0  0  
3  0  1  5  1
7  1  0  2  0
0  5  2  0  7
0  1  0  7  0

-------------------------------------------------------     
1. Display Graph
2. Shortest Path
3. Exit
-------------------------------------------------------     
Enter command: 2
Distance of source(1) to 1 is: 0
Distance of source(1) to 2 is: 3
Distance of source(1) to 3 is: 4
Distance of source(1) to 4 is: 6
Distance of source(1) to 5 is: 4

-------------------------------------------------------     
1. Display Graph
2. Shortest Path
3. Exit
-------------------------------------------------------     
Enter command: 3
Exited Successfully

*/