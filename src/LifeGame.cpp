#include <iostream>
#include <string>

using namespace std;

// TODO: buat class backpack, dimana bisa input sword, shield, food, etc dah woaowkoakow

// Dont forget concept DRY(Dont Repeat Yourself)

class RarityItems
{
private:
    int stars = 1;
    bool rare = false;

public:
    // class above can access private property for this class.
    friend class Sword;
    friend class Shield;
    friend class Food;
    friend class Drink;
    friend class Person;

    void setRare()
    {
        this->rare = true;
    }

    void setStars(int stars)
    {
        this->stars = stars;
    }
};

// to set params
class Items : public RarityItems {
private:
    string name;
    int value;
    bool is_expired = false;
public:
    // class player can access private property.
    friend class Player;
    friend class Person;

    void setValue(string name, int value, bool exp, int stars)
    {
        this->name = name;
        this->value = value;
        this->is_expired = exp;
        // this->stars = star;
        this->setStars(stars);
    } 
};

class AttackTools : public RarityItems {
private:
    string name; // nama pedang
    int health = 50;
    int damage; // damage yang dihasilkan pedang
public:
    // class player can access private property.
    friend class Player;
    friend class Person;

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

    // using this method to incerse health and return damage
    // 1st params for player who 
    template <typename Opponent1>
    int useAttack(Opponent1 player1)
    {
        cout << "\n" << player1.name << " using sword " << endl;
        cout << "\n" << player1.name << " attack with " << this->damage << "damage" << endl;
        // if(is_same<Opponent2, Monster>::value) {
        //     cout << "\n" << player1.name << " using shield \n" << endl;
        // } else {
        //     cout << "\n" << player1.name << " using shield \n" << endl;
        // }

        // if health == 0, destruc self!
        this->decerseHealth(5);
        return this->damage;
    }
};

class DefenseTools : public RarityItems {
private:
    string name;     // nama dari tameng
    int health = 50; // health dari shield, jika dipakai berlebihan maka akan mengurangi health nya
    int defense;     // pertahanan yang dihasilkan.

public:
    // class player can access private property.
    friend class Player;
    friend class Person;

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

    // using this method can decerse health and return defencse value
    // 1st param is person who using shield and 2nd params who person who attacking
    template <typename Opponent1>
    int useDefense(Opponent1 player)
    {
        // harusnya di cek, level player, sword player nya juga, biar bisa di decerse health nny berdasarkan stars dari weapon si opponent

        cout << "\n" << player.name << " using shield " << endl;
        cout << "\n" << player.name << " can hold "<< this->defense << " damage" << endl;
        this->decerseHealth(5);
        return this->defense;
    }
};

class Shield : public DefenseTools
{
public:
    Shield(const string name)
    {
        this->setShield(name);
    }

    void setShield(string name)
    {
        if (name == "tamengKayu")
        {
            this->setValue(name, 5, 1);
        }
        else
        {
            cout << "can't find the shield.\n" << endl;
            delete this; // destruct self;
        }
    }
};

class Sword : public AttackTools
{

public:
    Sword(const string name)
    {
        this->setSword(name);
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
            cout << "can't find the sword.\n" << endl;
            delete this; // self destruct
        }
    }
};

