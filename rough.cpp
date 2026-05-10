#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->data=data;
    this->next=nullptr;
  }

};

void printList(Node* head){

  Node* temp=head;

  while(temp!=nullptr){
    cout<<temp->data<<" ";
    temp=temp->next;
  }

  cout<<endl;


}
int main(){
  Node* head =  new Node(10);
  head->next=new Node(20);

  printList(head);
  return 0;
}