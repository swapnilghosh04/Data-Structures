#include <iostream>
using namespace std;
class linear_binary
{
  int n, arr[30];
  public:
         void input_length()
         {
           cout<<"Enter the size of the array: ";
           cin>>n;
         }
         void input_array()
         {
          cout<<"Enter the elements of the array: "<<endl;
          for(int i=0; i<n; i++)
          {
            cout<<"arr["<<i<<"]= ";
            cin>>arr[i];
          }
        }
        void linear_search()
        {
          int value, count=0;
          cout<<"Enter a value to be searched: ";
          cin>>value;
          for(int i=0; i<n; i++)
          {
            if(value==arr[i])
            {
              count++;
            }
          }
          if(count==0)
          {
            cout<<"Element is NOT found!"<<endl;
          }
          else
          {
            cout<<"Element is found"<<count<<" times."<<endl;
          }
        }
        void binary_search()
        {
          int value;
          cout<<"Enter a value to be searched: ";
          cin>>value;
          int low=0, high=n-1, mid=(low+high)/2;
          while(low<=high)
          {
            if(value>arr[mid])
            {
              low=mid+1;
            }
            else if(value==arr[mid])
            {
              cout<<value<<" is present in the position "<<mid+1<<endl;
              break;
            }
            else
            {
              high=mid-1;
            }
            mid=(low+high)/2;
          }
          if(low>high)
          {
            cout<<"Search is Unsuccessful!"<<endl;
          }
        }
        void display()
        {
          for(int i=0; i<n; i++)
          {
            cout<<arr[i]<<" ";
          }
        }
};

int main()
{
  int choice;
  linear_binary ob;
  ob.input_length();
  ob.input_array();
  while(1)
  {
    cout<<endl<<"Enter 1 for linear search"<<endl;
    cout<<"Enter 2 for binary search"<<endl;
    cout<<"Enter 3 for display"<<endl;
    cout<<"Enter 4 for exit from the program"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
      case 1: ob.linear_search();
              break;
              
      case 2: ob.binary_search();
              break;
              
      case 3: ob.display();
              break;
              
      case 4: cout<<endl<<"END OF PROGRAM!"<<endl;
              break;
              
      default: cout<<"WRONG CHOICE!"<<endl;
               break;
    }
    if(choice==4)
      break;
  }
  return 0;
}
         
