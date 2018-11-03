#include "shortestPath.h"
#include<stack>
std::stack <int> s;
void printPath(Adjacency** arr,int a,int b){
  if(a!=b&&arr[b]->getVertex(b)->getParent()==9999){
    std::cerr<<"Error: Path Does Not Exist"<<"\n";
  }
  else if (arr[b]->getVertex(b)->getParent()==9999){
    s.push(arr[a]->getVertex(a)->getValue());
  }
  else{
    s.push(arr[b]->getVertex(b)->getValue());
    printPath(arr,a,arr[b]->getVertex(b)->getParent());
  }
  while (!s.empty())
{
    std::cout<< s.top();
    s.pop();
    if(s.size()==0)
    {
      std::cout<<"\n";
      break;
    }
    std::cout<<"-";
}
}