class Drink : public Items
{
public:
    Drink(const string &name)
    {
        this->setDrink(name);
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
class Food : public Items
{
public:
    Food(const string &name)
    {
        this->setFood(name);
    };

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

class Person {
public: 
    string name;                                                                // nama player
    int health = 100, hungry_level = 100, thirsty_level = 100;                  // utility dari player
    string status;                                                              // status player, apakah pengembara, traveler, healer, etc.
    string playerEmoticon = "happy";
    double level = 1;

    void setEmosi(string emosi)
    {
        this->playerEmoticon = emosi;
    }

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
        if (food.value >= 10 && food.value <= 14)
        {
            this->level += 1;
        }

        if (food.value >= 15 && food.value <= 19)
        {
            this->level += 1.5;
        }

        if (food.value >= 20 && food.value <= 24)
        {
            this->level += 2;
        }

        if (food.value >= 25 && food.value <= 29)
        {
            this->level += 2.5;
        }

        if (food.value >= 30 && food.value <= 34)
        {
            this->level += 3;
        }

        if (food.value >= 35 && food.value <= 39)
        {
            this->level += 4;
        }

        if (food.value == 40)
        {
            this->level += 5;
        }
    }

    // di cek kalo exp(food nya) bakalan ngurangin health 3x dari value nya
    void inceraseHungry(Food food)
    {
        // dicek kalo value nya > 25 / 35 change emotion ke happy (kan makannanya enak)
        if (food.is_expired)
        {
            this->setEmosi("angry");
            this->decereaseHealth(food.value * 3);
            this->decereaseHungry(food.value * 2);
        }
        else
        {
            if(this->hungry_level + food.value > 100) {
                this->hungry_level = 100;
            } else {
                this->hungry_level += food.value;
            }
            this->incereaseLevel(food);
        }
    }

    void incereaseThirsty(Drink drink)
    {
        if (drink.is_expired)
        {
            // this->emotion = "angry";
            this->setEmosi("angry");
            this->decereaseHealth(drink.value * 2);
            this->decereaseThirsty(drink.value * 4);
        }
        else
        {
            if(this->thirsty_level + drink.value > 100) {
                this->thirsty_level = 100;
            } else {
                this->thirsty_level += drink.value;
            }
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
            delete this;
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

    void getPlayerInfo()
    {
        this->checkHealth();  // buat cek health nya

        cout << "========= User Info ============" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Level: " << this->level << endl;
        cout << "Emotion: " << this->playerEmoticon << endl;
        cout << "Type: " << this->status << endl;
        cout << "Health: " << this->health << endl;
        cout << "Hungry Level: " << this->hungry_level << endl;
        cout << "Thirsty Level: " << this->thirsty_level << endl;
        cout << "========= End User Info ==========" << endl;
        cout << "\n" << endl;
        // selain cout ada printf, namun sesuai kondisi digunakannya.
    }
};

// this class for vialin / apalah yang berbau antagonis
class Monster : public Person {
public:
    Monster(const string name, const string type) {
        this->name = name;
        this->status = type;
        this->level = rand() % (100 - 13 -1) + 13; // get random number beetwen 12 - 100
    }

    // we need a tools for attack something. damnntttt

    void getAttack(int damage) {
        this->decereaseHealth(damage);
    }
};

// class ini mempunyai berfungsi untuk membuat object person.
class Player : public Person
{
    // encapsulation: yang ada di dalam private tidak dapat di akses ke luar
private:
    // set default sword dan shielddari player
    Sword attackTools = Sword("pedangKayu");
    Shield defenseTools = Shield("tamengKayu");

    // bisa diakses oleh siapa saja
public:

    // constructor, accept name, age, stats player.
    Player(const string &name, const string &status)
    {
        this->name = name;
        this->status = status;
    };

    // todo: bikin destructor buat delete object nya.

    // Start Getter Setter

    // show information about player
    // override from method person.
    void getPlayerInfo()
    {
        this->checkHealth();  // buat cek health nya
        this->checkEmotion(); // buat cek emotion nya

        cout << "========= User Info ============" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Alat Perang: " << this->attackTools.name << endl;
        cout << "Alat Perang: " << this->defenseTools.name << endl;
        cout << "Level: " << this->level << endl;
        cout << "Emotion: " << this->playerEmoticon << endl;
        cout << "Status: " << this->status << endl;
        cout << "Health: " << this->health << endl;
        cout << "Hungry Level: " << this->hungry_level << endl;
        cout << "Thirsty Level: " << this->thirsty_level << endl;
        cout << "========= End User Info ==========" << endl;
        cout << "\n" << endl;
        // selain cout ada printf, namun sesuai kondisi digunakannya.
    }

    // method ini berfungsi untuk set/netapin new sword dari player.
    void setSword(Sword sword)
    {
        this->attackTools = sword; // set new sword
    }

    // method ini berfungsi untuk set/netapin new shield dari player.
    void setShield(Shield shield)
    {
        this->defenseTools = shield;
    }

    // jika player mendapatkan penyerangan, maka kode ini akan dijalankan oleh player yang mendapat penyerangan.
    void getAttack(int attack)
    {
        this->decereaseHealth(attack - this->defenseTools.useDefense<Person>(*this));
    }

    // End Getter Setter

    // method untuk makan
    void eating(Food food)
    {
        this->inceraseHungry(food);
        cout << this->name << " sedang memakan " << food.name << "\n" << endl;
    }

    // method untuk minum
    void drinking(Drink drink)
    {
        this->incereaseThirsty(drink);
        cout << this->name << " sedang meminum " << drink.name << "\n" << endl;
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
    // time ini harus berupa hour/jam
    void sleeping(int hour)
    {
        this->inceraseHealth(20);
    }

    template <typename Opponent>
    void attack(Opponent *opponent)
    {
        // TODO:
        // cek apakah level nya sama / lebih besar dari level musuh [done]
        // kalo lebih besar, yang getAttack adalah diri nya sendiri (this) [done]
        // kalo lebih kecil / sama, maka akan saling menyerang. [done]
        // this method for attack PtoP (Person to Person) [done]
        // i want implement to monster can be attack or attacking.
         if(this->level > opponent->level) {
            opponent->getAttack(this->attackTools.useAttack(*this));
            opponent->health >= 100 ? opponent->level += 1 : this->level;
        } else if(opponent->level > this->level) {
            this->getAttack(this->attackTools.useAttack(*opponent));
            this->health >= 100 ? this->level += 1 : this->level;
        } else {
            opponent->getAttack(this->attackTools.useAttack(*this));
            this->getAttack(opponent->attackTools.useAttack(*opponent));
            //check if opponent health  == 100, maka bakal nambah level 1;
            opponent->health >= 100 ? opponent->level += 1 : this->level;
            this->health >= 100 ? this->level += 1 : this->level;
        }
    }
};

Player *createPlayer()
{
    string namaPlayer;
    string statusPlayer;

    cout << "Welcome to the game! \n";
    cout << "We need your information :>! \n";

    cout << "Masukan nama kamu: ";
    getline(cin, namaPlayer);
    // cin >> namaplayer;

    cout << "Masukan status kamu: ";
    getline(cin, statusPlayer);

    cout << endl;

    Player *player = new Player(namaPlayer, statusPlayer);
    return player;
}

int main()
{
    Player *player1 = createPlayer();
    player1->getPlayerInfo();

    Player *player2 = new Player("random1", "yey");
    Monster *ranMonster = new Monster("MonsterHitam", "epic");

    ranMonster->getPlayerInfo();

    Sword swordDiamond("pedangDiamond");

    Food ayamGeprek("Ayam Geprek");

    player1->setSword(swordDiamond);

    player1->attack<Player>(player2);

    player2->getPlayerInfo();
    player1->getPlayerInfo();


    player2->eating(ayamGeprek);

    player2->attack(player1);

    player2->getPlayerInfo();
    player1->getPlayerInfo();

    return 1;
}