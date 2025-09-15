#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;

        for (string w : wordlist) {
            string lower = toLower(w);
            string devowel = devowelKey(lower);

            if (caseInsensitive.find(lower) == caseInsensitive.end()) {
                caseInsensitive[lower] = w;
            }

            if (vowelInsensitive.find(devowel) == vowelInsensitive.end()) {
                vowelInsensitive[devowel] = w;
            }
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lower = toLower(q);
            if (caseInsensitive.count(lower)) {
                ans.push_back(caseInsensitive[lower]);
                continue;
            }

            string devowel = devowelKey(lower);
            if (vowelInsensitive.count(devowel)) {
                ans.push_back(vowelInsensitive[devowel]);
                continue;
            }

            ans.push_back("");
        }
        return ans;
    }

private:
    string toLower(const string& s) {
        string t = s;
        for (auto &c : t) c = tolower(c);
        return t;
    }

    // change all vowel to '*'
    string devowelKey(const string& s) {
        string t = s;
        for (auto &c : t) {
            if (isVowel(c)) c = '*';
        }
        return t;
    }

    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
};
