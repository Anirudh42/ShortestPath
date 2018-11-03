#include "AllEdges.h"
#include<vector>
#include<queue>
#include<stack>
void calculateEdges(Vertex** vertexobjs,Adjacency** arr,std::vector<int> vertices_copy,std::vector<int> edges_copy){

  //Vertex **vertexobjs=new Vertex*[novertices];
  for(unsigned int i=0;i<vertices_copy.size();i++){
    Vertex *u=new Vertex("White",9999,9999,vertices_copy[i]);
    vertexobjs[vertices_copy[i]]=&(*u);
  }

  Vertex *udummy=new Vertex("Dummy",9999,9999,9999);
  for(unsigned int i=0;i<vertices_copy.size();i++){
    Adjacency *a=new Adjacency();
    a->AddNode(vertexobjs[vertices_copy[i]]);
    for(unsigned int j=0;j<edges_copy.size();j=j+2){
      if(vertices_copy[i]==edges_copy[j]){
        a->AddNode((vertexobjs[edges_copy[j+1]]));
        }
      if(vertices_copy[i]==edges_copy[j+1]){
        a->AddNode((vertexobjs[edges_copy[j]]));
      }
    }

    a->AddNode(&(*udummy));
    arr[vertices_copy[i]]=&(*a);

  }

}
