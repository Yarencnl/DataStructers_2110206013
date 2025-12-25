#include <iostream>

using namespace std;

// Ders notlarındaki düğüm yapısının çift yönlü (double) versiyonu [cite: 97, 99]
struct Node {
    int data;       // Veri kısmı [cite: 98]
    Node* next;     // Sonraki düğümü gösteren işaretçi [cite: 99]
    Node* prev;     // Önceki düğümü gösteren işaretçi (Çift yönlü için eklendi)
};

// Listenin sonuna eleman ekleme (Ders notundaki addlast mantığı) [cite: 165, 173]
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
    while (last->next != nullptr) { // Son düğümü bulma [cite: 174, 175]
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

// ARAYA EKLEME: Belirli bir düğümden sonra ekler
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

// SİLME: Belirli bir düğümü listeden çıkarır
void deleteNode(Node** head_ref, Node* del) {
    if (*head_ref == nullptr || del == nullptr) return;

    // Silinecek düğüm başta ise
    if (*head_ref == del) {
        *head_ref = del->next;
    }

    // Silinecek düğüm sonda değilse, sonrakinin prev'ini güncelle
    if (del->next != nullptr) {
        del->next->prev = del->prev;
    }

    // Silinecek düğüm başta değilse, öncekinin next'ini güncelle
    if (del->prev != nullptr) {
        del->prev->next = del->next;
    }

    delete del; // Belleği serbest bırak
}

// TRAVERSAL: Listeyi hem ileri hem geri yazdırır
void printList(Node* node) {
    Node* last = nullptr;
    cout << "İleri Gezinti: ";
    while (node != nullptr) { // [cite: 200]
        cout << node->data << " "; // [cite: 201]
        last = node;
        node = node->next; // [cite: 202]
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

    // Listeye eleman ekleme
    addLast(&head, 10);
    addLast(&head, 20);
    addLast(&head, 30);

    cout << "İlk Liste:" << endl;
    printList(head);

    // Araya ekleme (10'dan sonra 15 ekle)
    insertAfter(head, 15);
    cout << "\n15 Eklendikten Sonra:" << endl;
    printList(head);

    // Silme (20 değerini sil - head->next->next düğümü)
    deleteNode(&head, head->next->next);
    cout << "\n20 Silindikten Sonra:" << endl;
    printList(head);

    return 0;
}