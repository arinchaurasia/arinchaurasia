class Solution {
public:
    // function to check vowel
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
           c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            return true;
        }
        return false;
    }

    string sortVowels(string s) {
        vector<char> vowels;

        // Step 1: collect vowels
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                vowels.push_back(s[i]);
            }
        }

        // Step 2: sort vowels
        sort(vowels.begin(), vowels.end());

        // Step 3: put back vowels
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};
