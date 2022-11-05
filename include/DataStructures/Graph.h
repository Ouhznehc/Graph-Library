#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <DataStructures/Edge.h>
#include <bits/stdc++.h>

class Graph
{
public:
  Graph();
  ~Graph();

public:
  virtual bool AddVertex(int vertex);
  virtual bool RemoveVertex(int vertex);
  virtual bool AddEdge(int vertex1, int vertex2);
  virtual bool RemoveEdge(int vertex1, int vertex2);

 public:
  virtual int CountVertices() const;
  virtual int CountEdges() const;
  virtual bool ContainsVertex(int vertex) const;
  virtual bool ContainsEdge(int vertex1, int vertex2) const;
  virtual std::vector<int> GetVertices() const;
  std::vector<Edge> GetEdges() const;
  std::vector<Edge> GetIncomingEdges(int vertex) const;
  std::vector<Edge> GetOutgoingEdges(int vertex) const;
  virtual int GetDegree(int vertex) const;
  std::vector<int> GetNeighbors(int vertex) const;

protected:
  std::set<int> Vertices;
  std::set<Edge> Edges;
  std::map<int, std::set<Edge>> IncomingEdges;
  std::map<int, std::set<Edge>> OutgoingEdges;
};

#endif
