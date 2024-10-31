class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);  // Input string stream
        vector<string> words;  // Vector to store words
        string word;           // Temporary string to store words

        // Extract words while ignoring extra spaces
        while (iss >> word) {
            words.push_back(word);
        }

        // Reverse the words in place
        reverse(words.begin(), words.end());

        // Join words with a single space between them
        // accumulate(begin, end, initial_value, operation)
        //   - skips the first word to avoid an extra leading space, using it as the initial value instead
        //   - default operation is just `+`
        return accumulate(next(words.begin()), words.end(), words[0],
                          [](const string& a, const string& b) {
                              return a + ' ' + b;
                          });
        
    }
};