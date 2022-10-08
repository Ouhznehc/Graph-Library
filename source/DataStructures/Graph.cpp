#include <DataStructures/Graph.h>

Graph::Graph(){}

Graph::~Graph(){}

int Graph::CountVertices() const {
    return Vertices.size();
}

int Graph::CountEdges() const {
    return Edges.size();
}

bool Graph::ContainsVertex(int vertex) const {
    return Vertices.count(vertex);
}

bool Graph::ContainsEdge(int vertex1, int vertex2) const {
    return Edges.count(Edge(vertex1, vertex2));
}

vector<int> Graph::GetVertices() const {
    vector<int> vertices;
    for(auto it: Vertices)
        vertices.push_back(it);
    return vertices;
}

vector<Edge> Graph::GetEdges() const {
    vector<Edge> edges;
    for(auto it: Edges)
        edges.push_back(it);
    return edges;
}

vector<Edge> Graph::GetIncomingEdges(int vertex) const {
    vector<Edge> null;
    if(IncomingEdges.find(vertex) != IncomingEdges.end()){
        for(auto it : IncomingEdges.at(vertex))
            null.push_back(it);
    }
    return null;
}

vector<Edge> Graph::GetOutgoingEdges(int vertex) const {
    vector<Edge> null;
    if(OutgoingEdges.find(vertex) != OutgoingEdges.end()){
        for(auto it : OutgoingEdges.at(vertex))
            null.push_back(it);
    }
    return null;
}

int Graph::GetDegree(int vertex) const {
    if(OutgoingEdges.find(vertex) != OutgoingEdges.end())
        return OutgoingEdges.find(vertex)->second.size();
    else return 0;
}

vector<int> Graph::GetNeighbors(int vertex) const {
    vector<int> neighbors;
    if(OutgoingEdges.find(vertex) != OutgoingEdges.end())
        for(auto it: OutgoingEdges.find(vertex)->second)
            neighbors.push_back(it.GetDestination());
    return neighbors;
}

bool Graph::AddVertex(int vertex){
    if(ContainsVertex(vertex)) return false;
    Vertices.insert(vertex);
    return true;
}

bool Graph::RemoveVertex(int vertex){
    if(!ContainsVertex(vertex)) return false;
    Vertices.erase(vertex);
    return true;
}

bool Graph::AddEdge(int vertex1, int vertex2){
    if(!ContainsVertex(vertex1) || !ContainsVertex(vertex2) || ContainsEdge(vertex1, vertex2)) return false;
    Edges.insert(Edge(vertex1, vertex2));
    if(IncomingEdges.find(vertex2) != IncomingEdges.end())
        IncomingEdges.at(vertex2).insert(Edge(vertex1, vertex2));
    else{
        set<Edge> edg;
        edg.insert(Edge(vertex1, vertex2));
        IncomingEdges.emplace(vertex2, edg);
    } 
    if(OutgoingEdges.find(vertex1) != OutgoingEdges.end())
        OutgoingEdges.at(vertex1).insert(Edge(vertex1, vertex2));
    else{
        set<Edge> edg;
        edg.insert(Edge(vertex1, vertex2));
        OutgoingEdges.emplace(vertex1, edg);
    } 
    return true;
}

bool Graph::RemoveEdge(int vertex1, int vertex2){
    if(!ContainsVertex(vertex1) || !ContainsVertex(vertex2) || !ContainsEdge(vertex1, vertex2)) return false;
    Edges.erase(Edge(vertex1, vertex2));
    IncomingEdges.at(vertex2).erase(Edge(vertex1, vertex2));
    OutgoingEdges.at(vertex1).erase(Edge(vertex1, vertex2));
    return true;
}