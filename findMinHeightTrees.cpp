#include<list>
#include<map>
#include "findMinHeightTrees.h"

using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
	vector<int> nodeDegree;		// each element corespond to num of lines in each node
	int nodeLeft = n;
	map<int, vector<int>> adjacencyMatrix;
	list<int> currentNodes;

	for (int i = 0; i < n; i++)
	{
		nodeDegree.push_back(0);
		vector<int> vec;
		adjacencyMatrix[i] = vec;
	}

	// create a map that each node map to a vec of its connecting node
	for (auto vec : edges)
	{
		adjacencyMatrix[vec[0]].push_back(vec[1]);
		nodeDegree[vec[0]]++;
		adjacencyMatrix[vec[1]].push_back(vec[0]);
		nodeDegree[vec[1]]++;
	}

	// find leaf node to start with
	for (int i = 0; i < n; i++)
	{
		if (nodeDegree[i] == 1)
		{
			currentNodes.push_back(i);
		}
	}

	while (nodeLeft > 2)		// the MHT's root will be the center 1 node or 2 nodes
	{
		int num_to_pop = currentNodes.size();
		for (int i = 0; i < num_to_pop; i++)
		{
			int node = currentNodes.front();
			currentNodes.pop_front();
			nodeLeft--;
			nodeDegree[node]--;
			for (auto neighbor : adjacencyMatrix[node])
			{
				nodeDegree[neighbor]--;
				if (nodeDegree[neighbor] == 1)
				{
					currentNodes.push_back(neighbor);
				}
			}


		}
	}

	vector<int> root;
	int num_element = currentNodes.size();
	for (int i = 0; i < num_element; i++)
	{
		root.push_back(currentNodes.front());
		currentNodes.pop_front();
	}
	if (root.size() == 0)
	{
		root.push_back(0);
	}
	return root;
};
