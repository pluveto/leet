#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class util
{
public:
    template <class T>
    static void printVec(vector<T> v)
    {
        int size = v.size();
        cout << "[";
        for (int i = 0; i < size; i++)
        {
            cout << v[i] << (size == i + 1 ? "]\n" : ", ");
        }
    }

    static void printListNode(ListNode *head)
    {
        auto current = head;
        while (current)
        {
            cout << current->val << (current->next ? " > " : "");
            current = current->next;
        }
        cout << endl;
    }

    static ListNode *createListNode(vector<int> v)
    {
        int size = v.size();
        if (size == 0)
        {
            return nullptr;
        }
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        ListNode *current = node;
        for (int i = 0; i < size; i++)
        {
            current->val = v[i];
            if (i < size - 1)
            {
                ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
                newNode->val = 0;
                newNode->next = nullptr;
                current->next = newNode;
                current = newNode;
            }
        }
        return node;
    }

    static void printBool(bool b)
    {
        if (b)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
};
