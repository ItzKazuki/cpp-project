#include <iostream>
#include <string.h>

using namespace std;

class Buah {
    public:
        string nama;
        string famili;
        string rasa;
        string jenis;

        Buah(string nama, string famili, string rasa, string jenis) {
            this->nama = nama;
            this->famili = famili;
            this->rasa = rasa;
            this->jenis = jenis;
        }

        void getInfoBuah() {
            cout << "Nama Buah: " << this->nama <<endl;
            cout << "Famili Buah: " << this->famili <<endl;
            cout << "Rasa Buah: " << this->rasa <<endl;
        }
};

int main() {
    Buah apelMerah("apel", "something", "manis", "berserat");
    apelMerah.getInfoBuah();
    return 1;
}