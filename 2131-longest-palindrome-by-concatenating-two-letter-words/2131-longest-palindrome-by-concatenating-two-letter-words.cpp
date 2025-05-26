class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        for (const string& word : words) {
            count[word]++;
        }

        int length = 0;
        bool used_center = false;

        // Step 1: Use pairs like "ab" and "ba"
        for (auto& [word, freq] : count) {
            string rev = string{word.rbegin(), word.rend()};
            if (word != rev && count.find(rev) != count.end()) {
                int pair_count = min(freq, count[rev]);
                length += pair_count * 4;
                count[word] -= pair_count;
                count[rev] -= pair_count;
            }
        }

        // Step 2: Use words like "aa", "bb" (symmetric words)
        for (auto& [word, freq] : count) {
            if (word[0] == word[1]) {
                int pair_count = freq / 2;
                length += pair_count * 4;
                count[word] -= pair_count * 2;
                if (!used_center && count[word] > 0) {
                    length += 2;
                    used_center = true;
                }
            }
        }

        return length;
    }
};
