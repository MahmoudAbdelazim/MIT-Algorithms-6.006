#include <bits/stdc++.h>

using namespace std;

/*
 * This program computes the "distance" between two text files
 * as the angle between their word frequency vectors (in radians).
 */

//read the file as a vector of lines (strings)
vector<string> read_file(string &filename) {
    ifstream file;
    file.open(filename, ios::in);
    if (!file) {
        cout << "Couldn't open file" << endl;
        throw std::exception();
    }
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

//return a vector of words (strings) from a vector of lines (strings)
vector<string> get_words_from_line_list(vector<string> &list) {
    vector<string> word_list;
    for (const string &line : list) {
        string word;
        for (char c : line) {
            if (isalnum(c)) {
                word += c;
            } else if (!word.empty()) {
                for (char & i : word) i = tolower(i);
                word_list.push_back(word);
                word = "";
            }
        }
        if (!word.empty()) {
            for (int i = 0; i < word.size(); i++) word[i] = tolower(word[i]);
            word_list.push_back(word);
        }
    }
    return word_list;
}

// count the frequency of every word in the file and store them in a map
map<string, int> count_frequency(vector<string> &word_list) {
    map<string, int> D;
    for (const string& word : word_list) {
        if (D.find(word) != D.end()) {
            D[word]++;
        }
        else {
            D[word] = 1;
        }
    }
    return D;
}

// compute the word frequency for a file
map<string, int> word_frequencies_for_file(string &filename) {
    vector<string> text = read_file(filename);
    vector<string> word_list = get_words_from_line_list(text);
    return count_frequency(word_list);
}

// get the inner product of the two files using the frequencies of each words
double inner_product(map<string, int> &D1, map<string, int> &D2) {
    double sum = 0.0;
    for (pair<string, int> element: D1) {
        if (D2.find(element.first) != D2.end()) {
            sum += element.second * D2[element.first];
        }
    }
    return sum;
}

//get the distance using the vector angle between the frequencies
double vector_angle(map<string, int> &D1, map<string, int> &D2) {
    double numerator = inner_product(D1, D2);
    double denominator = sqrt(inner_product(D1, D1) * inner_product(D2, D2));
    return acos(numerator / denominator);
}

int main() {
    string filename1 = "file1.txt";
    string filename2 = "file2.txt";
    map<string, int> word_freq_1 = word_frequencies_for_file(filename1);
    map<string, int> word_freq_2 = word_frequencies_for_file(filename2);
    double distance = vector_angle(word_freq_1, word_freq_2);
    cout << "The distance between the 2 documents is: " << distance << "%\n";
    return 0;
}
