#include <iostream>
#include <string.h>

using namespace std;

class Cafe {
    private:
        string name;
        int reputation = 100;
        int staff = 1;
    public:
        Cafe(string name) {
            this->name = name;
        }

        void getCafeInfo() {
            cout << "Cafe Name: " << this->name <<endl;
            cout << "Cafe Reputation: " << this->reputation <<endl;
            cout << "Cafe Staff: " << this->staff <<endl;
        }
};

int main() {
    Cafe cafe1("myCafe");
    cafe1.getCafeInfo();
    cout << "Hello" <<endl;
}