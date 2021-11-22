#include <debug.h>
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(nullptr == root){
            return 0;
        }        
        int maxval = 1;
        for (auto &&child : root->children)
        {
            maxval = max(maxval, maxDepth(child));
        }
        return maxval;        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    
    return 0;
}