#include "header.h"
void pirma() {
    ifstream inFile("tekstas.txt");
    if (!inFile.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
    }
    // associative container
    map<string, int> counter;

    string line;
    while (getline(inFile, line)) {
        for (int i = 0; i < line.size(); i += 66) {
            string substring = line.substr(i, 66);
        }
        istringstream iss(line);
        string zodis;
        while (iss >> zodis) {
            // pasalinami skyrybos zenklai
            zodis.erase(remove_if(zodis.begin(), zodis.end(), ::ispunct), zodis.end());
            counter[zodis]++;
        }
    }
    inFile.close();


    ofstream outFile("zodziu_counteris.txt");
    if (!outFile.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
    }
    for (const auto& pair : counter) {
        outFile << pair.first << ": " << pair.second << "\n";
    }
    outFile.close();
}

