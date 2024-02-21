#include <iostream>
using namespace std;
struct node {
    int coeff;
    int expo;
    struct node* next;
};
node* insert(node* head, int co, int ex) {
    node* temp = new node();
    temp->coeff = co;
    temp->expo = ex;
    temp->next = NULL;

    if (head == NULL || ex > head->expo) {
        temp->next = head;
        head = temp;
    } else {
        node* curr = head;
        while (curr->next != NULL && curr->next->expo >= ex)
            curr = curr->next;
        temp->next = curr->next;
        curr->next = temp;
    }
    return head;
}

node* create() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    node* head = NULL;
    for (int i = 0; i < n; i++) {
        int coeff, expo;
        cout << "Enter the coefficient for term " << i + 1 << ": ";
        cin >> coeff;
        cout << "Enter the exponent for term " << i + 1 << ": ";
        cin >> expo;
        head = insert(head, coeff, expo);
    }
    return head;
}

void print(node* head) {
    if (head == NULL)
        cout << "No Polynomial.";
    else {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->coeff << "x^" << temp->expo;
            temp = temp->next;
            if (temp != NULL)
                cout << " + ";
            else
                cout << endl;
        }
    }
}

node* polyadd(node* head1, node* head2) {
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* head3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->expo == ptr2->expo) {
            head3 = insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } else if (ptr1->expo > ptr2->expo) {
            head3 = insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        } else {
            head3 = insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != NULL) {
        head3 = insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL) {
        head3 = insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }
    return head3;
}

int main() {
    cout << "Enter the first polynomial" << endl;
    node* head1 = create();
    cout << "Enter the second polynomial" << endl;
    node* head2 = create();

    node* result = polyadd(head1, head2);
    cout << "Added polynomial is: ";
    print(result);

    // Free memory
    node* temp;
    while (head1 != NULL) {
        temp = head1;
        head1 = head1->next;
        delete temp;
    }
    while (head2 != NULL) {
        temp = head2;
        head2 = head2->next;
        delete temp;
    }
    while (result != NULL) {
        temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}
