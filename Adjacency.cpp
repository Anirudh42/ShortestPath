#include "Adjacency.h"

Adjacency::Adjacency()
{
  head=NULL;
  curr=NULL;
  temp=NULL;
}

void Adjacency::AddNode(Vertex* u){
  nodeptr n=new node;
  n->next=NULL;
  n->x=u;

  if(head!=NULL){
    curr = head;
    while(curr->next!=NULL){
      curr=curr->next;
    }
    curr->next=n;
  }
  else{
    head=n;
  }
}

void Adjacency::PrintList(){
  curr=head;
  while(curr!=NULL){
    std::cout<<curr->x->getValue()<<"\n";
    curr=curr->next;
  }
}

void Adjacency::DeleteNode(Vertex u){
  nodeptr delptr=NULL;
  temp=head;
  curr=head;
  while(curr!=NULL && curr->x->getValue()!=u.getValue()){
    temp=curr;
    curr=curr->next;
  }
  if(curr==NULL){
    std::cout<<"Not in the List"<<"\n";
    delete delptr;
  }
  else{
    delptr=curr;
    curr=curr->next;
    temp->next=curr;
    if(delptr==head){
      head=head->next;
      temp=NULL;
    }
    delete delptr;
  }
}

int Adjacency::getHead() const{
  return head->x->getValue();
}

Vertex* Adjacency::getVertex(int value){
  curr=head;
  temp=head;
  while(curr!=NULL&&curr->x->getValue()!=value){
    curr=curr->next;
    temp=curr;
    }
    // std::string s="Gray";
    // temp->x.setColor(s);
  return (temp->x);
}

int Adjacency::getSize(){
  curr=head;
  int count=0;
  while(curr!=NULL){
    count++;
    curr=curr->next;
  }
  return count;
}

Vertex* Adjacency::getNext(Vertex *u) {
  curr=head;
  temp=head;
  while(curr!=NULL&&curr->x->getValue()!=u->getValue()){
    curr=curr->next;
  }
  temp=curr->next;
  return (temp->x);
}
