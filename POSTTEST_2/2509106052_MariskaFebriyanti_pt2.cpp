#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;

#define MAX 10

struct kereta_api {
    string nama;
    string kode;
    string asal;
    string tujuan;
    float jam;
    int harga;
};

kereta_api kereta[MAX];
int jmlhkereta = 0;

int carirute(kereta_api* arr, int n, string asal, string tujuan){
    for (int i = 0; i < n; i++) {
        cout << "iterasi " << (i+1) << ":" << endl;
        cout << "[" << i << "]" << (arr + i)->asal << " - " << (arr + i)->tujuan << endl;
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "ditemukan pada index ke " << i;
            return i;
        }
    }
    cout << "\nKereta tidak ditemukan\n";
    return -1;
}

int carikode(string target){
    if (jmlhkereta == 0) return -1;
    int n = jmlhkereta;
    int step = sqrt(n);
    int prev = 0;
    while (prev < n && kereta[min(step, n)-1].kode < target) {
        prev = step;
        step += (int)sqrt(n);
        if (prev >= n) return -1;
    }
    int batas = step;
    if (batas > n) batas = n;
    while (prev < batas){
        if(kereta[prev].kode == target){
            return prev;
        }
        prev++;
    }
    return -1;
}

void nama(kereta_api* arr, int left, int right, int mid){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    kereta_api* L = new kereta_api[n1];
    kereta_api* R = new kereta_api[n2];

    for (int i = 0; i < n1; i++){
        *(L + i) = *(arr + left + i);
    }
    for (int j = 0; j < n2; j++){
        *(R + j) = *(arr + mid + 1 + j);
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        if((L + i)->nama <= (R + j)->nama){
            *(arr + k) = *(L + i);
            i++;
        }else{
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }
    while (i < n1){
        *(arr + k) = *(L + i);
        i++;k++;
    }
    while (j < n2){
        *(arr + k) = *(R + j);
        j++;k++;
    }
    delete[] L;
    delete[] R;
}

void namasort(kereta_api*& arr, int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        namasort(arr, left, mid);
        namasort(arr, mid + 1, right);
        nama(arr, left, right, mid);
    }
}

void harga(kereta_api* arr, int n){
    for (int i = 0; i < n - 1; i++){
        int min_idx = i;
        for (int j = i + 1; j < n; j++){
            if ((arr + j)->harga < (arr + min_idx)->harga){
                min_idx = j;
            }
        }
        kereta_api temp = *(arr + i);
        *(arr + i) = *(arr + min_idx);
        *(arr + min_idx) = temp;
    }
}

