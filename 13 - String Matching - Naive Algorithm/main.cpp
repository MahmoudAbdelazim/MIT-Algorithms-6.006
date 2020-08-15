#include <bits/stdc++.h>
using namespace std;

void search(string &pat, string &txt) { //search for a string pat in a long string txt
    bool found = false;
    for (long long i = 0; i < txt.size() - pat.size(); i++) {
        int j = 0;
        for (j = 0; j < pat.size(); j++) {
            if (pat[j] != txt[i + j])
                break;
        }
        if (j == pat.size()) {
            found = true;
            cout << "Pattern \"" << pat << "\" is found in the text at index " << i << "\n";
        }
    }
    if (!found) {
        cout << "Pattern \"" << pat <<  "\" is not found in the text\n";
    }
}

int main() {
    string txt = "Lorem ipsum dolor sit amet, consectetur adipiscing elit"
                 ", sed do eiusmod tempor incididunt ut labore et dolore magna"
                 " aliqua. Ut enim ad minim veniam, quis nostrud exercitation"
                 " ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis"
                 " aute irure dolor in reprehenderit in voluptate velit esse cillum"
                 " dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat"
                 " non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    string pat = "eiusmod";
    search(pat, txt);
    return 0;
}
