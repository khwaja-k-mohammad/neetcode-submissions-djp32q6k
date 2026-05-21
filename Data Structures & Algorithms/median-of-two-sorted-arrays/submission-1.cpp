class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int left = 0, right = n1;
        int middle = (n1 + n2 + 1) / 2;

        while(left <= right)
        {
            int mid1 = (left + (right - left)/2);
            int mid2 = middle - mid1;

            int l1 = mid1 - 1 >= 0 ? nums1[mid1 - 1] : INT_MIN, l2 = mid1 < n1 ? nums1[mid1] : INT_MAX;
            int r1 = mid2 - 1 >= 0 ? nums2[mid2 - 1] : INT_MIN, r2 = mid2 < n2 ? nums2[mid2]: INT_MAX;

            if(l1 <= r2 && r1 <= l2) {
                if((n1 + n2) % 2 == 0) return (double)(max(l1, r1) + min(l2,r2))/2;
                else return (double)(max(l1, r1));
            }
            else if(l1 > r2) right = mid1 - 1;
            else left = mid1 + 1;
        }

        return 0;
    }
};
