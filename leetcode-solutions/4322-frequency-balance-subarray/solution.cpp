class Solution {
public:
    bool isBalanced(const unordered_map<int,int>&freq,const unordered_map<int, int>& countOfFreq, int maxFreq,
                    int currentLen) {
        if(currentLen == 1){
            return true;
        }
        if (countOfFreq.size() == 1) {
            return freq.size()==1;
        }
        if (countOfFreq.size() != 2) {
            return false;
        }
        int otherFreq = -1;
        for (auto& p : countOfFreq) {
            if (p.first != maxFreq) {
                otherFreq = p.first;
                break;
            }
        }
        return (otherFreq != -1 && maxFreq == 2 * otherFreq);
    }

    int getLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> countOfFreq;
            int maxFreq = 0;
            for (int j = i; j < n; j++) {
                int num = nums[j];
                if (freq[num] > 0) {
                    countOfFreq[freq[num]]--;
                    if (countOfFreq[freq[num]] == 0) {
                        countOfFreq.erase(freq[num]);
                    }
                }
                freq[num]++;
                countOfFreq[freq[num]]++;
                maxFreq = max(maxFreq, freq[num]);
                int currentLen = j - i + 1;
                if (isBalanced(freq,countOfFreq, maxFreq, currentLen)) {
                    maxLen = max(maxLen, currentLen);
                }
            }
        }
        return maxLen;
    }
};
