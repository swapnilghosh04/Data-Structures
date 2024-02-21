#include <iostream>
using namespace std;
#define max 30
class stackk
{
  int arr[max], top;
  public:
        stackk()
        {
          top=-1;
        }
        void push(int n)
        {
          if(top==max-1)
          {
            cout<<"Stack Overflow!"<<endl;
            return;
          }
          top++;
          arr[top]=n;
        }
        void pop()
        {
          if(top==-1)
          {
            cout<<"Stack Underflow!"<<endl;
            return;
          }
          int n=arr[top];
          top--;
        }
        void peek()
        {
          if(top==-1)
          {
            cout<<"Empty Stack!"<<endl;
            return;
          }
          cout<<arr[top]<<endl;
        }
        void display()
        {
          if(top==-1)
          {
            cout<<"Empty Stack!"<<endl;
            return;
          }
          for(int i=top; i>=0; i--)
          {
            cout<<arr[i]<<endl;
          }
        }
};

int main()
{
  stackk ob;
  int choice, n;
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
              cin>>n;
              ob.push(n);
              cout<<"The stack: "<<endl;
              ob.display();
              break;
              
      case 2: ob.pop();
              cout<<"The stack: "<<endl;
              ob.display();
              break;
              
      case 3: cout<<"The topmost element is: ";
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
      
              
            
