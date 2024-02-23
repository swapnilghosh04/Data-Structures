#include <iostream>
struct node {
int data;
node *prv;
node *next;
};
class DLL {
private:
node *head, *tail;
public:
DLL() {
head = NULL;
tail = NULL;
}
void add_node(int n) {
int x;
for(int i = 1; i <= n; i++) {
std::cout << "\nDATA" << i << "=";
std::cin >> x;
node *tmp = new node;
tmp->data = x;
tmp->prv = NULL;
tmp->next = NULL;
if(head == NULL) {
head = tmp;
tail = tmp;
} else {
tail->next = tmp;
tmp->prv = tail;
tail = tail->next;
}
}
}
node *gethead() {
return head;
}
void Search(node *head_ref, int key) {
node *current = head_ref;
int c = 0;
bool Flag = false;
while(current != NULL) {
if(current->data == key) {
std::cout << "\nSearch Successful !!!";
Flag = true;
break;
} else
current = current->next;
c++;
}
if(Flag == true) {
c++;
std::cout << "\n"<< key << " is in Position " <<
c; } else
std::cout << "\n"<< key << " is not found";
}
void Insert(int pos, int x, int n, node *head_ref) {
if(pos <= n + 1) {
node *tmp = new node;
tmp->data = x;
tmp->prv = NULL;
tmp->next = NULL;
node *ptr = NULL;
ptr = head_ref;
if(pos == 1) {
head = tmp;
tmp->next = ptr;
tmp->prv = tmp;
} else {
for(int i = 1; i < pos - 1; i++) {
ptr = ptr->next;
}
node *ptrN = NULL;
ptrN = ptr->next;
ptr->next = tmp;
tmp->prv = ptr;
tmp->next = ptrN;
}
} else
std::cout << "\nSorry! Insertion is not possible.";
}
void Deletion(int pos, int n, node *head_ref) {
if(pos <= n) {
node *ptrN;
node *ptr = head_ref;
if(pos == 1) {
head = head_ref->next;
head->prv = NULL;
delete ptr;
} else {
for(int i = 1; i < pos - 1; i++) {
if(ptr->next != NULL) {
ptr = ptr->next;
}
}
ptrN = ptr->next;
ptr->next = ptr->next->next;
delete ptrN;
if(ptr->next != NULL) {
ptr->next->prv = ptr;
}
}
} else {
std::cout << "\nSorry! Deletion not possible.";
}
}
void reverse(node *head_ref) {
int i;
node *pre, *in, *next;
pre = head_ref;
in = NULL;
next = NULL;
while(pre != NULL) {
next = pre->next;
pre->next = in;
pre->prv = next;
in = pre;
pre = next;
}
head = in;
}
void display(node *head_ref) {
if(head_ref == NULL) {
std::cout << "NULL" << std::endl;
} else {
std::cout << head_ref->data << " ";
display(head_ref->next);
}
}
~DLL() {
std::cout << "\nThank U";
}
};
int main() {
std::cout << "\n*****Presenting Double Linked List Operations*****\n";
int n1;
std::cout << "\nEnter the number of elments to insert in the linked list: ";
std::cin >> n1;
DLL a;
a.add_node(n1);
std::cout << "\nNow the linked list is: \n";
a.display(a.gethead());
while(1) {
std::cout <<
"\n1.Searching\n2.Insertion\n3.Deletion\n4.Reverse\n5.EXIT \nEnter ur choice: ";
int ch;
std::cin >> ch;
switch(ch) {
case 1:
int key;
std::cout << "\n Enter the element to search: "; 
std::cin >> key;
a.Search(a.gethead(), key);
break;
case 2:
int p, x;
std::cout << "\nEnter the position to insert: "; 
std::cin >> p;
std::cout << "\nEnter the data: ";
std::cin >> x;
a.Insert(p, x, n1, a.gethead());
if(p <= n1 + 1) {
std::cout << "\nThe updated Linked List:\n"; 
a.display(a.gethead());
}
break;
case 3:
int pos;
std::cout << "\nEnter the position to delete: "; 
std::cin >> pos;
a.Deletion(pos, n1, a.gethead());
if(pos <= n1) {
std::cout << "\nNow the updated linked list is: \n"; 
a.display(a.gethead());
}
break;
case 4:
std::cout << "\nNow the reversed linked list is: \n"; 
a.reverse(a.gethead());
a.display(a.gethead());
break;
case 5:
std::cout << "end" << std::endl;
break;
default:
std::cout << "Sorry! Invalid Choice ";
}
if(ch == 5)
break;
}
return 0;
}
