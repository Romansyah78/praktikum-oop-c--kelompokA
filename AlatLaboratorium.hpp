#ifndef ALATLABORATORIUM_HPP
#define ALATLABORATORIUM_HPP

#include <string>

// Peran A (Lead Programmer): deklarasi class AlatLaboratorium.
// Seluruh atribut bersifat private (enkapsulasi) dan diakses lewat getter/method.
class AlatLaboratorium {
private:
    std::string nama;
    std::string kategori;
    int jumlah;

public:
    // Constructor
    AlatLaboratorium(const std::string& nama, const std::string& kategori, int jumlah);

    // Getter
    std::string getNama() const;
    std::string getKategori() const;
    int getJumlah() const;

    // Method utama
    void tampilkanInfo() const;
    bool tambahJumlah(int n);   // true jika berhasil
    bool kurangiJumlah(int n);  // true jika berhasil (stok cukup dan n > 0)
};

#endif
