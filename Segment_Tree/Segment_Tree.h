#include<vector>
class Segment_Tree {

    public:
        Segment_Tree(std::vector<int> arr);
        // int n = arr.size();
        std::vector<int> build_tree(std::vector<int> arr, int tl, int tr, int v);
        int sum_query(int l, int r);
        int update(int pos, int val);

};