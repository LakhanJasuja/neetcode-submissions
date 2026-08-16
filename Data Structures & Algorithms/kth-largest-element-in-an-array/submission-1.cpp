class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector <int>> pq(less<int>(), nums);
        while (k > 1) {
            pq.pop();
            k--;
        }

        return pq.top();
        
    }
};
