#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Circular Linked List Toko Sembako
struct BarangNode {
    string namaBarang;
    int stok;
    BarangNode* next;

    // Constructor
    BarangNode(string nama, int jumlah) {
        namaBarang = nama;
        stok = jumlah;
        next = nullptr;
    }
};

// Fungsi insert di akhir Circular Linked List untuk membangun data
BarangNode* tambahBarang(BarangNode* head, string nama, int jumlah) {
    BarangNode* newNode = new BarangNode(nama, jumlah);
    if (head == nullptr) {
        newNode->next = newNode; // Menunjuk ke dirinya sendiri (Sirkuler)
        return newNode;
    }
    
    BarangNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

void tampilkanStokSembako(BarangNode* head) {
    if(head == nullptr){ // Mengecek apakah linked list kosong
        cout << "Gudang kosong" << endl; //jika kosong menampilkan output ini
        return; //keluar dari fungsi
    }
    BarangNode* temp = head; // Membuat pointer sementara untuk traversal
    do{ // kode di jalankan jika syarat(while) terpenuhi
        cout << temp->namaBarang << ": " << temp->stok << endl; // menampilkan nama barang dan stoknya
        temp = temp->next; //pindah ke node berikutnya
    }
    while(temp != head); // Perulangan berhenti jika temp kembali ke head
}

int main() {
    BarangNode* head = nullptr;
    
    head = tambahBarang(head, "Beras", 50);
    head = tambahBarang(head, "Minyak Goreng", 30);
    head = tambahBarang(head, "Gula Pasir", 20);
    head = tambahBarang(head, "Tepung Terigu", 15);

    cout << "Daftar Stok Sembako:" << endl;
    tampilkanStokSembako(head); 
    /* Harusnya output:
    - Beras: 50
    - Minyak Goreng: 30
    - Gula Pasir: 20
    - Tepung Terigu: 15
    */
    
    return 0;
}