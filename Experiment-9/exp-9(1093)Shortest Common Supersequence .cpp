class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int str1Length = str1.length();
        int str2Length = str2.length();

        vector<string> prevRow(str2Length + 1);
        for (int col = 0; col <= str2Length; col++) {
            prevRow[col] = str2.substr(0, col);
        }

        for (int row = 1; row <= str1Length; row++) {
            vector<string> currRow(str2Length + 1);
            currRow[0] = str1.substr(0, row);

            for (int col = 1; col <= str2Length; col++) {
                if (str1[row - 1] == str2[col - 1]) {
                    currRow[col] = prevRow[col - 1] + str1[row - 1];
                } else {
                    string pickS1 = prevRow[col];
                    string pickS2 = currRow[col - 1];

                    currRow[col] = (pickS1.length() < pickS2.length())
                                       ? pickS1 + str1[row - 1]
                                       : pickS2 + str2[col - 1];
                }
            }
            prevRow = currRow;
        }

        return prevRow[str2Length];
    }
};
