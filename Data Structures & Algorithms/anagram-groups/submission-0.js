class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */

    formString(str)
    {
        let arr = Array.from({ length: 26 }).fill(0);

        for(const char of str) {
            arr[char.charCodeAt(0) - 'a'.charCodeAt(0)] += 1;
        }

        let finalString = "";
        for(let i=0;i<26;i++)
        {
            if(arr[i] > 0) finalString += String.fromCharCode(i + 65) + arr[i].toString();
        }

        return finalString;
    }

    groupAnagrams(strs) {
        
        let wordMap = {};

        for(const str of strs)
        {
            const charCount = this.formString(str);
            if(!wordMap[charCount]) wordMap[charCount] = [str];
            else wordMap[charCount].push(str);
        }

        return Object.values(wordMap);
    };
}
