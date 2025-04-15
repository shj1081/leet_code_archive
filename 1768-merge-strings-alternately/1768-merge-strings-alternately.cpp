class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int idx1 = 0;
        int idx2 = 0;
        string output;

        while (true) {
            if (idx1 == word1.length() && idx2 == word2.length()) {
                break;
            }

            else if (idx1 == word1.length() && idx2 != word2.length()) {
                output += word2.substr(idx2);
                break;
            }

            else if (idx1 != word1.length() && idx2 == word2.length()) {
                 output += word1.substr(idx1);
                 break;
            }


            else {
                output += word1[idx1++];
                output += word2[idx2++];

            }
        }

        cout << output;

        return output;
    }
};