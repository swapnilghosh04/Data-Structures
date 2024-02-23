#include<stdio.h>

#include<iostream>

using namespace std;

class node{

          public:

                   int key;

                   int data;

                   node* link1;

                   node(){

                             key=0;

                             data=0;

                             link1=NULL;

                   }

};

class de_queue{

          public:

                   node* head;

                   de_queue(){

                             head=NULL;

                   }

                   int check(int n){

                             node* ptr=head;

                             while(ptr!=NULL){

                                      if(ptr->key==n)

                                                return 1;

                                      ptr=ptr->link1;

                             }

                             return 0;

                   }

                   void queue(node* n){

                             if(head==NULL)

                                      head=n;

                             else{

                                      if(check(n->key))

                                                cout<<"THIS KEY ALREADY EXISTS...TRY WITH ANOTHER KEY .."<<endl;

                                      else{

                                                node* ptr=head;

                                                while(ptr!=NULL){

                                                          if(ptr->link1==NULL){

                                                                   ptr->link1=n;

                                                                   break;

                                                          }

                                                          ptr=ptr->link1;

                                                }

                                      }

                             }                          

                   }

                   void stenqueue(node* n){

                             if(head==NULL)

                                      head=n;

                             else{

                                      if(check(n->key))

                                                cout<<"THIS KEY ALREADY EXISTS...TRY WITH ANOTHER KEY .."<<endl;

                                      else{

                                                n->link1=head;

                                                head=n;

                                                cout<<"INSERTED DATA SUCCESSFULLY FROM FRONT...."<<endl;

                                      }

                             }

                   }

                   void lastenqueu(node* n){

                             if(head==NULL)

                                      head=n;

                             else{

                                      if(check(n->key))

                                                cout<<"THIS KEY ALREADY EXISTS...TRY WITH ANOTHER KEY .."<<endl;

                                      else{

                                                node* ptr=head;

                                                while(ptr!=NULL){

                                                          if(ptr->link1==NULL){

                                                                   ptr->link1=n;

                                                                   break;

                                                          }

                                                          ptr=ptr->link1;

                                                }

                                                cout<<"INSERTED DATA SUCCESSFULLY FROM REAR ...."<<endl;

                                      }

                             }                          

                   }

                   void stdqueue(){

                             if(head==NULL)

                                      cout<<"THE QUEUE IS EMPTY ...."<<endl;

                             else{

                                      head=head->link1;

                                      cout<<"DELETED AN ELEMENT SUCCESSFULLY FROM FRONT ...."<<endl;

                             }

                   }

                   void lastdqueue(){

                             if(head==NULL)

                                      cout<<"THE QUEUE IS EMPTY........."<<endl;

                             else{

                                      node* ptr=head;

                                      node* ptr1=NULL;

                                      while(ptr->link1!=NULL){

                                                ptr1=ptr;

                                                ptr=ptr->link1;

                                      }

                                      ptr1->link1=NULL;

                                      cout<<"DELETED AN ELEMENT SUCCESSFULLY FROM REAR..."<<endl;

                             }

                   } 

                   void display(){

                             if(head==NULL)

                                      cout<<"THE QUEUE IS EMPTY ...."<<endl;

                             else{

                                      node* ptr=head;

                                      while(ptr!=NULL){

                                                cout<<"("<<ptr->key<<","<<ptr->data<<")->";

                                                ptr=ptr->link1;

                                      }

                             }

                   }

};

int main(){

          de_queue ob;

          int opt=0;

          do{

                   cout<<"\nPRESS 0 TO EXIT ...."<<endl;

                   cout<<"PRESS 1 TO INSERT DATA IN QUEUE ....."<<endl;

                   cout<<"PRESS 2 TO ENQUEUE AT FIRST ...."<<endl;

                   cout<<"PRESS 3 TO ENQUEUE AT LAST......"<<endl;

                   cout<<"PRESS 4 TO DEQUEUE AT FIRST......"<<endl;

                    cout<<"PRESS 5 TO DEQUEUE AT LAST......"<<endl;

                   cout<<"PRESS 6 TO DISPLAY......"<<endl;

                   cin>>opt;

                   node *n=new node();

                   switch(opt){

                             case 0: cout<<"END OF THE PROGRAM..."<<endl;

                                      break;

                             case 1:

                                      cout<<"ENTER THE KEY OF THE DATA ->"<<endl;

                                      cin>>n->key;

                                      cout<<"ENTER THE DATA ->"<<endl;

                                      cin>>n->data;

                                      ob.queue(n);

                                      break;

                             case 2:

                                      cout<<"ENTER THE KEY OF THE DATA ->"<<endl;

                                      cin>>n->key;

                                      cout<<"ENTER THE DATA ->"<<endl;

                                      cin>>n->data;

                                      ob.stenqueue(n);

                                      break;

                             case 3:

                                      cout<<"ENTER THE KEY OF THE DATA ->"<<endl;

                                      cin>>n->key;

                                      cout<<"ENTER THE DATA ->"<<endl;

                                      cin>>n->data;

                                      ob.lastenqueu(n);

                                      break;

                             case 4:

                                      ob.stdqueue();

                                      break;

                             case 5:

                                      ob.lastdqueue();

                                      break;

                             case 6:

                                      ob.display();

                                      break;

                             default:

                                      cout<<"...............ERROR..............."<<endl;

                                      break;

                   }

                  

          }while(opt!=0);

          return 0;

}
