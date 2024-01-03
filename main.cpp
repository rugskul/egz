#include "funkcijos.h"

int main() {
    int uzduotis;
    cout << "užduoties nr. (1 / 2 / 3) ? " << endl;
    cin >> uzduotis;
    if (uzduotis == 1) {
        pirma();
    } else if (uzduotis == 2) {
        antra();
    } else if (uzduotis == 3) {
        trecia();
    } else {
        cerr << "tokios užduoties nėra" << endl;
    }
}