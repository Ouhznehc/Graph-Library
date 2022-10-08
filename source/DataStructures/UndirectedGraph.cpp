#include <DataStructures/UndirectedGraph.h>

UndirectedGraph:: UndirectedGraph(){};

UndirectedGraph:: ~UndirectedGraph(){};

bool UndirectedGraph::AddEdge(int vertex1, int vertex2){
    if(vertex1 == vertex2){
        bool flag = Graph::AddEdge(vertex1, vertex2);
        if(flag)trival_circle_num++;
        return flag;
    }
    else{
        return Graph::AddEdge(vertex1, vertex2) && Graph::AddEdge(vertex2, vertex1);
    }
}

bool UndirectedGraph::RemoveEdge(int vertex1, int vertex2){
    if(vertex1 == vertex2){
        bool flag = Graph::RemoveEdge(vertex1, vertex2);
        if(flag) trival_circle_num--;
        return flag;
    }
    else {
        return Graph::RemoveEdge(vertex1, vertex2) && Graph::RemoveEdge(vertex2, vertex1);
    }
}

int UndirectedGraph:: CountEdges() const {
    return (Graph::CountEdges() + trival_circle_num) / 2;
}

vector<Edge> UndirectedGraph::GetEdges() const {
    vector<Edge> ans;
    for(auto i = Edges.begin(); i != Edges.end(); i++){
        ans.push_back(*i);
        if(i->GetSource() != i->GetDestination()) i++;
    }
    return ans;
}

int UndirectedGraph::GetDegree(int vertex) const{
    if(Graph::ContainsEdge(vertex, vertex))
        return Graph::GetNeighbors(vertex).size() + 1;
    else
        return Graph::GetNeighbors(vertex).size();
}