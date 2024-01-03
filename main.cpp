#include "funkcijos.h"



int main() {
    ifstream file("tekstas.txt");
    if (!file.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
        return 1;
    }

    int uzduotis;
    cout << "užduoties nr. (1 / 2 / 3) ? " << endl;
    cin >> uzduotis;

    if (uzduotis == 1) {
        map<string, int> counter = pirma(file);
        out1(counter);
    } else if (uzduotis == 2) {
        map<string, set<int>> eilutes = antra(file);
        out2(eilutes);
    } else if (uzduotis == 3) {
        unordered_set<string> urls = trecia(file);
        out3(urls);
    } else {
        cerr << "tokios užduoties nėra" << endl;
    }

    file.close();
}