#include "AlatLaboratorium.hpp"
#include <iostream>

using namespace std;

// Peran B (Implementer): implementasi method class AlatLaboratorium.

AlatLaboratorium::AlatLaboratorium(const string& nama, const string& kategori, int jumlah) {
    this->nama = nama;
    this->kategori = kategori;
    this->jumlah = (jumlah < 0) ? 0 : jumlah; // stok tidak boleh negatif
}

string AlatLaboratorium::getNama() const { return nama; }
string AlatLaboratorium::getKategori() const { return kategori; }
int AlatLaboratorium::getJumlah() const { return jumlah; }

void AlatLaboratorium::tampilkanInfo() const {
    cout << "Nama     : " << nama << endl;
    cout << "Kategori : " << kategori << endl;
    cout << "Jumlah   : " << jumlah << endl;
}

bool AlatLaboratorium::tambahJumlah(int n) {
    if (n <= 0) {
        cout << "[GAGAL] Jumlah penambahan harus lebih dari 0." << endl;
        return false;
    }
    jumlah += n;
    cout << "[OK] Stok " << nama << " bertambah " << n << ". Stok sekarang: " << jumlah << endl;
    return true;
}

bool AlatLaboratorium::kurangiJumlah(int n) {
    if (n <= 0) {
        cout << "[GAGAL] Jumlah pengurangan harus lebih dari 0." << endl;
        return false;
    }
    if (n > jumlah) {
        cout << "[GAGAL] Stok " << nama << " tidak cukup (tersedia " << jumlah << ")." << endl;
        return false;
    }
    jumlah -= n;
    cout << "[OK] Stok " << nama << " berkurang " << n << ". Stok sekarang: " << jumlah << endl;
    return true;
}
