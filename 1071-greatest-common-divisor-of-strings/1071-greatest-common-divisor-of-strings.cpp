class Solution {
public:
    // 문자열을 n번 반복하는 함수
    string repeat(const string& s, int times) {
        string result;
        for (int i = 0; i < times; ++i) {
            result += s;
        }
        return result;
    }

    string gcdOfStrings(string str1, string str2) {
        
        int gcdLen = gcd(str1.length(), str2.length());
        string sub1, sub2;
        string gcdStr = "";

        for (int i = 1; i <= gcdLen ; i++) {
            
            if (str1.length() % i != 0 || str1.length() % i != 0) {
                continue;
            }
            
            sub1 = str1.substr(0,i);
            sub2 = str2.substr(0,i);

            if (sub1 != sub2) {
                break;
            }

            if (repeat(sub1,str1.length()/i) == str1 && repeat(sub2,str2.length()/i) == str2) {
                gcdStr = str1.substr(0,i);
            }

            else {
                if (str1[i] != str2[i]) {
                    break;
                }
            }

        }

        return gcdStr;
        
    }
};