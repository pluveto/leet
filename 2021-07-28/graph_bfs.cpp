#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

void _print_vec(std::vector<int> &vec)
{
    if (vec.size() == 0)
    {
        printf("{}\n");
        return;
    }
    printf("{");
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        printf("%d, ", vec[i]);
    }
    printf("%d", vec[vec.size() - 1]);
    printf("}\n");
}

#include <queue>
#include <unordered_map>

void bfs(Node *start, vector<int> &ret)
{
    queue<Node *> todolist;
    unordered_map<Node *, bool> history;
    todolist.push(start);
    while (!todolist.empty())
    {
        auto out = todolist.front();
        todolist.pop();
        ret.push_back(out->val);

        for (auto nei : out->neighbors)
        {
            if (history[nei])
                continue;
            todolist.push(nei);
            history[nei] = true;
        }
    }
}

int main(int argc, char const *argv[])
{
    /*
     a   b   c   d
     3---2---0---5
          \  | / |
            4----1
            e    f
    */
    Node a(3);
    Node b(2);
    Node c(0);
    Node d(5);
    Node e(4);
    Node f(1);

    a.neighbors = {&b};
    b.neighbors = {&a, &c, &e};
    c.neighbors = {&b, &d, &e};
    d.neighbors = {&c, &e, &f};
    e.neighbors = {&b, &c, &d, &f};
    f.neighbors = {&e, &d};

    vector<int> r;
    bfs(&a, r);
    _print_vec(r);
    return 0;
}