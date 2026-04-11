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

struct penumpang {
    string nama_pen;
    string asal_pen;
    string tujuan_pen;
    int idx_kereta;
};

kereta_api kereta[MAX];
int queue[MAX], front = -1,rear = -1;
penumpang penumpang_queue[MAX];
penumpang riwayat[MAX];
int top = -1;
int jmlhkereta = 0;
bool isFull(){
    return rear == MAX-1;
}
bool isEmpty(){
    return front == -1;
}
bool stackFull(){
    return top == MAX-1;
}

void enqueque(penumpang p){
    if(isFull()){
        cout << "!!! antrian penuh !!!" << endl;
        return;
    }
    if(front == -1) front = 0;
    rear++;
    *(penumpang_queue + rear) = p;
    cout << ">> tiket berhasil masuk antrian ke_" << (rear + 1) << " <<" << endl;
}

void prosestiket(){
    if(isEmpty()){
        cout << "!!! antrian kosong !!!" << endl;
        return;
    }
    penumpang p = *(penumpang_queue + front);
    cout << "==================================" << endl;
    cout << "          Tiket Diproses " << endl;
    cout << "==================================" << endl;
    cout << "Nama: " << p.nama_pen << endl;
    cout << "Rute: " << p.asal_pen << " - " << p.tujuan_pen << endl;
    if(p.idx_kereta != -1){
        kereta_api* k = kereta + p.idx_kereta;
        cout << "Nama kereta: " << kereta[p.idx_kereta].nama << endl;
        cout << "Kode kereta: " << kereta[p.idx_kereta].kode << endl;
        cout << "Jam keberangkatan: " << kereta[p.idx_kereta].jam << endl;
        cout << "Harga: " << kereta[p.idx_kereta].harga << endl;    
    }
    cout << "==================================" << endl;

    if(stackFull()){
        cout << "!!! stack riwayat penuh !!!" << endl;
    }else{
        top++;
        *(riwayat + top) = p;
    }
    if(front == rear){
        front = rear = -1;
    }else{
        front++;
    }
    cout << ">> Tiket berhasil diproses <<" << endl;
}

void antrian(){
    if(isEmpty()){
        cout << "!!! antrian kosong !!!" << endl;
        return;
    }
    cout << "==================================" << endl;
    cout << "          ANTRIAN TIKET" << endl;
    cout << "==================================" << endl;
    cout << left << setw(5) << "No"
    << setw(15) << "Nama Penumpang"
    << setw(15) << "Asal"
    << setw(15) << "Tujuan" << endl;
    for(int i = front; i <= rear; i++){
        penumpang* p = penumpang_queue + i;
        cout << left << setw(5) << (i - front + 1)
        << setw(15) << p->nama_pen
        << setw(15) << p->asal_pen
        << setw(15) << p->tujuan_pen << endl;
    }
    cout << "==================================" << endl;
}

void tampilriwayat(){
    if(top == -1){
        cout << "!!! riwayat kosong !!!" << endl;
        return;
    }
    cout << "==================================" << endl;
    cout << "             RIWAYAT" << endl;
    cout << "==================================" << endl;
    for(int i = top; i >= 0; i--){
        penumpang* p = riwayat + i;
        cout << left << setw(5) << (top - i + 1)
        << setw(15) << p->nama_pen
        << setw(15) << p->asal_pen
        << setw(15) << p->tujuan_pen << endl;
    }
    cout << "==================================" << endl;
}

void popriwayat(){
    if(top < 0){
        cout << "!!! riwayat kosong !!!" << endl;
        return;
    }
    penumpang* p = riwayat + top;
    cout << "transaksi terakhir: \n";
    cout << left << setw(15) << "Nama Penumpang"
    << setw(15) << "Asal"
    << setw(15) << "Tujuan" << endl;
    cout << left << setw(15) <<  p->nama_pen 
    << setw(15) << p->asal_pen
    << setw(15) << p->tujuan_pen << endl;
    top--;  
}

void peekantrian(){
    if(isEmpty()){
        cout << "!!! antrian kosong !!!" << endl;
        return;
    }else{
        penumpang* p = penumpang_queue + front;
        cout << "antrian terdepan: \n";
        cout << left << setw(15) << "Nama Penumpang"
        << setw(15) << "Asal"
        << setw(15) << "Tujuan" << endl;
        cout << left << setw(15) << p->nama_pen
        << setw(15) << p->asal_pen
        << setw(15) << p->tujuan_pen << endl;
    }
}

void peekRiwayat(){
    if(top == -1){
        cout << "!!! Riwayat kosong !!!\n";
        return;
    }
    penumpang* p = riwayat + top;
    cout << "Transaksi terakhir: \n";
    cout << left << setw(15) << "Nama Penumpang"
    << setw(15) << "Asal"
    << setw(15) << "Tujuan" << endl;
    cout << left << setw(15) << p->nama_pen 
    << setw(15) << p->asal_pen
    << setw(15) << p->tujuan_pen << endl;
}

void belitiket(){
    if(jmlhkereta == 0){
        cout << "!!! Belum ada data kereta !!!" << endl;
        return;
    }
    penumpang p;
    string asal, tujuan;

    cout << "Nama Penumpang: ";
    getline(cin, p.nama_pen);
    cout << "Asal: ";
    getline(cin, p.asal_pen);
    cout << "Tujuan: ";
    getline(cin, p.tujuan_pen);

    int idx_cari = -1;
    for(int i = 0; i < jmlhkereta; i++){
        if(kereta[i].asal == p.asal_pen && kereta[i].tujuan == p.tujuan_pen){
            idx_cari = i;
            break;
        }
    }
    if(idx_cari == -1){
        cout << "!!! Rute tidak ditemukan !!!" << endl;
        return;
    }
    cout << "\n==================================" << endl;
    cout << "          DATA KERETA API " << endl;
    cout << "==================================" << endl;
    cout << "Nama: " << kereta[idx_cari].nama << endl;
    cout << "Kode: " << kereta[idx_cari].kode << endl;
    cout << "Jam:" << kereta[idx_cari].jam << endl;
    cout << "Harga: " << kereta[idx_cari].harga << endl;
    cout << "==================================" << endl;

    p.idx_kereta = idx_cari;
    enqueque(p);
}

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
        cout << "1.Jadwal Kereta\n2.Tambah Kereta\n3.Beli Tiket\n4.proses tiket\n5.Peek Antrian & Riwayat\n6.Riwayat Transaksi\n7.Pop Riwayat (Batalkan)\n8.Keluar" << endl;
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
                belitiket();
                antrian();
                system("pause");
                continue;
            case 4:
                prosestiket();
                system("pause");
                continue;
            case 5:
                peekantrian();
                cout <<  "==================================\n";
                peekRiwayat();
                system("pause");
                continue;
            case 6:
                tampilriwayat();
                system("pause");
                continue;
            case 7:
                popriwayat();
                system("pause");
                continue;
            case 8:
                cout << "TERIMA KASIH TELAH MENGUNAKAN PROGRAM SISTEM KERETA API";
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
                system("pause");
                continue;
        }
    }
}