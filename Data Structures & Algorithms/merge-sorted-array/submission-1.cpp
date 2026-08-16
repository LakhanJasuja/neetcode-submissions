class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap = (m + n) / 2 + (m+n)%2;
        int ind = m;
        int itr = 0;
        while (itr < nums2.size()) {
            nums1[ind] = nums2[itr];
            ind++;
            itr++;
        }

        int tot = nums1.size();

        while (gap > 0) {
            int i = 0;
            int j = gap;
            while (j < tot) {
                if (nums1[i] > nums1[j]){
                    swap(nums1[i], nums1[j]);
                }
                i++;
                j++;
            }
            if (gap == 1) break;
            gap = (gap/2) + gap%2;
        }

        // int ind = nums1.size();
        // int itr = 0;
        // while (itr < nums2.size()) {
        //     nums1[ind] = nums2[itr];
        //     itr++;
        // }
        
    }
};