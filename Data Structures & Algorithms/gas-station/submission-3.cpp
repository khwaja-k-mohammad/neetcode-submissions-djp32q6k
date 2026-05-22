class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         
         int len = gas.size();

         int currIndex = 0, startIndex = 0, currGas = 0;

         while(startIndex < len)
         {
            //  cout<<startIndex<<"   "<<currIndex<<"  "<<currGas<<endl;
             currGas += gas[currIndex];
             if(currGas < cost[currIndex]) {
                if(currIndex < startIndex) return -1;
                else startIndex = currIndex + 1;
                currGas = 0;
             }
             else {
                if(currIndex == startIndex - 1 || (currIndex == len - 1 && startIndex == 0)) return startIndex;
                currGas -= cost[currIndex];
             }

            currIndex = (currIndex == len - 1) ? 0 : currIndex + 1;
         }

         return -1;
    }
};
