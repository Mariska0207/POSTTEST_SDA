#include <iostream>
using namespace std; 

struct Mahasiswa{
    string nama;
    string NIM;
    float IPK;
};

int main(){
    Mahasiswa mahasiswa[5];
    for(int i=0; i<5; i++){
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama: " ;
        cin >> mahasiswa[i].nama;
        cout << "NIM: " ;
        cin >> mahasiswa[i].NIM;
        cout << "IPK: " ;
        cin >> mahasiswa[i].IPK;
    }
    
    float ipktertinggi = mahasiswa[0].IPK;
    for(int i=1; i<5; i++){
        if(mahasiswa[i].IPK > ipktertinggi){
            ipktertinggi = mahasiswa[i].IPK;
        }
    }
    
    cout << "\nMahasiswa dengan IPK tertinggi (" << ipktertinggi << "):" << endl;
    for(int i=0; i<5; i++){
        if(mahasiswa[i].IPK == ipktertinggi){
            cout << "--------------------------" << endl;
            cout << "Nama: " << mahasiswa[i].nama << endl;
            cout << "NIM: " << mahasiswa[i].NIM << endl;
            cout << "IPK: " << mahasiswa[i].IPK << endl;
        }
    }
    return 0;
}