#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <algorithm> 
#include <cctype> 
#include <set>
#include <iomanip>
#include <regex>
#include <unordered_set>
#include <locale>
#include <codecvt>
using namespace std;

map<string, int> pirma(ifstream&);
map<string, set<int>> antra(ifstream&);
unordered_set<string> trecia(ifstream&);
void out1(map<string, int>);
void out2(map<string, set<int>>);
void out3(unordered_set<string>);
