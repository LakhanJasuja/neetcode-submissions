class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ind = -1;
        int sum = 0;
        int minm = INT_MAX;

        for (int i = 0; i < n; i++) {
            sum += (gas[i] - cost[i]);
            if (sum < minm) {
                minm = sum;
                ind = i;
            }
        }
       // cout << ind << "\n";

        // check if possible for ind+1..n 
        int i = ind + 1;
        i%=n;
        sum = 0;
        while (i != ind) {
            sum += (gas[i] - cost[i]);
           // cout << sum << " " << i <<"\n";
            if (sum < 0) return -1;
            i++;
            i%=n;
        }

        if (sum + (gas[i] - cost[i]) < 0) return -1;


        return (ind + 1)%n;

    
        // int lastInd = -1;
        // for (int i = 0 ; i < n ; i++) {
        //     if (gas[i] - cost[i] >= 0) {
        //         int sum = 0;
        //         lastInd = i;
        //         bool ans = true;
        //         while (i < n) {
        //             sum += gas[i] - cost[i];
        //             i++;
        //             if (sum < 0) {
        //                 ans = false;
        //                 break;
        //             }
        //         }
        //         if (ans == false) lastInd = -1;
        //     }
        // }
        // return lastInd;

        //if (lastInd == -1) return -1;




        
    }
};
