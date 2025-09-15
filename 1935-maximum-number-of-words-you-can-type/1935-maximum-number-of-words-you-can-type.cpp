class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        istringstream iss(text);
        bool isBroken[27] = {false,};
        int ans = 0;
        string word;

        for (char c : brokenLetters) {
            isBroken[c-'a'] = true;
        }

        while(iss >> word) {
            bool canType = true;
            for (char c : word) {
                if (isBroken[c-'a']) {
                    canType=false;
                    break;
                }
            }
            if (canType) 
                ++ans;
        }

        return ans;
    }
};