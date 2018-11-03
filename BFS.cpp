#include "BFS.h"
#include<queue>
#include<iostream>
#include<vector>
void shortestDistance(Adjacency** arr,int s){
  Vertex *p;
  std::queue <Vertex*> q;
  int nextValue=0;
  Vertex *vnext;
  arr[s]->getVertex(s)->setColor("Gray");
  arr[s]->getVertex(s)->setDistance(0);
  arr[s]->getVertex(s)->setParent(9999);
  q.push(arr[s]->getVertex(s));
  while(!q.empty()){
    p=q.front();
    q.pop();
    nextValue=arr[p->getValue()]->getHead();
    for(int i=0;i<arr[p->getValue()]->getSize()-1;i++){
      vnext=arr[p->getValue()]->getVertex(nextValue);

      if(vnext->getColor()=="White"){
        vnext->setColor("Gray");
        vnext->setDistance(p->getDistance()+1);
        vnext->setParent(p->getValue());
        q.push(vnext);
        }
        nextValue=arr[p->getValue()]->getNext(vnext)->getValue();

  }
  p->setColor("Black");

  }

}