int main(){
    while (true){
        system("cls");
        cout << "STASIUN KERETA API" << endl;
        cout << "1.Jadwal\n2.Tambah\n3.Keluar" << endl;
        cout << "Masukkan pilihan :";
        int pilihan;
        if(!(cin >> pilihan)){
            cout << "INPUT HARUS BERUPA ANGKA" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            continue;
        }
        system("cls");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (pilihan){
            case 1:
                cout << "\n MENU:\n1.Semua \n2.Rute \n3.kode \n4.Nama \n5.harga\n> ";
                int p2;
                if(!(cin >> p2)){
                    cout << "INPUT HARUS BERUPA ANGKA" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    system("pause");
                    continue;
                }
                system("cls");
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                switch (p2){
                    case 1:
                        if (jmlhkereta == 0) cout << "Kosong!\n";
                        else {
                            cout << "DAFTAR KERETA API:\n";
                            cout << left << setw(5) << "No"
                            << setw(15) << "Nama Kereta"
                            << setw(10) << "Kode"
                            << setw(10) << "Asal"
                            << setw(15) << "Tujuan"
                            << setw(10) << "Harga" << endl;
                            cout << "============================================================\n";

                            for (int i = 0; i < jmlhkereta; i++) {
                                cout << left << setw(5) << i+1
                                << setw(15) << kereta[i].nama
                                << setw(10) << kereta[i].kode
                                << setw(10) << kereta[i].asal
                                << setw(15) << kereta[i].tujuan
                                << setw(10) << kereta[i].harga << endl;
                            }
                            cout << "============================================================\n";
                        }
                        system("pause");
                        continue;
                    case 2:
                        if (jmlhkereta > 0) {
                            string asal, tujuan;
                            cout << "Masukkan asal: ";
                            cin >> asal;
                            cout << "Masukkan tujuan: ";
                            cin >> tujuan;
                            int idx = carirute(kereta, jmlhkereta, asal, tujuan);

                            if (idx != -1){
                                cout << "\nDATA KERETA:\n";
                                cout << "Nama   : " << kereta[idx].nama << endl;
                                cout << "Kode   : " << kereta[idx].kode << endl;
                                cout << "Rute   : " << kereta[idx].asal << " - " << kereta[idx].tujuan << endl;
                                cout << "Jam    : " << kereta[idx].jam << endl;
                                cout << "Harga  : Rp" << kereta[idx].harga << endl;
                            }
                        } else{
                            cout << "Kosong!\n";
                        }
                        system("pause");
                        continue;
                    case 3:
                        if (jmlhkereta > 0) {
                            string kode;
                            cout << "Masukkan kode: ";
                            cin >> kode;
                            int idx = carikode(kode);
                            if (idx == -1){
                                cout << "Kereta tidak ditemukan\n";
                            }else{
                                cout << "\nDATA KERETA:\n";
                                cout << "Nama   : " << kereta[idx].nama << endl;
                                cout << "Kode   : " << kereta[idx].kode << endl;
                                cout << "Rute   : " << kereta[idx].asal << " - " << kereta[idx].tujuan << endl;
                                cout << "Jam    : " << kereta[idx].jam << endl;
                                cout << "Harga  : Rp" << kereta[idx].harga << endl;
                            }
                        } else{
                            cout << "Kosong!\n";
                        }
                        system("pause");
                        continue;
                    case 4:
                        if (jmlhkereta > 0) {
                            kereta_api* ptr_kereta = kereta;
                            namasort(ptr_kereta, 0, jmlhkereta-1);
                            cout << "\nNama kereta urut (A-Z):\n";
                            cout << left << setw(5) << "No"
                            << setw(15) << "Nama Kereta"
                            << setw(10) << "Kode"
                            << setw(10) << "Asal"
                            << setw(15) << "Tujuan"
                            << setw(10) << "Harga" << endl;
                            for (int i = 0; i < jmlhkereta; i++){
                                cout << left << setw(5) << i+1
                                << setw(15) << kereta[i].nama
                                << setw(10) << kereta[i].kode
                                << setw(10) << kereta[i].asal
                                << setw(15) << kereta[i].tujuan
                                << setw(10) << kereta[i].harga << endl;
                            }
                        } else{
                            cout << "Kosong!\n";
                        }
                        system("pause");
                        continue;
                    case 5:
                        if (jmlhkereta > 0) {
                            harga(kereta, jmlhkereta);
                            cout << "\n harga kereta urut (termurah ke termahal):\n";
                            cout << left << setw(5) << "No"
                            << setw(15) << "Nama Kereta"
                            << setw(10) << "Kode"
                            << setw(10) << "Asal"
                            << setw(15) << "Tujuan"
                            << setw(10) << "Harga" << endl;
                            for (int i = 0; i < jmlhkereta; i++){
                                cout << left << setw(5) << i+1
                                << setw(15) << kereta[i].nama
                                << setw(10) << kereta[i].kode
                                << setw(10) << kereta[i].asal
                                << setw(15) << kereta[i].tujuan
                                << setw(10) << kereta[i].harga << endl;
                            }
                        } else{
                            cout << "Kosong!";
                        }
                        system("pause");
                        continue;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                        system("pause");
                        continue;
                }
                system("pause");
                continue;
            case 2:
                if (jmlhkereta < MAX){
                    cout << "Nama Kereta : ";
                    getline(cin, kereta[jmlhkereta].nama);
                    cout << "Kode Kereta : "; 
                    cin >> kereta[jmlhkereta].kode;
                    cout << "Asal : ";
                    cin.ignore();
                    getline(cin, kereta[jmlhkereta].asal);
                    cout << "Tujuan : "; 
                    getline(cin, kereta[jmlhkereta].tujuan);
                    cout << "Jam : ";  
                    cin >> kereta[jmlhkereta].jam;
                    cout << "Harga :"; 
                    cin >> kereta[jmlhkereta].harga;
                    jmlhkereta++;
                    cout << "OK! (" << jmlhkereta << "/" << MAX << ")\n";
                } else{
                    cout << "Penuh!\n";
                }
                system("pause");
                continue;
            case 3:
                cout << "TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI";
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
                system("pause");
                continue;
        }
    }
}