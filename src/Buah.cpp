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

class Monitor {
    private:
        string model;
        int pixel, frame_rate;
    public:
        Monitor(string model, int pixel, int frame_rate) {
            this->model = model;
            this->pixel = pixel;
            this->frame_rate = frame_rate;
        }

        void getMonitorInformasi() {
            cout << "Model: " << this->model <<endl;
            cout << "Jumlah Pixel: " << this->pixel << "px" <<endl;
            cout << "Frame Rate: " << this->frame_rate << "Hz" <<endl;
        }

        // generic type.
        template <typename Any>
        void tampilkan(Any any) {
            cout << any <<endl;
        }

        void tampilkan2(string any) {
            cout << any <<endl;
        }
};

int main() {
    // Buah apelMerah("apel", "something", "manis", "berserat");
    // apelMerah.getInfoBuah();
    Monitor monitor1("Rog", 2000, 120);
    monitor1.getMonitorInformasi();
    monitor1.tampilkan<int>(1234);
    monitor1.tampilkan2("aaaa");

    cin.get();
    return 1;
}