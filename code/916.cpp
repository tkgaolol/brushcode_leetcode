class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Create a frequency map that represents maximum frequency needed for each char
        vector<int> maxFreq(26, 0);
        for (const string& word : words2) {
            vector<int> currFreq = getFrequency(word);
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], currFreq[i]);
            }
        }
        
        // Check each word in words1
        vector<string> result;
        for (const string& word : words1) {
            vector<int> freq = getFrequency(word);
            bool isUniversal = true;
            
            // Check if current word has enough of each character
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            
            if (isUniversal) {
                result.push_back(word);
            }
        }
        
        return result;
    }
    
private:
    // Helper function to get character frequency
    vector<int> getFrequency(const string& word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        return freq;
    }
};