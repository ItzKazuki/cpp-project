#include <iostream>
#include <string>

using namespace std;

class Sword {
    public:
        std::string name;
        int damage;
        int level;

        Sword(const std::string name, int damage, int level) {
            this->name = name;
            this->damage = damage;
            this->level = level;
        }
};

class Drink {
    public:
        std::string name;
        int drink_value; // ga boleh lebih dari 40
        bool is_expired = false;

        Drink(const std::string& name, int drink_value, bool is_exp) {
            this->name = name;
            this->drink_value = drink_value;
            this->is_expired = is_exp;
        }
};

class Food {
    public:
        std::string name;
        int food_value; // ga boleh > 40
        bool is_expired = false;

        Food(const std::string& name, int food_value, bool is_exp) {
            this->name = name;
            this->food_value = food_value;
            this->is_expired = is_exp;
        };
};

// class ini mempunyai properti nama, umur, status, health, hugry_level
class Player {
    // encapsulation: yang ada di dalam private tidak dapat di akses ke luar
    private: 
        std::string name; // mending pake std::string daripada char, char ribet soalnya.
        int umur;
        std::string status;
        int health = 100; // default value
        int hungry_level = 100;
        int thirsty_level = 100;
        std::string emotion = "happy";
        int stars = 1;
        int level = 1;
        Sword userSword = Sword("pedangKayu", 5, 1);

        // this method use getter setter and encapsulation
        void decereaseHungry(int value) {
            this->hungry_level -= value;
        }

        // this method use getter setter and encapsulation
        void decereaseThirsty(int value) {
            this->thirsty_level -= value;
        }

        // this method use getter setter and encapsulation
        void decereaseHealth(int value) {
            this->health -= value;
        }

        void inceraseHealth(int value) {
            this->health += value;
        }

        void incereaseLevel(Food food) {
            if(food.food_value >= 10 && food.food_value <= 14) {
                this->level += 1;
            }

            if(food.food_value >= 15 && food.food_value <= 19) {
                this->level += 1.5;
            }

            if(food.food_value >= 20 && food.food_value <= 24) {
                this->level += 2;
            }

            if(food.food_value >= 25 && food.food_value <= 29) {
                this->level += 2.5;
            }

            if(food.food_value >= 30 && food.food_value <= 34) {
                this->level += 3;
            }

            if(food.food_value >= 35 && food.food_value <= 39) {
                this->level += 4;
            }

            if(food.food_value == 40) {
                this->level += 5;
            }
        }

        // di cek kalo exp(food nya) bakalan ngurangin health 3x dari food_value nya
        void inceraseHungry(Food food) {
            // dicek kalo food_value nya > 25 / 35 change emotion ke happy (kan makannanya enak)
            if(food.is_expired) {
                this->emotion = "angry";
                this->decereaseHealth(food.food_value * 3);
                this->decereaseHungry(food.food_value * 2);
            } else {
                this->hungry_level += food.food_value;
                this->incereaseLevel(food);
            }
        }

        void incereasethirsty(Drink drink) {
            if(drink.is_expired) {
                this->emotion = "angry";
                this->decereaseHealth(drink.drink_value * 2);
                this->decereaseThirsty(drink.drink_value * 4);
            } else {
                this->thirsty_level += drink.drink_value;
            }
        }

        void checkHealth() {
            // dicek kaloo haus < 25 health berkurang 10%, < 20 berkurang 15% dst.. (10 % dari t
            if(this->thirsty_level <= 25) {
                this->health -= this->health * (10 / 100);
            }
            // dicek kalo laper < 30 healt berkurang 5%, dst
            if(this->hungry_level <= 30) {
                this->health -= this->health * (5 / 100);
            }
            // dicek darah nya kalo udh 0 maka di set status meninggal, atau di hapus lewat descructor
            if(this->health == 0) {
                // destruct
            }
        }

        void checkEmotion() {
            // kalo health < 50
            if(this->health <= 50) {
                this->emotion = "sad";
            }
            // kalo haus < 30
            if(this->thirsty_level <= 30) {
                this->emotion = "sad";
            }
            // kalo laper < 50
            if(this->hungry_level <= 50) {
                this->emotion = "sad";
            }
        }

        // todo: bikin destructor buat delete object nya.

    // bisa diakses oleh siapa saja
    public:
        // constructor
        Player(const std::string& name, int umur, const std::string& status) {
            this->name = name;
            this->umur = umur;
            this->status = status;
        };

