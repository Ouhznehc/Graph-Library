#ifndef EDGE_H
#define EDGE_H

class Edge
{
public:
  Edge(int source, int destination);
  ~Edge();
  bool operator==(const Edge &b) const {
    return this->source == b.source && this->destination == b.destination;
  }
  bool operator< (const Edge &b) const{
    if(this->source < b.source) return true;
    if(this->source == b.source) return this->destination < b.destination;
    return false;
}
public:
  int GetSource() const;
  int GetDestination() const;

protected:
  int source, destination;
};

#endif
