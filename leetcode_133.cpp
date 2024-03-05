#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node // 邻接表表示
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

static unordered_map<Node *, Node *> markedMap; // 标记图，避免死循环

Node *cloneGraph(Node *node)
{
    if (node == nullptr)
        return node;
    if (markedMap.find(node) != markedMap.end())
        return markedMap[node];
    Node *cloneNode = new Node(node->val);
    markedMap[node] = cloneNode;
    for (auto &neighbour : node->neighbors)
        cloneNode->neighbors.emplace_back(cloneGraph(neighbour));
    return cloneNode;
}

int main()
{
    return 0;
}