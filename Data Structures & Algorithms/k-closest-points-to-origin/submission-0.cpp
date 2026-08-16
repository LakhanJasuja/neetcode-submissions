struct Node {
    public : 
        int x; 
        int y; 
        Node(int x, int y) {
            this->x = x;
            this->y = y;
        }
};
class Solution {
public:

    struct Compare {
        bool operator()(const Node& n1, const Node& n2) const {
            long long d1 = 1LL * n1.x * n1.x + 1LL * n1.y * n1.y;
            long long d2 = 1LL * n2.x * n2.x + 1LL * n2.y * n2.y;
            return d1 > d2;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Node, vector <Node>, Compare> pq;

        for (int i=0; i< points.size(); i++) {
            Node node(points[i][0], points[i][1]);
            pq.push(node);
        }

        vector<vector <int>> ans;

        while (k >= 1) {
            ans.push_back({pq.top().x, pq.top().y});
            pq.pop();
            k--;
        }
        return ans;
        
    }
};
