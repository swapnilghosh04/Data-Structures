#include <iostream>
using namespace std;
struct node 
{
  int data;
  struct node* next;
};
class linked_list
{
  struct node* head;
  public:
        linked_list()
        {
          head=NULL;
        }
        void insert_beginning(int value)
        {
          struct node* temp=new node;
          temp->data=value;
          temp->next=head;
          head=temp;
        }
        void delete_beginning()
        {
          struct node* temp=head;
          head=head->next;
          delete(temp);
        }
        void insert_end(int value)
        {
          struct node* temp=new node;
          temp->data=value;
          temp->next=NULL;
          struct node* temp1=head;
          while(temp1->next!=NULL)
          {
            temp1=temp1->next;
          }
          temp1->next=temp;
        }
        void delete_end()
        {
          struct node* temp=head;
          struct node* prev_temp;
          while(temp->next!=NULL)
          {
            prev_temp=temp;
            temp=temp->next;
          }
          prev_temp->next=NULL;
          delete(temp);
        }
        void insert_position(int value)
        {
          struct node* temp=new node;
          temp->data=value;
          struct node* temp1=head;
          int pos;
          cout<<"Enter the position: ";
          cin>>pos;
          pos--;
          while(pos!=1)
          {
            temp1=temp1->next;
            pos--;
          }
          temp->next=temp1->next;
          temp1->next=temp;
        }
        void delete_position()
        {
          struct node* temp=head;
          struct node* prev_temp=head;
          int pos;
          cout<<"Enter the position: ";
          cin>>pos;
          if(head==NULL)
          {
            cout<<"List is already empty!"<<endl;
          }
          else if(pos==1)
          {
            head=temp->next;
            delete(temp);
            temp=NULL;
          }
          else
          {
            while(pos!=1)
            {
              prev_temp=temp;
              temp=temp->next;
              pos--;
            }
            prev_temp->next=temp->next;
            delete(temp);
            temp=NULL;
          }
        }
        void linear_search()
        {
          struct node* temp=head;
          int value;
          cout<<"Enter the value of a node to be searched: ";
          cin>>value;
          while(temp!=NULL)
          {
            if(value==temp->data)
            {
              cout<<"Node has been found!"<<endl;
              break;
            }
            temp=temp->next;
          }
          if(temp==NULL)
          {
            cout<<"Desired Node is NOT found!"<<endl;
          }
        }
        void reverse()
        {
          struct node* prev_node=NULL;
          struct node* curr_node=head;
          struct node *next_node=head;
          while(next_node!=NULL)
          {
            next_node=next_node->next;
            curr_node->next=prev_node;
            prev_node=curr_node;
            curr_node=next_node;
          }
          head=prev_node;
        }
        void display()
        {
          struct node* temp=head;
          while(temp!=NULL)
          {
            cout<<temp->data<<" ";
            temp=temp->next;
          }
        }
};

int main()
{
  int choice, value;
  linked_list ob;
  while(1)
  {
    cout<<endl<<"Enter 1 for insertion at the beginning"<<endl;
    cout<<"Enter 2 for deletion from the beginning"<<endl;
    cout<<"Enter 3 for insertion at the end"<<endl;
    cout<<"Enter 4 for deletion from the end"<<endl;
    cout<<"Enter 5 for insertion at any position"<<endl;
    cout<<"Enter 6 for deletion from any position"<<endl;
    cout<<"Enter 7 for linear search"<<endl;
    cout<<"Enter 8 for reversing the traversal"<<endl;
    cout<<"Enter 9 for display"<<endl;
    cout<<"Enter 10 for exit from the program"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
      case 1: cout<<"Enter a value to be inserted: ";
              cin>>value;
              ob.insert_beginning(value);
              cout<<"List after insertion is: "<<endl;
              ob.display();
              break;
              
      case 2: ob.delete_beginning();
              cout<<"List after deletion is: "<<endl;
              ob.display();
              break;
              
      case 3: cout<<"Enter a value to be inserted: ";
              cin>>value;
              ob.insert_end(value);
              cout<<"List after insertion is: "<<endl;
              ob.display();
              break;
              
      case 4: ob.delete_end();
              cout<<"List after deletion is: "<<endl;
              ob.display();
              break;
              
      case 5: cout<<"Enter a value to be inserted: ";
              cin>>value;
              ob.insert_position(value);
              cout<<"List after insertion is: "<<endl;
              ob.display();
              break;
              
      case 6: ob.delete_position();
              cout<<"List after deletion is: "<<endl;
              ob.display();
              break;
              
      case 7: ob.linear_search();
              break;
      
      case 8: ob.reverse();
              cout<<"Reversed list is: ";
              ob.display();
              break;
              
      case 9: ob.display();
              break;
          
      case 10: cout<<endl<<"END OF THE PROGRAM."<<endl;
               break;
               
      default: cout<<"WRONG CHOICE!"<<endl;
                break;
    }
    if(choice==10)
      break;
  }
  return 0;
}
