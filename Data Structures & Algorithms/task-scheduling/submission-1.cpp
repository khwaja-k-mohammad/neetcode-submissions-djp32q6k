class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> freq(26, 0);
        int maxi = INT_MIN;
        int elementsWithMaxFreq = 0;

        for(auto task : tasks) {
            int newFreq = ++freq[task - 'A'];
            if(maxi == newFreq) {
                elementsWithMaxFreq += 1;
            }

            else if(newFreq > maxi) {
                maxi = newFreq;
                elementsWithMaxFreq = 1;
            }
        }

        int idleSpaces = (maxi - 1) * (n - (elementsWithMaxFreq - 1));
        int availableTasks = tasks.size() - maxi * elementsWithMaxFreq;

        int extraSpacesNeeded = max(0, idleSpaces - availableTasks);

        return tasks.size() + extraSpacesNeeded;
    }
};