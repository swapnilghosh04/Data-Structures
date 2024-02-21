#include <iostream>
using namespace std;
class factorial
{
  public:
        int fact(int n)
        {
          if(n==1)
            return 1;
          else
            return(n*fact(n-1));
        }
        int iteration(int n)
        {
          int f=1;
          for(int i=2; i<=n; i++)
          {
            f=f*i;
          }
          return f;
        }
};

int main()
{
  factorial ob;
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
              cout<<"Factorial of "<<n<<" is: "<<ob.fact(n)<<endl;
              break;
              
      case 2: cout<<"Enter a value: ";
              cin>>n;
              cout<<"Factorial of "<<n<<" is: "<<ob.iteration(n)<<endl;
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
