#include <iostream>
using namespace std;
#define max 30
class circular_queue
{
  int front, rear, arr[max];
  public:
        circular_queue()
        {
          front=rear=-1;
        }
        void insertion(int n)
        {
          if((rear+1)%max==front)
          {
            cout<<"Circular Queue Overflow"<<endl;
            return;
          }
          if(front==-1 && rear==-1)
          {
            front=rear=0;
          }
          else if(rear==max-1 && front!=0)
          {
            rear=0;
          }
          else
          {
            rear=(rear+1)%max;
          }
          arr[rear]=n;
        }
        void deletion()
        {
          if(front==-1)
          {
            cout<<"Circular Queue Underflow!"<<endl;
            return;
          }
          int n=arr[front];
          if(front==rear)
          {
            front=rear=-1;
          }
          else
          {
            if(front==max-1)
            {
              front=0;
            }
            else
            {
              front++;
            }
          }
        }
        void peek()
        {
          if(front==-1 && rear==-1)
          {
            cout<<"Empty Queue!"<<endl;
            return;
          }
          cout<<arr[front]<<endl;
        }
        void display()
        {
          if(front==-1 && rear==-1)
          {
            cout<<"Empty Queue!"<<endl;
          }
          else {
          if(front<=rear) {
          for(int i=front; i<=rear; i++)
          {
            cout<<arr[i]<<" ";
          }
          }
          else
          {
            for(int i=front; i<max; i++)
            {
              cout<<arr[i]<<" ";
            }
            for(int i=0; i<=rear; i++)
            {
              cout<<arr[i]<<" ";
            }
          }
          cout<<endl;
        }
        }
};

int main()
{
  circular_queue ob;
  int choice, n;
  while(1)
  {
    cout<<endl<<"Enter 1 for insertion"<<endl;
    cout<<"Enter 2 for deletion"<<endl;
    cout<<"Enter 3 for peek operation"<<endl;
    cout<<"Enter 4 for display"<<endl;
    cout<<"Enter 5 for exit from the program"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"Enter a value to be inserted: ";
              cin>>n;
              ob.insertion(n);
              cout<<"The queue: "<<endl;
              ob.display();
              break;
              
      case 2: ob.deletion();
              cout<<"The queue: "<<endl;
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
