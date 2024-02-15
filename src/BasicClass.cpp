#include <iostream>
#include <string> // untuk menggunakan string!

// agar menggunakan cout dan cin tanpa menggunakan static(::) seperti std::cout >> (gitu dah).

using namespace std;

// (khusus variable awalan nya huruf biasa, namun kalo class biasakan awalannya huruf KAPITAL)
class MyClass { // myClass disini adalah nama class yang kalian ingin buat.
    public: // kita sey variable di public (nanti lanjut di enkasulapsi)
        // biasanya di bawah class berisi PROPERTI dari class tersebut.
        string nama; // biasakan penulisan variable menggunakan CamelCase 
        int umur;
}; // jangan lupa titik koma!.


class Ac {
    public:
        string merek;
        string warna;
        string tipe_mesin;
        int kecepatan;

        Ac(string merek, string warna, string tipe_mesin, int kecepatan) {
            this->merek = merek;
            this->warna = warna;
            this->tipe_mesin = tipe_mesin;
            this->kecepatan = kecepatan;
        }

        // destruct: dijalankan paling terakhir 
        ~Ac() {
            // memberikan informasi bahwa object telah di hapus di memori
            cout << "Berhasil menghapus object dengan merek: " << this->merek <<endl;
        }
        
        void getInfo() {
            cout << "Merek: " << this->merek <<endl;
            cout << "Warna: " << this->warna <<endl;
            cout << "Tipe mesin: " << this->tipe_mesin <<endl;
            cout << "kecepatan: " << this->kecepatan  << "\n" <<endl;
        }
};

void tanpaConstructor() {
    Ac ac2("", "", "", 0); 
    ac2.merek = "Merek 2";
    ac2.warna = "hitam";
    ac2.tipe_mesin = "mesin 2";
    ac2.kecepatan = 50;

    ac2.getInfo();
}

void menggunakanConstructor() {
    Ac ac1("Test", "putih", "mesin 1", 500);
    ac1.getInfo();
}

int main() {
    // MyClass object1;
    // object1.nama = "yahaha";
    // object1.umur = 16;

    tanpaConstructor();
    menggunakanConstructor();

    return 1; // setelah ini, destruct akan di jalankan otomatis.
    // cout << "object 1 memiliki nama: " << object1.nama << " dan umur: " << object1.umur << endl;
}