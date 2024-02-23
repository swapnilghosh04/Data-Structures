/*#include <iostream>
using namespace std;
struct node 
{
  int data;
  struct node* next;
};
class circularll
{
  struct node* head;
  public:
        circularll()
        {
          head=NULL;
        }
        void */
        
#include <iostream> //5. circular LL
struct node {
int data;
node *next;
};
class CLL {
private:
node *head, *tail;
public:
CLL() {
head = NULL;
tail = NULL;
}
void addNode(int n) {
int k;
for(int i = 1; i <= n; i++) {
node *tmp = new node;
std::cout << "\nData" << i << "= ";
std::cin >> k;
tmp->data = k;
tmp->next = NULL;
if(head == NULL) {
head = tmp;
tail = tmp;
tmp->next = head;
} else {
tmp->next = head;
tail->next = tmp;
tail = tmp;
}
}
}
void display() {
node *ptr = head;
while(ptr->next != head) {
std::cout << " " << ptr->data;
ptr = ptr->next;
}
std::cout << " " << ptr->data;
}
void search(int k) {
node *current = head;
int c = 0;
bool Flag = false;
while(current->next != head) {
if(current->data == k) {
std::cout << "\nSearch Successful !!!";
Flag = true;
break;
} else
current = current->next;
c++;
}
if(Flag == false) {
if(current->data == k) {
std::cout << "\nSearch Successful !!!";
Flag = true;
}
} else if(Flag == true) {
c++;
std::cout << "\n" << k << " is in Position " << c;
} else {
std::cout << "\n" << k << " is not found";
}
}
void Insert(int pos, int x) {
node *tmp = new node;
tmp->data = x;
tmp->next = NULL;
node *ptr = NULL;
ptr = head;
if(pos == 1) {
head = tmp;
tmp->next = ptr;
tail->next = head;
} else {
for(int i = 1; i < pos - 1; i++)
ptr = ptr->next;
node *ptr1 = NULL;
ptr1 = ptr->next;
ptr->next = tmp;
tmp->next = ptr1;
}
}
void Deletion(int pos) {
node *temp = head;
if(pos == 1) {
head = head->next;
delete temp;
tail->next = head;
} else {
for(int i = 0; i < pos - 2; i++)
temp = temp->next;
node *temp2 = temp->next;
temp->next = temp->next->next;
delete temp2;
}
}
void reverse() {
node *pre, *in, *next;
pre = head;
in = NULL;
next = NULL;
while(pre->next != head) {
next = pre->next;
pre->next = in;
in = pre;
pre = next;
}
pre->next = in;
head->next = pre;
head = pre;
}
~CLL() {
std::cout << "\nThank u...";
}
};
int main() {
std::cout << "\n*****Presenting Circular Linked List*****";
CLL ob1;
std::cout << "\nThe number of elements u want to insert in the Linked List: ";
int n;
std::cin >> n;
ob1.addNode(n);
std::cout << "\nNow the linked list is: \n";
ob1.display();
while(1) {
int ch;
std::cout << "\n1.Search An Element\n2.Insertion\n3.Deletion\n4.Reversing\n5.exit";
std::cout << "\nPlease enter ur Choice: ";
std::cin >> ch;
switch(ch) {
case 1:
int k;
std::cout << "\nEnter the elment to search: ";
std::cin >> k;
ob1.search(k);
break;
case 2:
int posI, x;
std::cout << "\nEnter the position to insert element: "; 
std::cin >> posI;
std::cout << "\nEnter the NEW DATA to insert: "; 
std::cin >> x;
ob1.Insert(posI, x);
std::cout << "\nNOW the UPDATED linked list AFTER insertion:\n";
ob1.display();
break;
case 3:
int posD;
std::cout << "\nEnter the position u want to DELETE: "; 
std::cin >> posD;
ob1.Deletion(posD);
std::cout << "\nNOW the UPDATED linked list AFTER deletion:\n";
ob1.display();
break;
case 4:
ob1.reverse();
std::cout << "\nThe reversed Linked List is:\n"; 
ob1.display();
break;
case 5:
std::cout << "End" << std::endl;
break;
default:
std::cout << "Sorry! Invalid Choice ";
break;
}
if(ch == 5)
break;
}
return 0;
}
