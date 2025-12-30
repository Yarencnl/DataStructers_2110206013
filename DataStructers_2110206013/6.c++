//6.  Çembersel Linked list silme kodu, araya ekleme, traversal

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void printList(Node* last) {
    if (last == NULL) {
        cout << "Liste bos." << endl;
        return;
    }

    Node* temp = last->next;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != last->next);
    cout << "(Basa dondu)" << endl;
}

Node* addToEmpty(Node* last, int data) {
    if (last != NULL) return last;

    Node* newNode = new Node();
    newNode->data = data;
    last = newNode;
    last->next = last; 
    return last;
}

Node* addEnd(Node* last, int data) {
    if (last == NULL) return addToEmpty(last, data);

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    return last;
}

void insertAfter(Node* last, int item, int data) {
    if (last == NULL) return;

    Node* temp = last->next;
    do {
        if (temp->data == item) {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;

            if (temp == last) last = newNode; 
            cout << item << " değerinden sonra " << data << " eklendi." << endl;
            return;
        }
        temp = temp->next;
    } while (temp != last->next);

    cout << item << " listede bulunamadigi icin ekleme yapilamadi." << endl;
}

Node* deleteNode(Node* last, int key) {
    if (last == NULL) return NULL;

    Node *curr = last->next, *prev = last;

    if (curr == last && curr->data == key) {
        delete curr;
        return NULL;
    }

    if (curr->data == key) {
        prev->next = curr->next;
        delete curr;
        return last;
    }

    while (curr != last && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == key) {
        prev->next = curr->next;
        if (curr == last) last = prev; 
        delete curr;
        cout << key << " degeri silindi." << endl;
    } else {
        cout << key << " bulunamadigi icin silinemedi." << endl;
    }

    return last;
}

int main() {
    Node* last = NULL;

    last = addEnd(last, 10);
    last = addEnd(last, 20);
    last = addEnd(last, 30);

    cout << "Baslangic Listesi: ";
    printList(last);

    insertAfter(last, 20, 25); 
    printList(last);

    last = deleteNode(last, 10);
    printList(last);

    last = deleteNode(last, 30);
    printList(last);

    return 0;
}
