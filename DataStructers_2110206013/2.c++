//2.  Hanoi Ödevi
#include <iostream>
using namespace std;

void hanoi(int n, char source, char dest, char aux) {
    if (n == 1) {
        cout << "Diski 1: " << source << " -> " << dest << endl;
        return;
    }

    hanoi(n - 1, source, aux, dest);

    cout << "Diski " << n << ": " << source << " -> " << dest << endl;

    hanoi(n - 1, aux, dest, source);
}

int main() {
    int n;
    cout << "Disk sayisini giriniz: ";
    cin >> n;

    cout << "\n--- Hamle Listesi ---\n" << endl;
    hanoi(n, 'A', 'C', 'B'); 

    return 0;
}