#include <iostream>
#include <string.h>
using namespace std;
class postfix
{
  int s[30], top;
  char post[30];
  public:
        postfix()
        {
          top=-1;
        }
        void input_array()
        {
          cout<<"Enter the postfix expression: ";
          cin>>post;
        }
        void push(int x)
        {
          s[++top]=x;
        }
        int pop()
        {
          return s[top--];
        }
        void evaluation()
        {
          int z;
          for(int i=0; i<strlen(post); i++)
          {
            if(post[i]>='0' && post[i]<='9')
            {
              push(post[i]-48);
            }
            else
            {
              int x=pop();
              int y=pop();
              if(post[i]=='+')
                z=y+x;
              if(post[i]=='-')
                z=y-x;
              if(post[i]=='*')
                z=y*x;
              if(post[i]=='/')
                z=y/x;
              if(post[i]=='%')
                z=y%x;
              if(post[i]=='^')
              {
                z=1;
                for(int j=1; j<=x; j++)
                {
                  z=z*y;
                }
              }
              push(z);
            }
          }
          cout<<s[0]<<endl;
        }
};
                
int main()
{
  postfix ob;
  ob.input_array();
  ob.evaluation();
  return 0;
}
