#include <iostream>
#include <string>

using namespace std;

// TODO: buat class backpack, dimana bisa input sword, shield, food, etc dah woaowkoakow
class Backpack
{
};

class RarityItems
{
private:
    int stars = 1;
    bool rare = false;

public:
    void setRare()
    {
        this->rare = true;
    }

    void setStars(int stars)
    {
        this->stars = stars;
    }

    bool getRarity()
    {
        return this->rare;
    }

    int getStars()
    {
        return this->stars;
    }
};

class Shield : public RarityItems
{
private:
    string name;     // nama dari tameng
    int health = 50; // health dari shield, jika dipakai berlebihan maka akan mengurangi health nya
    int defense;     // pertahanan yang dihasilkan.

    void setValue(string name, int defense, int stars)
    {
        this->name = name;
        this->defense = defense;
        this->setStars(stars);
    }

    void decerseHealth(int damage)
    {
        this->health -= damage;
    }

public:
    Shield(const string name)
    {
        this->setShield(name);
    }

    string getName()
    {
        return this->name;
    }

    // use this method only for get defense value
    int getDefense()
    {
        return this->defense;
    }

    // using this method can decerse health and return defencse value
    int useDefense(string playerName)
    {
        // harusnya di cek, level player, sword player nya juga, biar bisa di decerse health nny berdasarkan stars dari weapon si opponent
        cout << "\n"
             << playerName << " using shield \n"
             << endl;
        this->decerseHealth(5);
        return this->defense;
    }

    // int useDefense(Player player) {
    //     // harusnya di cek, level player, sword player nya juga, biar bisa di decerse health nny berdasarkan stars dari weapon si opponent
    //     cout << "\n" << player.getName() << " using shield \n" <<endl;
    //     this->decerseHealth(5);
    //     return this->defense;
    // }

    void setShield(string name)
    {
        if (name == "tamengKayu")
        {
            this->setValue(name, 5, 1);
        }
        else
        {
            cout << "can't find the shield.\n"
                 << endl;
            // this->~Shield();
        }
    }
};

class Sword : public RarityItems
{
private:
    string name; // nama pedang
    int health = 50;
    int damage; // damage yang dihasilkan pedang/

    void setValue(string name, int damage, int stars)
    {
        this->name = name;
        this->damage = damage;
        // this->stars = stars;
        this->setStars(stars);
    }

    void decerseHealth(int damage)
    {
        this->health -= damage;
    }

public:
    Sword(const string name)
    {
        this->setSword(name);
    }

    string getName()
    {
        return this->name;
    }

    // using this method only for getting damage
    int getDamage()
    {
        return this->damage;
    }
    // using this method to incerse health and return damage
    int useAttack(string playerName)
    {
        cout << "\n"
             << playerName << " using sword \n"
             << endl;
        // if health == 0, destruc self!
        this->decerseHealth(5);
        return this->damage;
    }

    void setSword(string name)
    {
        if (name == "pedangKayu")
        {
            // do something
            // if want to set item rare, use setRare();
            this->setValue(name, 5, 1);
        }
        else if (name == "pedangDiamond")
        {
            this->setRare();
            this->setValue(name, 20, 4);
        }
        else
        {
            // self destruct
            cout << "can't find the sword.\n"
                 << endl;
        }
    }
};

class Drink : public RarityItems
{
private:
    string name;             // nama minuman
    int drink_value;         // value dari minuman, ga boleh lebih dari 40
    bool is_expired = false; // expired dari minuman, kalo expired bisa bikin player meninggal

    void setValue(string name, int value, bool exp, int stars)
    {
        this->name = name;
        this->drink_value = value;
        this->is_expired = exp;
        // this->stars = star;
        this->setStars(stars);
    }

public:
    Drink(const string &name)
    {
        this->setDrink(name);
    }

    string getName()
    {
        return this->name;
    }

    int getDrinkValue()
    {
        return this->drink_value;
    }

    bool getExpired()
    {
        return this->is_expired;
    }

    void setDrink(string name)
    {
        if (name == "Es Kelapa")
        {
            // do something
            this->setValue(name, 15, false, 3);
        }
        else
        {
            // do something
        }
    }
};

// class food(makanan) dimana bisa incerse/decerse health player
class Food : public RarityItems
{
private:
    string name;             // nama makanan.
    int food_value;          // value dari makanan, ga boleh > 40.
    bool is_expired = false; // kalo expired dia bakal true.

    void setValue(string name, int value, bool exp, int stars)
    {
        this->name = name;
        this->food_value = value;
        this->is_expired = exp;
        // this->stars = stars;
        this->setStars(stars);
    }

public:
    Food(const string &name)
    {
        this->setFood(name);
    };

    string getName()
    {
        return this->name;
    }

    int getFoodValue()
    {
        return this->food_value;
    }

