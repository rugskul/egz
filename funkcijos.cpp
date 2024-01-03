#include "funkcijos.h"

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
            zodis.erase(remove_if(zodis.begin(), zodis.end(), ::isdigit), zodis.end());
            if (!zodis.empty()) {
                counter[zodis]++;
            }
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

void antra() {
    // associative container
    map<string, set<int>> crossReferenceTable;
    int lineNumber = 1;
    ifstream file("tekstas.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string zodis;
            while (iss >> zodis) {
                // pasalinami skyrybos zenklai
                zodis.erase(remove_if(zodis.begin(), zodis.end(), ::ispunct), zodis.end());
                zodis.erase(remove_if(zodis.begin(), zodis.end(), ::isdigit), zodis.end());
                crossReferenceTable[zodis].insert(lineNumber);
            }
            lineNumber++;
        }
        file.close();
    } else {
        cerr << "Nepavyko atidaryti failo." << endl;
    }

    cout << left << setw(30) << "";
    for (int i = 1; i <= lineNumber-1; i++) {
        cout << setw(5) << i;
    }
    cout << endl;
    for (const auto& pair : crossReferenceTable) {
        cout << left << setw(30) << pair.first;
        for (int i = 1; i <= lineNumber-1; i++) {
            if (pair.second.find(i) != pair.second.end()) {
                cout << setw(5) << "x";
            } else {
                cout << setw(5) << " ";
            }
        }
        cout << endl;
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

void trecia() {
    ifstream file("tekstas.txt");
    if (!file.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
    }
    stringstream buffer;
    buffer << file.rdbuf();
    string tekstas = buffer.str();


    regex url_regex(
        R"((https?|www)[^\s]+)",
        regex::icase
    );

    unordered_set<string> urls;

    for(auto i = sregex_iterator(tekstas.begin(), tekstas.end(), url_regex); i != sregex_iterator(); ++i) {
        urls.insert(i->str());
    }

    for (const string& url : urls) {
        cout << url << endl;
    }
}
