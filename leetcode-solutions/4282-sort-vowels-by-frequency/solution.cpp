class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    string sortVowels(string s) {
        string vow = "";
        vector<int> freq(26, 0);
        vector<int> firstPos(26, -1);

        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])) {
                vow += s[i];
                freq[s[i] - 'a']++;

                if(firstPos[s[i] - 'a'] == -1) {
                    firstPos[s[i] - 'a'] = i;
                }
            }
        }

        sort(vow.begin(), vow.end(), [&](char a, char b){
            if(freq[a - 'a'] != freq[b - 'a']) 
                return freq[a - 'a'] > freq[b - 'a'];
            return firstPos[a - 'a'] < firstPos[b - 'a'];
        });

        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])) {
                s[i] = vow[j++];
            }
        }

        return s;
    }
};
