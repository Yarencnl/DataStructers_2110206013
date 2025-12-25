// 1.  Sparse matrix dönüşümü

#include <iostream>
using namespace std;

int main() {
    int sparseMatrix[4][5] = {
        {0,0,1,2,0},
        {5,6,0,0,0},
        {0,0,0,0,0},
        {0,7,0,1,3}
    };
    int size = 0;
    for (int i = 0; i<4; i++) {
        for (int j=0; j<5; j++){
            if (sparseMatrix[i][j] != 0){
                size++;
            }
        }
    }
    int compactMatrix[size][3];
    int k = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            if (sparseMatrix[i][j] != 0){
                compactMatrix[k][0] = i;
                compactMatrix[k][1] = j;
                compactMatrix[k][2] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    cout << "Sparse Matrix Dönüşümü Sonrası:" << endl;
    cout << "Satır\tSütun\tDeğer" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << compactMatrix[i][0] << "\t" 
             << compactMatrix[i][1] << "\t" 
             << compactMatrix[i][2] << endl;
    }
    return 0;
}