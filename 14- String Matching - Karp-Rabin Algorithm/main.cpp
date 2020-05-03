#include <bits/stdc++.h>

using namespace std;

/*
 * The idea of the Algorithm is to compute the hash value of a string using the hash value
 * of the the string preceding it by 1 character in only O(1) running-time, instead of
 * matching every strings character by character.
 *
 * using the hash values, we can only compare 2 strings if their hash values are the same, and that would happen rarely
 *
 * The formula for Karp_Rabin Algorithm is the following:
 * hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q
 *
 * hash( txt[s .. s+m-1] ) : Hash value at shift s.
 * hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1)
 * d: Number of characters in the alphabet
 * q: A prime number
 * h: d^(m-1)
 *
 * This is simple mathematics, we compute decimal value of current window from previous window.
For example pattern length is 3 and string is “23456”
You compute the value of first window (which is “234”) as 234.
How how will you compute value of next window “345”? You will do (234 – 2*100)*10 + 5 and get 345.
 */

const int d = 256; // number of possible characters (ASCII is 256)
void search(string &pat, string &txt,
            int q) { //pat is the pattern to search for, txt is the long string text, q is a prime number
    int M = pat.size();
    int N = txt.size();
    int pHash = 0;
    int tHash = 0;
    int h = 1;
    //this is computing h = d^(m-1)
    for (int i = 0; i < M - 1; i++) {
        h = (h * d) % q;
    }
    //this computes the hash values of pat and the first window of txt,
    //converting the 256-bit character string to integer <= q
    for (int i = 0; i < M; i++) {
        pHash = (d * pHash + pat[i]) % q;
        tHash = (d * tHash + txt[i]) % q;
    }
    bool found = false;
    for (int i = 0; i <= N - M; i++) {
        //if their hashes match, only then compare them char by char
        if (pHash == tHash) {
            int j = 0;
            for (j = 0; j < M; j++) {
                if (pat[j] != txt[i + j])
                    break;
            }
            if (j == M) {
                cout << "Pattern \"" << pat << "\" found at index " << i << "\n";
                found = true;
            }
        }
        //if not, calculate the hash value of the next window (remove the first char and add the next)
        if (i < N - M) {
            //using the karp-rabin formula
            tHash = (d * (tHash - txt[i] * h) + txt[i + M]) % q;
            while (tHash < 0) // if tHash turned out to be negative
                tHash += q;
        }
    }
    if (!found) {
        cout << "Pattern \"" << pat << "\" is not found in the text\n";
    }
}

int main() {
    string txt = "Mahmoud Mohamed Abdelazim";
    string pat = "Mahmoud";
    search(pat, txt, 101);
    pat = "Mohamed";
    search(pat, txt, 101);
    pat = "Abdelazim";
    search(pat, txt, 101);
    pat = "1234";
    search(pat, txt, 101);

    return 0;
}
