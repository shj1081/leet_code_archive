class Solution {
public:
    string reverseWords(string s) {
        vector<string> strings;  // Store the words
        stringstream ss(s);      // Use stringstream to split the string
        string item;             // Store the word temporarily
        string result;

        // Split the string by spaces
        // getline(ss, item, ' ') reads the string from ss to item until ' ' is found
        while (getline(ss, item, ' ')) {
            strings.push_back(item);
        }

        // Reverse the words
        for (int i = strings.size() - 1; i >= 0; i--) {
            if (!strings[i].empty())
                result += strings[i] + " ";
        }

        // Remove the last space
        result.pop_back();

        return result;
        
    }
};