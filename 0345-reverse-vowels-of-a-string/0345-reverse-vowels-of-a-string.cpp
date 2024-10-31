class Solution {
public:

    // Two pointer problem
   string reverseVowels(string s) {

        // i = left end, j = right end
        int i = 0, j = s.size() - 1;

        // loop until i < j, if both pointer indicate vowel, swap them
        while (i < j) {
            if (!isVowel(s[i])) {
                i++;
            } else if (!isVowel(s[j])) {
                j--;
            } else {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }

    // check the character is vowel
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    // swap to character
    void swap(char &a, char &b) {
        char temp = a;
        a = b;
        b = temp;
    }
};