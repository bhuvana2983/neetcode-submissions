
class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mp;

        for(char ch : t) {
            mp[ch]++;
        }

        int left = 0;
        int required = t.size();

        int minLength = INT_MAX;
        int startIndex = 0;

        for(int right = 0; right < s.size(); right++) {

            char ch = s[right];

            if(mp[ch] > 0) {
                required--;
            }

            mp[ch]--;

            while(required == 0) {

                if(right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIndex = left;
                }

                char leftChar = s[left];

                mp[leftChar]++;

                if(mp[leftChar] > 0) {
                    required++;
                }

                left++;
            }
        }

        if(minLength == INT_MAX) {
            return "";
        }

        return s.substr(startIndex, minLength);
    }
};
