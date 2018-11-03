#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include "Vertex.h"
class Adjacency
{
private:
  struct node{
    Vertex* x;
    node* next;
  };
  typedef struct node* nodeptr;

  nodeptr head;
  nodeptr curr;
  nodeptr temp;

public:
  Adjacency();
  void AddNode(Vertex*);
  void DeleteNode(Vertex);
  void PrintList();
  int getHead() const;
  Vertex* getVertex(int);
  int getSize();
  Vertex* getNext(Vertex*);
};
