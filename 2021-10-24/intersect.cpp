#include <debug.h>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode () : val (0), left (nullptr), right (nullptr) {}
  TreeNode (int x) : val (x), left (nullptr), right (nullptr) {}
  TreeNode (int x, TreeNode *left, TreeNode *right)
      : val (x), left (left), right (right)
  {
  }
};

class Solution
{
private:
    stack<TreeNode*> lstack;
    stack<TreeNode*> rstack;
    TreeNode *lptr;
    TreeNode *rptr;
    TreeNode* step(TreeNode ** cur, stack<TreeNode*> *curstack){        
        while(*cur != nullptr || !curstack->empty())
        {
            if(*cur!=nullptr){
                TreeNode* ltmp = *cur;
                curstack->push(ltmp);
                // printf("ltmp->val = %d\n", ltmp->val);
                *cur = ltmp->left;
            }
            else if(!curstack->empty())
            {
                auto top = curstack->top();
                curstack->pop();
                // ret.push(ptr->val)
                // printf("%x top->val = %d\n",top, top->val);                
                *cur = top->right;
                if(*cur != nullptr){
                    return nullptr;
                }
            }
        }
        return nullptr;
    }
public:
    void intersect(TreeNode *t1, TreeNode *t2)
    {
        lptr = t1, rptr =t2;
        // 各自回到最小值
        step(&lptr, &lstack);
        step(&rptr, &rstack);
        while(lptr!=nullptr && rptr != nullptr ){            
            auto lval = lptr->val;
            auto rval = rptr->val;
            TreeNode *lptrtmp, *rptrtmp;
            // 相交，保存，并各走一步
            if(lval == rval){
                printf("~~~val = %d\n", lval);                                
                lptrtmp = step(&lptr, &lstack);
                rptrtmp = step(&rptr, &rstack);
            }else if(lval > rval){ // 右边小了，右边走一步
                rptrtmp = step(&rptr, &rstack);
            }else /*lval < rval*/{ // 左边小了，左边走一步
                lptrtmp = step(&lptr, &lstack);
            }
            
           // printf("lval = %d\n", lval);
           // printf("rval = %d\n\n",rval);
        }        
    }
};


int
main (int argc, char const *argv[])
{
  Solution s;
  /*
       12
      /  \
     8    13
    / \    \
   1   9    15
            / \
           14  18
  */
  TreeNode t1 (12, 
        new TreeNode (8, 
            new TreeNode (1), 
            new TreeNode (9)),
        new TreeNode (13, 
            nullptr, 
            new TreeNode (15, 
                new TreeNode (14), 
                new TreeNode (18))));
  /*
       13
      /  \
     8    14
    / \    \
   1   10   15
            / \
           14  20
  */
  TreeNode t2 (13, 
        new TreeNode (8, 
            new TreeNode (1), 
            new TreeNode (10)),
        new TreeNode (14, 
            nullptr, 
            new TreeNode (15, 
                new TreeNode (14), 
                new TreeNode (20))));
  s.intersect(&t1,&t2);
  return 0;
}