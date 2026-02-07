#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cout << "File input.txt not found!" << endl;
        return 1;
    }

    map<string, int> dict;
    string word;

    while (fin >> word) {

        string clean = "";
        for (int i = 0; i < word.length(); i++) {
            if (ispunct(word[i])) continue; 
            clean += tolower(word[i]);      
        }

        if (!clean.empty()) {
            dict[clean]++;
        }
    }
    fin.close();

    ofstream fout("output.txt");
    string mostFrequent = "";
    int maxCount = 0;

    cout << "Frequency dictionary:" << endl;


    for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
        fout << it->first << ": " << it->second << endl;

        if (it->second > maxCount) {
            maxCount = it->second;
            mostFrequent = it->first;
        }
    }


    if (maxCount > 0) {
        cout << "\nMost frequent: " << mostFrequent << " (" << maxCount << ")" << endl;
        fout << "\nMost frequent: " << mostFrequent << " (" << maxCount << ")" << endl;
    }

    fout.close();
}   