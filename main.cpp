#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm> 
#include <cctype> 

using namespace std;

int main() {
    ifstream inputFile("tekstas.txt");
    if (!inputFile.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
        return 1;
    }
    // associative container
    map<string, int> counter;

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string zodis;
        while (iss >> zodis) {
            // pasalinami skyrybos zenklai
            zodis.erase(remove_if(zodis.begin(), zodis.end(), ::ispunct), zodis.end());
            counter[zodis]++;
        }
    }
    inputFile.close();


    ofstream outputFile("zodziu_counteris.txt");
    if (!outputFile.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
        return 1;
    }
    for (const auto& pair : counter) {
        outputFile << pair.first << ": " << pair.second << "\n";
    }
    outputFile.close();

}