#include<bits/stdc++.h>
using namespace std;

void forwardDFS(vector<int>* graph, bool* visited, stack<int>& finishOrder, int n, int start){
    
    // Mark start as visited.
    visited[start] = true;
    vector<int> currAdjList = graph[start];
    
    for(int i=0; i<currAdjList.size(); i++){
        int adjNode = currAdjList[i];
        if(!visited[adjNode]){
            forwardDFS(graph, visited, finishOrder, n, adjNode);
        }
    }
    
    finishOrder.push(start);
}

void backwardDFS(vector<int>* graph, bool* visited, int n, int start){
    
    // Mark start as visited.
    visited[start] = true;
    vector<int> currAdjList = graph[start];
    
    for(int i=0; i<currAdjList.size(); i++){
        int adjNode = currAdjList[i];
        if(!visited[adjNode]){
            backwardDFS(graph, visited, n, adjNode);
        }
    }
}

int countComponents(vector<int>* graph, int n){
    // KosaRaju's strongly connected Components.
    
    // Forward DFS.
    bool* visited = new bool[n]();
    stack<int> finishOrder;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            forwardDFS(graph, visited, finishOrder, n, i);
        }
    }
    
    delete[] visited; // delete old visited array.
    
    // Backward DFS.
    bool* newVisited = new bool[n]();
    int countOfComponents = 0;
    
    while(finishOrder.size() > 0){
        
        // pick the top element and run DFS on it. 
        int currentNode = finishOrder.top();
      
        
        if(!newVisited[currentNode]){
            backwardDFS(graph, newVisited, n, currentNode);
            countOfComponents++;
        }
          finishOrder.pop();
    }
     delete[] newVisited;
    
    return countOfComponents;
}

int dominos(){
    int n, m;
    cin >> n >> m;
    
    // Directed graph.
    vector<int>* graph = new vector<int>[n];
   
    
    // Get edges.
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        
        graph[x-1].push_back(y-1); // 0 - indexed.
       // Since directed graph need KosaRaju.
    }
        
    int components = countComponents(graph, n);
    graph->clear();
    return components;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        cout << dominos() <<endl;
    }

	return 0;
}