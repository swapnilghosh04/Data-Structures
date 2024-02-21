#include <iostream>
using namespace std;
struct node
{
  int data;
  struct node* next;
};
class stackll
{
  struct node* top;
  public:
        stackll()
        {
          top=NULL;
        }
        void push(int value)
        {
          struct node* temp=new node;
          temp->data=value;
          temp->next=top;
          top=temp;
        }
        void pop()
        {
          struct node* temp;
          if(top==NULL)
          {
            cout<<"Stack Underflow!"<<endl;
            return;
          }
          temp=top;
          top=top->next;
          delete(temp);
        }
        void peek()
        {
          if(top==NULL)
          {
            cout<<"Empty Stack!"<<endl;
            return;
          }
          cout<<top->data<<" ";
        }
        void display()
        {
          struct node* temp;
          if(top==NULL)
          {
            cout<<"Empty Stack!"<<endl;
            return;
          }
          temp=top;
          while(temp!=NULL)
          {
          cout<<temp->data<<" ";
          temp=temp->next;
          }
        }
};

int main()
{
  stackll ob;
  int choice, value;
  while(1)
  {
    cout<<endl<<"Enter 1 for push operation"<<endl;
    cout<<"Enter 2 for pop operation"<<endl;
    cout<<"Enter 3 for peek operation"<<endl;
    cout<<"Enter 4 for display"<<endl;
    cout<<"Enter 5 for exit from the program"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"Enter a value to push: ";
              cin>>value;
              ob.push(value);
              cout<<"The stack: "<<endl;
              ob.display();
              break;
              
      case 2: ob.pop();
              cout<<"The stack: "<<endl;
              ob.display();
              break;
              
      case 3: cout<<"The topmost value is: ";
              ob.peek();
              break;
              
      case 4: ob.display();
              break;
              
      case 5: cout<<endl<<"END OF THE PROGRAM."<<endl;
              break;
      
      default: cout<<"WRONG CHOICE!"<<endl;
               break;
    }
    if(choice==5)
      break;
  }
  return 0;
}
              
