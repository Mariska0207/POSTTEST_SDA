#include <iostream>
using namespace std; 

void tukarNilai(int *nilai1, int *nilai2){
    int temp = *nilai1;
    *nilai1 = *nilai2;
    *nilai2 = temp;
}

int main(){
    int nilai1, nilai2;
    cout << "masukkan nilai 1 : ";
    cin >> nilai1;
    cout << "masukkan nilai 2 : ";
    cin >> nilai2;
    
    cout << "sebelum ditukar: " << endl;
    cout << "Nilai1 = " << nilai1 << ", Nilai2 = " << nilai2 << endl;
    tukarNilai(&nilai1, &nilai2);
    cout << "sesudah ditukar: " << endl;
    cout << "Nilai1 = " << nilai1 << ", Nilai2 = " << nilai2 << endl;
    return 0;
}