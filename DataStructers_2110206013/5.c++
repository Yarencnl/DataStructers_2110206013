// 5.  Double Linked list silme kodu, araya ekleme, traversal

#include <iostream>

using namespace std;

struct Node {
    int data;       
    Node* next;     
    Node* prev; 
};

void addLast(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void insertAfter(Node* prev_node, int new_data) {
    if (prev_node == nullptr) {
        cout << "Önceki düğüm NULL olamaz." << endl;
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;

    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != nullptr) {
        new_node->next->prev = new_node;
    }
}

void deleteNode(Node** head_ref, Node* del) {
    if (*head_ref == nullptr || del == nullptr) return;

    if (*head_ref == del) {
        *head_ref = del->next;
    }

    if (del->next != nullptr) {
        del->next->prev = del->prev;
    }

    if (del->prev != nullptr) {
        del->prev->next = del->next;
    }

    delete del;
}

void printList(Node* node) {
    Node* last = nullptr;
    cout << "İleri Gezinti: ";
    while (node != nullptr) {
        cout << node->data << " "; 
        last = node;
        node = node->next; 
    }

    cout << "\nGeri Gezinti: ";
    while (last != nullptr) {
        cout << last->data << " ";
        last = last->prev;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    addLast(&head, 10);
    addLast(&head, 20);
    addLast(&head, 30);

    cout << "İlk Liste:" << endl;
    printList(head);

    insertAfter(head, 15);
    cout << "\n15 Eklendikten Sonra:" << endl;
    printList(head);

    deleteNode(&head, head->next->next);
    cout << "\n20 Silindikten Sonra:" << endl;
    printList(head);

    return 0;
}