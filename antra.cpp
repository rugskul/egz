#include "header.h"

void antra() {
    // associative container
    map<string, set<int>> crossReferenceTable;
    ifstream file("tekstas.txt");
    if (file.is_open()) {
        string line;
        int lineNumber = 1;
        while (getline(file, line)) {
            istringstream iss(line);
            string zodis;
            while (iss >> zodis) {
                // pasalinami skyrybos zenklai
                zodis.erase(remove_if(zodis.begin(), zodis.end(), ::ispunct), zodis.end());
                crossReferenceTable[zodis].insert(lineNumber);
            }
            lineNumber++;
        }
        file.close();
    } else {
        cerr << "Nepavyko atidaryti failo." << endl;
    }

    ofstream outFile("zodziu_counteris.txt");
    if (!outFile.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
    }
    for (const auto& pair : crossReferenceTable) {
        outFile << pair.first << ": ";
        for (const auto& line : pair.second) {
            outFile << line << " ";
        }
        outFile << "\n";
    }
    outFile.close();
}