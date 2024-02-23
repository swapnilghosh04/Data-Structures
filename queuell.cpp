#include <iostream>
using namespace std;

struct node *front = NULL, *rear = NULL;

struct node
{
    int data;
    struct node *link;
};

void insert()
{
    struct node *temp;
    temp = new node;
    cout<<"Enter data: ";
    cin>>temp->data;
    temp->link = NULL;
    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

void deletion()
{
    struct node *temp;
    if (front == NULL)
        cout<<"Queue Underflow\n";
    else
    {
        if (front == rear)
        {
            cout<<"Deleted data = \n"<<front->data;
            delete(front);
            front = NULL;
            rear = NULL;
        }
        else
        {
            temp = front;
            cout<<"Deleted data = \n"<<temp->data;
            front = front->link;
            delete(temp);
        }
    }
}

void display()
{
    struct node *temp;
    if (front == NULL)
        cout<<"Empty Queue\n";
    else
    {
        temp = front;
        while (temp != NULL)
        {
            cout<<temp->data;
            temp = temp->link;
        }
    }
}

int main()
{
    while (1)
    {
        cout<<"\nEnter 1 to insert element\n";
        cout<<"Enter 2 to delete element\n";
        cout<<"Enter 3 to display Queue\n";
        cout<<"Enter 4 to exit\n";
        cout<<"\nEnter choice : ";
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            deletion();
            break;
        case 3:
            cout<<"\nThe Queue is\n";
            display();
            break;
        case 4:
            cout<<"\nEnd of program\n";
            break;
        default:
            cout<<"\nInvalid input\n";
        }
        if (choice == 4)
            break;
    }
    return 0;
}
