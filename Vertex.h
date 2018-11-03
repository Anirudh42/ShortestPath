#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
  class Vertex
  {
  private:
    std::string color;
    int d;
    int parent;
    int value;

  public:
    Vertex();
    Vertex(std::string,int,int,int);
    ~Vertex();
    std::string getColor() const;
    int getDistance() const;
    int getParent() const;
    int getValue() const;
    void setColor(std::string);
    void setParent(int);
    void setDistance(int);
  };
