class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int blockSize = sqrt(n);
        int numBlocks = (n + blockSize - 1) / blockSize;

        vector<int> blockMax(numBlocks, 0); 

        for (int i = 0; i < n; i++) {
            int blockIndex = i / blockSize;
            blockMax[blockIndex] = max(blockMax[blockIndex], baskets[i]);
        }

        int unplaced = 0; 
        for (int fruit : fruits) {
            bool placed = false;

            for (int block = 0; block < numBlocks; block++) {
                if (blockMax[block] < fruit) continue; 

                for (int i = block * blockSize; i < (block + 1) * blockSize && i < n; i++) {
                    if (baskets[i] >= fruit) {
                        baskets[i] = 0; 
                        placed = true;

                        blockMax[block] = 0;
                        for (int j = block * blockSize; j < (block + 1) * blockSize && j < n; j++) {
                            blockMax[block] = max(blockMax[block], baskets[j]);
                        }
                        break;
                    }
                }

                if (placed) break;
            }

            if (!placed) unplaced++; 
        }

        return unplaced;
    }
};