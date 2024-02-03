#include <iostream>
#include <string>

using namespace std;

// ini contoh pake constructor
class Buah {
    private: 
        string nama; // ini naruh isi teks
        string warna;
        int nutrisi; // ini buat nomor
    public:
        // constructor
        Buah(string nama, string warna, int nutrisi) {
            this->nama = nama;
            this->warna = warna;
            this->nutrisi = nutrisi;
        }

        // method 
        void getInfoBuah() {
            cout << "Nama Buah: " << this->nama <<endl;
            cout << "Nama Warna: " << this->warna <<endl;
            cout << "Nama Nutrisi: " << this->nutrisi <<endl;
        }
};

// perbedaan void dan int

int main() {
    string namaBuah;
    string warnaBuah;
    int nutrisiBuah;

    cout << "buahPertama";
    cout << "Masukan nama buah: ";
    getline(cin, namaBuah);
    // cin >> namaBuah;

    cout << "Masukan warna buah: ";
    getline(cin, warnaBuah);

    cout << "Masukan nutrisi buah: ";
    // getline(cin, namaBuah);

    cin >> nutrisiBuah;

    cout <<endl;


    Buah buahPertama(namaBuah, warnaBuah, nutrisiBuah);
    buahPertama.getInfoBuah();

    return 1;
}