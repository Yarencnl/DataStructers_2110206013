//7.  Array de ekleme silme işlemleri

#include <iostream>
using namespace std;

int main(){
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 0;
    int choice, value, position;

    while (true) {
        cout << "1. Ekleme\n2. Silme\n3. Göster\n4. Çıkış\nSeçiminiz: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Eklenecek değeri girin: ";
            cin >> value;
            cout << "Eklenecek pozisyonu girin (0-" << size << "): ";
            cin >> position;

            if (position < 0 || position > size || size >= MAX_SIZE) {
                cout << "Geçersiz pozisyon veya dizi dolu!" << endl;
                continue;
            }

            for (int i = size; i > position; i--) {
                arr[i] = arr[i - 1];
            }
            arr[position] = value;
            size++;
            cout << "Değer eklendi." << endl;

        } else if (choice == 2) {
            cout << "Silinecek pozisyonu girin (0-" << size - 1 << "): ";
            cin >> position;

            if (position < 0 || position >= size) {
                cout << "Geçersiz pozisyon!" << endl;
                continue;
            }

            for (int i = position; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            cout << "Değer silindi." << endl;

        } else if (choice == 3) {
            cout << "Dizi elemanları: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;

        } else if (choice == 4) {
            break;

        } else {
            cout << "Geçersiz seçim!" << endl;
        }
    }

    return 0;
}