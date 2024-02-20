#include <iostream>

using namespace std;

// pointer anjixxxxxcc afuactahfi pusing

void pointerhehe(int *b) {
    cout << "addr b: " << b <<endl;
    cout << "nilai b: " << *b <<endl;
}

int main() {

    // var a di taruh di memori ke (berapapun) dengan value 5
    int a = 5;
    //pointer berguna untuk merujuk ke memori tersebut
    int *aPtr = &a;
    
    cout << "nilai a: " << a <<endl;
    cout << "nilai addres a: " << &a <<endl;
    cout << "nilai pointer a: " << *aPtr <<endl;
    cout << "nilai addres pointer a: " << &aPtr <<endl;

    pointerhehe(&a);

    cin.get();
    return 1;
}