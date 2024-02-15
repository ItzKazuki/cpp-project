#include <iostream>
#include <string>

using namespace std;

class Sepatu {
    public:
        string warna;

        // constructor
        Sepatu(const char* warna){
            // Constructor adalah function khusus yang 
            // di jalankan secara otomatis pada saat sebuah objek dibuat.
            this->warna = warna;

            cout << "sepatu " << this->warna << " Di Buat" << endl;
        }

        // destructor
        ~Sepatu(){
            // Destructor adalah function khusus yang 
            // di jalankan secar otomatis pada saat sebuah objek di hapus.
            cout << "sepatu " << Sepatu::warna << " Di hapus" << endl;
        }
};

void membuatSepatuStack() {
   Sepatu stackSepatu("stack");
   // setelah ini cpp akan langsung mengeksekusi destructor
};

void membuatSepatuHeap() {
    // ini adalah cara special agar destruct tidak di jalankan
    // secara otomatis oleh cpp.
    Sepatu* heapSepatu = new Sepatu("heap");
}

int main(int argc, char const *argv[]) {
    membuatSepatuStack(); // setelah ini destruct akan di jalankan otomatis oleh cpp.
    membuatSepatuHeap();       
    return 0;
}