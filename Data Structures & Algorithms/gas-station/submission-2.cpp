class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         
         int len = gas.size();
         int totalGas = 0, totalCost = 0;

         for(int i=0;i<len;i++)
         {
            totalGas += gas[i];
            totalCost += cost[i];
         }

         if(totalGas < totalCost) return -1;

         int currIndex = 0, startIndex = 0, currGas = 0;

         while(startIndex < len)
         {
            //  cout<<startIndex<<"   "<<currIndex<<"  "<<currGas<<endl;
             currGas += gas[currIndex];
             if(currGas < cost[currIndex]) {
                if(startIndex == len - 1) return -1;
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
