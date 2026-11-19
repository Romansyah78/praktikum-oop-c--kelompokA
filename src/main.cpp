#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "AlatLaboratorium.hpp"

using namespace std;

// Peran C (Integrator): mengelola vector objek dan menu program.

void tampilkanDaftar(const vector<AlatLaboratorium>& daftar) {
    if (daftar.empty()) {
        cout << "Belum ada alat terdaftar." << endl;
        return;
    }
    cout << "=== DAFTAR ALAT LABORATORIUM ===" << endl;
    for (size_t i = 0; i < daftar.size(); i++) {
        cout << "[" << i + 1 << "]" << endl;
        daftar[i].tampilkanInfo();
        cout << "--------------------------------" << endl;
    }
}

// Mencari alat berdasarkan nama (tidak membedakan huruf besar/kecil sederhana: persis).
int cariAlat(const vector<AlatLaboratorium>& daftar, const string& nama) {
    for (size_t i = 0; i < daftar.size(); i++) {
        if (daftar[i].getNama() == nama) return (int)i;
    }
    return -1;
}

int bacaInt(const string& prompt) {
    int x;
    cout << prompt;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input harus angka. " << prompt;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
}

string bacaString(const string& prompt) {
    string s;
    cout << prompt;
    getline(cin, s);
    return s;
}

int main() {
    vector<AlatLaboratorium> daftar;

    // Data awal sesuai kasus: mikroskop, tabung reaksi, multimeter.
    daftar.push_back(AlatLaboratorium("Mikroskop", "Optik", 5));
    daftar.push_back(AlatLaboratorium("Tabung Reaksi", "Gelas", 40));
    daftar.push_back(AlatLaboratorium("Multimeter", "Elektronik", 8));

    int pilihan;
    do {
        cout << "\n===== MENU INVENTARIS LABORATORIUM =====" << endl;
        cout << "1. Tampilkan semua alat" << endl;
        cout << "2. Tambah alat baru" << endl;
        cout << "3. Tambah jumlah stok alat" << endl;
        cout << "4. Kurangi jumlah stok alat" << endl;
        cout << "5. Tampilkan info satu alat" << endl;
        cout << "0. Keluar" << endl;
        pilihan = bacaInt("Pilih menu: ");

        if (pilihan == 1) {
            tampilkanDaftar(daftar);
        } else if (pilihan == 2) {
            string nama = bacaString("Nama alat     : ");
            string kategori = bacaString("Kategori      : ");
            int jumlah = bacaInt("Jumlah awal    : ");
            if (cariAlat(daftar, nama) != -1) {
                cout << "[GAGAL] Alat dengan nama tersebut sudah ada (cegah data duplikat)." << endl;
            } else if (nama.empty()) {
                cout << "[GAGAL] Nama alat tidak boleh kosong." << endl;
            } else {
                daftar.push_back(AlatLaboratorium(nama, kategori, jumlah));
                cout << "[OK] Alat " << nama << " berhasil ditambahkan." << endl;
            }
        } else if (pilihan == 3 || pilihan == 4) {
            string nama = bacaString("Nama alat     : ");
            int idx = cariAlat(daftar, nama);
            if (idx == -1) {
                cout << "[GAGAL] Alat tidak ditemukan." << endl;
            } else {
                int n = bacaInt("Jumlah        : ");
                if (pilihan == 3) daftar[idx].tambahJumlah(n);
                else daftar[idx].kurangiJumlah(n);
            }
        } else if (pilihan == 5) {
            string nama = bacaString("Nama alat     : ");
            int idx = cariAlat(daftar, nama);
            if (idx == -1) cout << "[GAGAL] Alat tidak ditemukan." << endl;
            else daftar[idx].tampilkanInfo();
        } else if (pilihan != 0) {
            cout << "Menu tidak valid." << endl;
        }
    } while (pilihan != 0);

    cout << "Program selesai." << endl;
    return 0;
}
