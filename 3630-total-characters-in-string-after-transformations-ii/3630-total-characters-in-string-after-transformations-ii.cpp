class Solution {
public:
    const int MOD = 1e9 + 7;
    
    // Function to multiply two matrices
    vector<vector<long long>> matrixMultiply(vector<vector<long long>>& A, vector<vector<long long>>& B, int size) {
        vector<vector<long long>> result(size, vector<long long>(size, 0));
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        
        return result;
    }

    // Function to exponentiate a matrix
    vector<vector<long long>> matrixExponentiate(vector<vector<long long>>& matrix, long long exp, int size) {
        vector<vector<long long>> result(size, vector<long long>(size, 0));
        
        // Set result to the identity matrix
        for (int i = 0; i < size; ++i) {
            result[i][i] = 1;
        }
        
        // Exponentiation by squaring
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = matrixMultiply(result, matrix, size);
            }
            matrix = matrixMultiply(matrix, matrix, size);
            exp /= 2;
        }
        
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int size = 26; // Alphabet size
        vector<vector<long long>> transformMatrix(size, vector<long long>(size, 0));
        
        // Build the transformation matrix
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < nums[i]; ++j) {
                int newChar = (i + j + 1) % 26;
                transformMatrix[i][newChar]++;
            }
        }

        // Perform matrix exponentiation to get the transformation matrix after t steps
        vector<vector<long long>> finalMatrix = matrixExponentiate(transformMatrix, t, size);
        
        long long totalLength = 0;

        // Calculate the length of the transformed string
        for (char c : s) {
            int index = c - 'a';
            
            // Sum up the contributions from the final matrix
            for (int i = 0; i < size; ++i) {
                totalLength = (totalLength + finalMatrix[index][i]) % MOD;
            }
        }

        return (int)totalLength;
    }
};