    bool getExpired()
    {
        return this->is_expired;
    }

    void setFood(string name)
    {
        if (name == "Ayam Geprek")
        {
            this->setValue(name, 10, false, 3);
        }
        else
        {
            // do something
        }
    }
};

class Emosi
{
private:
    string playerEmoticon = "happy";

public:
    void setEmosi(string emosi)
    {
        this->playerEmoticon = emosi;
    }

    string getEmosi()
    {
        return this->playerEmoticon;
    }
};

// class ini mempunyai berfungsi untuk membuat object person.
class Player : public Emosi
{
    // encapsulation: yang ada di dalam private tidak dapat di akses ke luar
private:
    string name;                                                                // nama player
    int umur, health = 100, hungry_level = 100, thirsty_level = 100, level = 1; // utility dari player
    string status;                                                              // status player, apakah pengembara, traveler, healer, etc.

    // set default sword dan shielddari player
    Sword userSword = Sword("pedangKayu");
    Shield userShield = Shield("tamengKayu");

    // this method use getter setter and encapsulation
    void decereaseHungry(int value)
    {
        this->hungry_level -= value;
    }

    // this method use getter setter and encapsulation
    void decereaseThirsty(int value)
    {
        this->thirsty_level -= value;
    }

    // this method use getter setter and encapsulation
    void decereaseHealth(int value)
    {
        this->health -= value;
    }

    // this method use getter setter and encapsulation
    void inceraseHealth(int value)
    {
        this->health += value;
    }

    void incereaseLevel(Food food)
    {
        if (food.getFoodValue() >= 10 && food.getFoodValue() <= 14)
        {
            this->level += 1;
        }

        if (food.getFoodValue() >= 15 && food.getFoodValue() <= 19)
        {
            this->level += 1.5;
        }

        if (food.getFoodValue() >= 20 && food.getFoodValue() <= 24)
        {
            this->level += 2;
        }

        if (food.getFoodValue() >= 25 && food.getFoodValue() <= 29)
        {
            this->level += 2.5;
        }

        if (food.getFoodValue() >= 30 && food.getFoodValue() <= 34)
        {
            this->level += 3;
        }

        if (food.getFoodValue() >= 35 && food.getFoodValue() <= 39)
        {
            this->level += 4;
        }

        if (food.getFoodValue() == 40)
        {
            this->level += 5;
        }
    }

    // di cek kalo exp(food nya) bakalan ngurangin health 3x dari getFoodValue() nya
    void inceraseHungry(Food food)
    {
        // dicek kalo getFoodValue() nya > 25 / 35 change emotion ke happy (kan makannanya enak)
        if (food.getExpired())
        {
            this->setEmosi("angry");
            this->decereaseHealth(food.getFoodValue() * 3);
            this->decereaseHungry(food.getFoodValue() * 2);
        }
        else
        {
            this->hungry_level += food.getFoodValue();
            this->incereaseLevel(food);
        }
    }

    void incereasethirsty(Drink drink)
    {
        if (drink.getExpired())
        {
            // this->emotion = "angry";
            this->setEmosi("angry");
            this->decereaseHealth(drink.getDrinkValue() * 2);
            this->decereaseThirsty(drink.getDrinkValue() * 4);
        }
        else
        {
            this->thirsty_level += drink.getDrinkValue();
        }
    }

    void checkHealth()
    {
        // dicek kaloo haus < 25 health berkurang 10%, < 20 berkurang 15% dst.. (10 % dari t
        if (this->thirsty_level <= 25)
        {
            this->health -= this->health * (10 / 100);
        }

        // dicek kalo laper < 30 healt berkurang 5%, dst
        if (this->hungry_level <= 30)
        {
            this->health -= this->health * (5 / 100);
        }

        // dicek darah nya kalo udh 0 maka di set status meninggal, atau di hapus lewat descructor
        if (this->health == 0)
        {
            // destruct
        }
    }

    void checkEmotion()
    {
        // kalo health < 50
        if (this->health <= 50)
        {
            // this->emotion = "sad";
            this->setEmosi("sad");
        }

        // kalo haus < 30
        if (this->thirsty_level <= 30)
        {
            // this->emotion = "sad";
            this->setEmosi("sad");
        }

        // kalo laper < 50
        if (this->hungry_level <= 50)
        {
            // this->emotion = "sad";
            this->setEmosi("sad");
        }
    }

    // todo: bikin destructor buat delete object nya.

    // bisa diakses oleh siapa saja
public:
    // constructor, accept name, age, stats player.
    Player(const string &name, int umur, const string &status)
    {
        this->name = name;
        this->umur = umur;
        this->status = status;
    };

    // Start Getter Setter

