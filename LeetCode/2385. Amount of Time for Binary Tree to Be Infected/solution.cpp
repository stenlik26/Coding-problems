#include<iostream>
#include <string>
#include<vector>
#include<queue>
#include<unordered_set>
#include <list>

using namespace std;

struct TreeNode
 {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};



void fill_graph(TreeNode* prev, TreeNode* root, vector<list<int>*>& graph)
{
    if(root == nullptr)
        return;

    list<int>* current_vertex_list = new list<int>;

    if(root->left != nullptr)
        current_vertex_list->push_back(root->left->val);

    if(root->right != nullptr)
        current_vertex_list->push_back(root->right->val);

    if(prev != nullptr)
        current_vertex_list->push_back(prev->val);

    graph[root->val] = current_vertex_list;
    
    fill_graph(root, root->left, graph);
    fill_graph(root, root->right, graph);
}

int bfs_graph(vector<list<int>*>& graph, int start)
{
    int current_dist = 0;

    queue<pair<int,int>> nodes_to_visit;
    unordered_set<int> visited;

    nodes_to_visit.push({start, 0});

    while(!nodes_to_visit.empty())
    {
        pair<int,int> current = nodes_to_visit.front();
        nodes_to_visit.pop();

        if(visited.find(current.first) != visited.end())
            continue;

        visited.insert(current.first);

        current_dist = current.second;

        list<int>* vertex_list = graph[current.first];

        for(list<int>::iterator itr = vertex_list->begin(); itr != vertex_list->end(); ++itr)
        {
            if(visited.find(*itr) != visited.end())
                continue;

            nodes_to_visit.push({*itr, current_dist + 1});
        }
    }
    return current_dist;
}

int amountOfTime(TreeNode* root, int start) {
    
    vector<list<int>*> graph (100001, nullptr);

    fill_graph(nullptr, root, graph);

    return bfs_graph(graph, start);
}


int main()
{

    TreeNode* root = new TreeNode(
        1,
        new TreeNode(5, nullptr, new TreeNode(4, new TreeNode(9), new TreeNode(2))),
        new TreeNode(3, new TreeNode(10), new TreeNode(6))
    );

    cout << amountOfTime(root, 3) <<endl;

    return 0; 

}