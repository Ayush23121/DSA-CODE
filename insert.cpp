#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
    node(int x)
    {
      data=x;
      next=NULL;
    }
};
int main(){
    node *Head;
    if (Head==NULL){
    Head = new node(4);
    }
   else
   {
    node *temp;
    temp= new node(28);
    temp->next=Head;
    Head=temp;

   } 
   return Head->data;

}