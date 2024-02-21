#include <iostream>
using namespace std;
class fibonacci
{
  public:
         int fibo(int n)
         {
            if(n==0)
              return 0;
            else if(n==1)
              return 1;
            else
              return(fibo(n-1)+fibo(n-2));
         }
         void iteration(int n)
         {
            int x=0, y=1, z=0;
            for(int i=0; i<n; i++)
            {
              if(i<=1)
                z=i;
              else
              {
                z=x+y;
                x=y;
                y=z;
              }
                cout<<z<<" ";
            }
          }
};

int main()
{
  fibonacci ob;
  int choice, n;
  while(1)
  {
    cout<<endl<<"Enter 1 for recursion"<<endl;
    cout<<"Enter 2 for iteration"<<endl;
    cout<<"Enter 3 for exit from the program"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"Enter a value: ";
              cin>>n;
              cout<<"Fibonacci Series of "<<n<<" is: "<<endl;
              for(int i=0; i<n; i++)
              {
                cout<<ob.fibo(i)<<" ";
              }
              break;
              
      case 2: cout<<"Enter a value: ";
              cin>>n;
              cout<<"Fibonacci Series of "<<n<<" is: "<<endl;
              ob.iteration(n);
              break;
              
      case 3: cout<<endl<<"END OF THE PROGRAM."<<endl;
              break;
              
      default: cout<<"WRONG CHOICE!"<<endl;
               break;
    }
    if(choice==3)
      break;
  }
  return 0;
}
