class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string temp(word1.size() + word2.size(),' ');
        int i = 0, j = 0;
        int k = 0;
        while (i < word1.size() && j < word2.size()) {
            temp[k++] = word1[i];
            temp[k++] = word2[j];
            i++;
            j++;
        }

        while (i < word1.size()) {
            temp[k++] = word1[i];
            i++;
        }

        while (j < word2.size()) {
            temp[k++] = word2[j];

            j++;
        }
        return temp;
    }
};