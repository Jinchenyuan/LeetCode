#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    void travel(Node* src, Node* ans, Node **visited)
    {
        if (!src)
            return;
        if (visited[src->val - 1])
            return;
        ans->val = src->val;
        visited[ans->val - 1] = ans;
        for (int i = 0; i < src->neighbors.size(); i++)
        {
            if (visited[src->neighbors[i]->val - 1])
            {
                ans->neighbors.push_back(visited[src->neighbors[i]->val - 1]);
            }
            else
            {
                Node *tmp = new Node();
                ans->neighbors.push_back(tmp);
                travel(src->neighbors[i], tmp, visited);
            }
        }
    }

public:
    Node* cloneGraph(Node* node) {
        Node *visited[100] = {NULL};
        Node *ans = new Node();
        travel(node, ans, visited);
        return ans;
    }
};

