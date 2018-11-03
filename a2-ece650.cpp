#include "AllEdges.h"
#include<iterator>
#include<iostream>
#include<vector>
#include<regex>
#include<sstream>
#include<string>
#include<stack>
#include<queue>
int main(void) {
    std::string s;
    std::vector<int> edges;
    std::vector<int> vertices;
    Adjacency** arr;
    Vertex** vertexobjs;
    // int input=0;
    // int sizeofv=0;
    int fixedsize=0;
    while(std::getline(std::cin,s)){
      std::regex reg ("[-]?[0-9]+");
      std::regex regstring("[a-zA-Z]+");
      std::sregex_iterator stringmatch(s.begin(),s.end(),regstring);
      std::smatch matchstring=*stringmatch;
      std::sregex_iterator currentMatch(s.begin(),s.end(),reg);
      std::sregex_iterator lastMatch;
      //int numberofvertices=0;
      if(matchstring.str()=="V"){
        if(fixedsize!=0){
          for(unsigned int i=0;i<vertices.size();i++){
            delete vertexobjs[vertices[i]];
            delete arr[vertices[i]];
          }
          delete[] vertexobjs;
          delete[] arr;
        }
        int input=0;
        std::stringstream ss((*currentMatch).str());
        ss>>input;
        arr=new Adjacency*[input];
        vertexobjs=new Vertex*[input];
        fixedsize=input;
      }
      else if(matchstring.str()=="E"){
        int flag=0;
        int input=0;
        edges.clear();
        vertices.clear();
        while(currentMatch!=lastMatch){
          std::smatch match=*currentMatch;
          std::stringstream ss(match.str());
          ss>>input;
          if(input<fixedsize){
            edges.push_back(input);
            currentMatch++;
          }
          else{
            std::cerr<<"Error: Enter Vertex ID only upto "<<fixedsize-1<<"\n";
            flag=1;
            break;
          }

        }
        if(flag==0){
          for(unsigned int i=0;i<edges.size();i++){
              if(std::find(vertices.begin(),vertices.end(),edges[i])!=vertices.end()){
                continue;
              }else{
                vertices.push_back(edges[i]);
            }
            }
            calculateEdges(vertexobjs,arr,vertices,edges);

          }
        }
         else if(matchstring.str()=="s"){
          int flag=0;
          int input=0;
          std::vector<int> srcdst;
          while(currentMatch!=lastMatch){
            std::smatch match=*currentMatch;
            std::stringstream ss(match.str());
            ss>>input;
            if(std::find(vertices.begin(), vertices.end(), input) != vertices.end()){
              srcdst.push_back(input);
              currentMatch++;

            }else{
              std::cerr<<"Error: Vertex ID Does Not Exist "<<"\n";
              flag=1;
              break;
            }

          }
          if(flag==0){
            shortestDistance(arr,srcdst[0]);
            printPath(arr,srcdst[0],srcdst[1]);
            srcdst.clear();
            for(unsigned int i=0;i<vertices.size();i++){
              delete vertexobjs[vertices[i]];
              delete arr[vertices[i]];
            }
            delete[] vertexobjs;
            delete[] arr;
            arr=new Adjacency*[fixedsize];
            vertexobjs=new Vertex*[fixedsize];
            calculateEdges(vertexobjs,arr,vertices,edges);
          }

        }


    }
    for(unsigned int i=0;i<vertices.size();i++){
      delete vertexobjs[vertices[i]];
      delete arr[vertices[i]];
    }
    delete[] vertexobjs;
    delete[] arr;

    return 0;
}