        // method getter bisa di kenali dengan awalan "get"
        void getPlayerInfo() {
            this->checkHealth(); // buat cek health nya
            this->checkEmotion(); // buat cek emotion nya

            cout << "========= User Info ==========" <<endl;
            cout << "Name: " << this->name <<endl;
            cout << "Umur: " << this->umur <<endl;
            cout << "Alat Perang: " << this->userSword.name <<endl;
            cout << "Level: " << this->level <<endl;
            cout << "Emotion: " << this->emotion <<endl;
            cout << "Status: " << this->status <<endl;
            cout << "Health: " << this->health <<endl;
            cout << "Hungry Level: " << this->hungry_level <<endl;
            cout << "Thirsty Level: " << this->thirsty_level <<endl;
            cout << "========= End User Info ==========" <<endl;
            cout << "\n" <<endl;
            // selain cout ada printf, namun sesuai kondisi digunakannya.
        }

        void setSword(Sword sword) {
            this->userSword = sword;
        }

        // method untuk makan
        void eating(Food food) {
            this->inceraseHungry(food);
            cout << "sedang memakan " << food.name << "\n" <<endl;
        }

        // method untuk minum
        void drinking(Drink drink) {
            this->incereasethirsty(drink);
            cout << "sedang meminum " << drink.name << "\n" <<endl;
        }

        void runing(int speed) {
            // kalo dia lari, maka ngurangin hungry level dan thirsty_level (speed 5 = 7,10 speed 10 10, 20 speed 15 15, 35) (spped this->speed hungry, thristy)

            if(speed >= 16) {
                cout << "Tidak ada player yang speed nya lebih dari " << speed  << "\n" <<endl;
            }

            if(speed == 0) {
                cout << "Player sedang tidak berlari " << "\n" <<endl;
            }

            if(speed <= 5) {
                this->decereaseHungry(7);
                this->decereaseThirsty(10);
                cout << "Player sedang berlari dengan speed " << speed << "\n" <<endl;
            } 

            if(speed >= 6 && speed <= 10) {
                this->decereaseHungry(10);
                this->decereaseThirsty(20);
                cout << "Player sedang berlari dengan speed " << speed << "\n" <<endl;
            } 

            if(speed >= 11 && speed <= 15) {
                this->decereaseHungry(15);
                this->decereaseThirsty(35);
                cout << "Player sedang berlari dengan speed " << speed << "\n" <<endl;
            }
        }

        void sleeping(int time) {
            // if(int)
            this->inceraseHealth(20);
        }

        void getDamage(Sword sword) {
            this->decereaseHealth(sword.damage);
        }

        void attack(Player opponent) {
            if(opponent.level >= this->level) {
                // kurangin darah dengan alat yang dia pegang
           //     opponent.getDamage(this->userSword);
               cout << "tidak bisa menyerang " << opponent.name << "karena perbedaan level "<<endl; 
            }
		// ga bisa ngurangin darah musuh karena 
            
            this->getDamage(opponent.userSword);
        }
};

int main() {
    // buat alat perang
    Sword pedangBesi("pedangBesi", 10, 5);

    // params: nama, umur, status
    Player andi("Andi", 16, "Pengembara");
    Player npc1("yudi", 14, "Deamon");


    // params: name_food, food_value, is_expired
    Food ayamGeprek("Ayam Geprek", 10, false);
    Drink esKelapa("Es Kelapa", 15, false);

    // contoh encapsulation
    // cout << "Name: " << andi.name <<endl; // ga bisa di akses, inaccesable
    // ayamGeprek.name;

    andi.getPlayerInfo(); // method ini bisa di akses karena berada dipublic
    andi.runing(10);
    andi.getPlayerInfo();
    andi.eating(ayamGeprek);
    andi.getPlayerInfo();
    andi.setSword(pedangBesi);
    andi.drinking(esKelapa);
    andi.getPlayerInfo();
    andi.runing(13);
    andi.getPlayerInfo();
    andi.attack(npc1); // aneh, gua ga bisa nyerang dia, harus dia yang nyerang gua.
    npc1.getPlayerInfo();

    // todo: buat switch case di mana user bisa pilih pilihan 1, 2, 3 etc dan bisa cek health, playerInfo, etc dah lewat console/ cmd/ cli.

    return 1;
}   
