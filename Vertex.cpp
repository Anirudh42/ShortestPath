#include "Vertex.h"

Vertex::Vertex()
{
  color="White";
  d=9999;
  value=9999;
  parent=9999;
}

Vertex::Vertex(std::string color,int d,int parent,int value)
{
  this->color=color;
  this->d=d;
  this->parent=parent;
  this->value=value;
}

Vertex::~Vertex()
{

}

std::string Vertex::getColor() const{
  return color;
}

int Vertex::getDistance() const{
  return d;
}

int Vertex::getParent() const{
  return parent;
}

int Vertex::getValue() const{
  return value;
}

void Vertex::setColor(std::string color){
  this->color=color;
}

void Vertex::setParent(int parent){
  this->parent=parent;
}

void Vertex::setDistance(int d){
  this->d=d;
}