    // show information about player
    void getPlayerInfo()
    {
        this->checkHealth();  // buat cek health nya
        this->checkEmotion(); // buat cek emotion nya

        cout << "========= User Info ============" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Umur: " << this->umur << endl;
        cout << "Alat Perang: " << this->userSword.getName() << endl;
        cout << "Alat Perang: " << this->userShield.getName() << endl;
        cout << "Level: " << this->level << endl;
        cout << "Emotion: " << this->getEmosi() << endl;
        cout << "Status: " << this->status << endl;
        cout << "Health: " << this->health << endl;
        cout << "Hungry Level: " << this->hungry_level << endl;
        cout << "Thirsty Level: " << this->thirsty_level << endl;
        cout << "========= End User Info ==========" << endl;
        cout << "\n"
             << endl;
        // selain cout ada printf, namun sesuai kondisi digunakannya.
    }

    // method ini berfungsi untuk set/netapin new sword dari player.
    void setSword(Sword sword)
    {
        this->userSword = sword; // set new sword
    }

    // method ini berfungsi untuk set/netapin new shield dari player.
    void setShield(Shield shield)
    {
        this->userShield = shield;
    }

    // mendapatkan informasi sword dari player.
    Sword getSword()
    {
        return this->userSword;
    }

    // menampilkan nama player
    string getName()
    {
        return this->name;
    }

    // jika player mendapatkan penyerangan, maka kode ini akan dijalankan oleh player yang mendapat penyerangan.
    void getAttack(int attack)
    {
        this->decereaseHealth(attack - this->userShield.useDefense(this->name));
    }

    // End Getter Setter

    // method untuk makan
    void eating(Food food)
    {
        this->inceraseHungry(food);
        cout << "sedang memakan " << food.getName() << "\n"
            << endl;
    }

    // method untuk minum
    void drinking(Drink drink)
    {
        this->incereasethirsty(drink);
        cout << "sedang meminum " << drink.getName() << "\n"
            << endl;
    }

    // method untuk running / berlari
    void runing(int speed)
    {
        // kalo dia lari, maka ngurangin hungry level dan thirsty_level (speed 5 = 7,10 speed 10 10, 20 speed 15 15, 35) (spped this->speed hungry, thristy)

        if (speed >= 16)
        {
            cout << "Tidak ada player yang speed nya lebih dari " << speed << "\n"
                 << endl;
        }

        if (speed == 0)
        {
            cout << "Player sedang tidak berlari "
                 << "\n"
                 << endl;
        }

        if (speed <= 5)
        {
            this->decereaseHungry(7);
            this->decereaseThirsty(10);
            cout << "Player sedang berlari dengan speed " << speed << "\n"
                 << endl;
        }

        if (speed >= 6 && speed <= 10)
        {
            this->decereaseHungry(10);
            this->decereaseThirsty(20);
            cout << "Player sedang berlari dengan speed " << speed << "\n"
                 << endl;
        }

        if (speed >= 11 && speed <= 15)
        {
            this->decereaseHungry(15);
            this->decereaseThirsty(35);
            cout << "Player sedang berlari dengan speed " << speed << "\n"
                 << endl;
        }
    }

    // TODO: cek time nya, makin tinggi time nya makin besar juga health incerse/bertambah.
    // method untuk tidur
    void sleeping(int time)
    {
        // if(int)
        this->inceraseHealth(20);
    }

    void attack(Player *opponent)
    {
        // TODO:
        // cek apakah level nya sama / lebih besar dari level musuh
        // kalo lebih besar, yang getAttack adalah diri nya sendiri (this)
        // kalo lebih kecil / sama, maka akan saling menyerang.
        opponent->getAttack(this->getSword().useAttack(this->name));
    }
};

Player *createPlayer()
{
    string namaPlayer;
    int umurPlayer;
    string statusPlayer;

    cout << "Welcome to the game! \n";
    cout << "We need your information :>! \n";

    cout << "Masukan nama kamu: ";
    getline(cin, namaPlayer);
    // cin >> namaplayer;

    cout << "Masukan status kamu: ";
    getline(cin, statusPlayer);

    cout << "Masukan umur kamu: ";
    // getline(cin, namaplayer); // khusus string
    cin >> umurPlayer; // khusus int

    cout << endl;

    if (umurPlayer <= 12)
    {
        cout << "Tidak dapat membuat player, masih terlalu muda" << endl;
        // return createPlayer();
        exit(1);
    }

    Player *player = new Player(namaPlayer, umurPlayer, statusPlayer);
    return player;
}

int main()
{
    Player *player1 = createPlayer();
    player1->getPlayerInfo();

    Player *player2 = new Player("random1", 16, "yey");

    Sword swordDiamond("pedangDiamond");

    player1->setSword(swordDiamond);

    player1->attack(player2);

    player2->getPlayerInfo();
    player1->getPlayerInfo();

    cin.get();
    return 1;
}