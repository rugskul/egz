#include "funkcijos.h"

map<string, int> pirma(ifstream& file) {
    // associative container
    map<string, int> counter;

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string zodis;
        while (iss >> zodis) {
            // pasalinami skyrybos zenklai ir skaiciai
            zodis.erase(remove_if(zodis.begin(), zodis.end(), ::ispunct), zodis.end());
            zodis.erase(remove_if(zodis.begin(), zodis.end(), ::isdigit), zodis.end());
            if (!zodis.empty()) {
                counter[zodis]++;
            }
        }
    }
    return counter;
}

pair<map<string, set<int>>, int> antra(ifstream& file) {
    // associative container
    map<string, set<int>> eilutes;
    int lineNumber = 1;
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string zodis;
        while (iss >> zodis) {
            // pasalinami skyrybos zenklai ir skaiciai
            zodis.erase(remove_if(zodis.begin(), zodis.end(), ::ispunct), zodis.end());
            zodis.erase(remove_if(zodis.begin(), zodis.end(), ::isdigit), zodis.end());
            if (!zodis.empty()) {
                eilutes[zodis].insert(lineNumber);
            }
        }
        lineNumber++;
    }
    return make_pair(eilutes, lineNumber);
}

unordered_set<string> trecia(ifstream& file) {
    stringstream buffer;
    buffer << file.rdbuf();
    string tekstas = buffer.str();

    // associative container
    unordered_set<string> urls;

    regex url_regex(
        R"((https?|www)[^\s]+)",
        regex::icase
    );
    for(auto i = sregex_iterator(tekstas.begin(), tekstas.end(), url_regex); i != sregex_iterator(); ++i) {
        urls.insert(i->str());
    }
    return urls;
}

void out1(map<string, int> counter) {
    ofstream outFile("zodziu_counteris.txt");
    for (const auto& pair : counter) {
        outFile << pair.first << " " << pair.second << endl;
    }
    outFile.close();
}

void out2(map<string, set<int>> eilutes, int lineNumber) {
    ofstream outFile("zodziu_eilutes.txt");
    for (const auto& pair : eilutes) {
        outFile << pair.first << " ";
        for (const int& line : pair.second) {
            outFile << line << " ";
        }
        outFile << endl;
    }
    outFile.close();
}

void out3(unordered_set<string> urls) {
    ofstream outFile("urls.txt");
    for (const string& url : urls) {
        cout << url << endl; //ekrane
        outFile << url << endl; //i faila
    }
    outFile.close();
}