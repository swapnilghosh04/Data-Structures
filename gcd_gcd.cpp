#include <iostream>
using namespace std;
class gcd_gcd
{
  public:
        int gcd(int x, int y)
        {
          int rem;
          rem=x%y;
          if(rem==0)
            return y;
          else
            return(gcd(y, rem));
        }
        int iteration(int x, int y)
        {
          while(y!=0)
          {
            int temp=y;
            y=x%y;
            x=temp;
          }
          return x;
        }
};

int main()
{
  gcd_gcd ob;
  int choice, x, y;
  while(1)
  {
    cout<<endl<<"Enter 1 for recursion"<<endl;
    cout<<"Enter 2 for iteration"<<endl;
    cout<<"Enter 3 for exit from the program"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"Enter two values: ";
              cin>>x>>y;
              cout<<"GCD of "<<x<<" and "<<y<<" is: "<<ob.gcd(x, y)<<endl;
              break;
              
      case 2: cout<<"Enter two values: ";
              cin>>x>>y;
              cout<<"GCD of "<<x<<" and "<<y<<" is: "<<ob.iteration(x, y)<<endl;
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
