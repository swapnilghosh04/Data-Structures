/*#include <iostream>
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
        node *gethead() {
return head;
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
        linked_list operator+(linked_list ob2) {
linked_list ob3;
node *link = gethead();
while(link->next != NULL)
link = link->next;
link->next = ob2.gethead();
ob3.head = head;
return ob3;
}
void display(node *head_ref) {
if(head_ref == NULL)
std::cout << "NULL" << std::endl;
else {
std::cout << head_ref->data << " ";
display(head_ref->next);
}
}
~linked_list() {
std::cout << "\nThank you...";
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
    cout<<"Enter 9 for concatenation"<<endl;
    cout<<"Enter 10 for display"<<endl;
    cout<<"Enter 11 for exit from the program"<<endl;
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
              
      case 9: int n2;
std::cout << "\nnumber of elements u want to insert in 2nd linkedlist: ";
std::cin >> n2;
b.add_node(n2);
c = a + b;
std::cout << "\nPresenting the Marged linked list\n"; 
c.display(c.gethead());
break;
              
      case 10: ob.display();
              break;
          
      case 11: cout<<endl<<"END OF THE PROGRAM."<<endl;
               break;
               
      default: cout<<"WRONG CHOICE!"<<endl;
                break;
    }
    if(choice==11)
      break;
  }
  return 0;
}*/

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

class linked_list {
    struct node* head;

public:
    linked_list() {
        head = NULL;
    }

    node* gethead() {
        return head;
    }

    void insert_beginning(int value) {
        struct node* temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void delete_beginning() {
        if (head == NULL) {
            cout << "List is already empty!" << endl;
            return;
        }
        struct node* temp = head;
        head = head->next;
        delete temp;
    }

    void insert_end(int value) {
        struct node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            return;
        }
        struct node* temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }

    void delete_end() {
        if (head == NULL) {
            cout << "List is already empty!" << endl;
            return;
        }
        struct node* temp = head;
        struct node* prev_temp = NULL;
        while (temp->next != NULL) {
            prev_temp = temp;
            temp = temp->next;
        }
        if (prev_temp != NULL)
            prev_temp->next = NULL;
        delete temp;
    }

    void insert_position(int value) {
        struct node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            return;
        }
        int pos;
        cout << "Enter the position: ";
        cin >> pos;
        if (pos == 1) {
            temp->next = head;
            head = temp;
            return;
        }
        struct node* temp1 = head;
        for (int i = 1; i < pos - 1 && temp1 != NULL; i++) {
            temp1 = temp1->next;
        }
        if (temp1 == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }

    void delete_position() {
        if (head == NULL) {
            cout << "List is already empty!" << endl;
            return;
        }
        int pos;
        cout << "Enter the position: ";
        cin >> pos;
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            struct node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        struct node* temp = head;
        struct node* prev_temp = NULL;
        for (int i = 1; temp != NULL && i < pos; i++) {
            prev_temp = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }
        prev_temp->next = temp->next;
        delete temp;
    }

    void linear_search() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        int value;
        cout << "Enter the value to be searched: ";
        cin >> value;
        struct node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Node with value " << value << " is found!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Node with value " << value << " is not found!" << endl;
    }

    void reverse() {
        struct node* prev = NULL;
        struct node* current = head;
        struct node* next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    linked_list operator+(linked_list ob2) {
        linked_list result;
        struct node* temp = head;
        while (temp != NULL) {
            result.insert_end(temp->data);
            temp = temp->next;
        }
        temp = ob2.head;
        while (temp != NULL) {
            result.insert_end(temp->data);
            temp = temp->next;
        }
        return result;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        struct node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~linked_list() {
        struct node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Linked list destroyed." << endl;
    }
};

int main() {
    int choice, value;
    linked_list ob;
    while (true) {
        cout << endl
             << "Enter 1 for insertion at the beginning" << endl;
        cout << "Enter 2 for deletion from the beginning" << endl;
        cout << "Enter 3 for insertion at the end" << endl;
        cout << "Enter 4 for deletion from the end" << endl;
        cout << "Enter 5 for insertion at any position" << endl;
        cout << "Enter 6 for deletion from any position" << endl;
        cout << "Enter 7 for linear search" << endl;
        cout << "Enter 8 for reversing the list" << endl;
        cout << "Enter 9 for concatenation" << endl;
        cout << "Enter 10 for display" << endl;
        cout << "Enter 11 to exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> value;
                ob.insert_beginning(value);
                break;
            case 2:
                ob.delete_beginning();
                break;
            case 3:
                cout << "Enter value to be inserted: ";
                cin >> value;
                ob.insert_end(value);
                break;
            case 4:
                ob.delete_end();
                break;
            case 5:
                cout << "Enter value to be inserted: ";
                cin >> value;
                ob.insert_position(value);
                break;
            case 6:
                ob.delete_position();
                break;
            case 7:
                ob.linear_search();
                break;
            case 8:
                ob.reverse();
                break;
            case 9:
                {
                    linked_list ob2;
                    int n;
                    cout << "Enter number of elements for the second list: ";
                    cin >> n;
                    for (int i = 0; i < n; ++i) {
                        cout << "Enter value for element " << i + 1 << ": ";
                        cin >> value;
                        ob2.insert_end(value);
                    }
                    linked_list result = ob + ob2;
                    cout << "Concatenated list: ";
                    result.display();
                    break;
                }
            case 10:
                ob.display();
                break;
            case 11:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
