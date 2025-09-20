/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,  unordered_map<Node*,Node*>& mp)
    {
        if(mp.find(node) != mp.end())
        {
            return mp[node];
        }
        Node* clone = new Node(node->val);
        mp[node] = clone;
       vector<Node*> neighbour;


       for(int i =0; i < node->neighbors.size() ;i++)
       {
            clone->neighbors.push_back(dfs( node->neighbors[i],mp));
       }
      return clone;

    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node == nullptr)
        {
            return nullptr;
        }

        if(node->neighbors.size() ==0)
        {
            Node* clone = new Node();
            clone->val = node->val;
            return clone;
        }

        return dfs(node,mp);
    }
};