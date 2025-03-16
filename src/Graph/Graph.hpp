#ifndef GPAPH_HPP_
#define GPAPH_HPP_

#include <vector>
#include <queue>

class Graph
{
public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    void addEdge(int u, int v)
    {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    std::vector<int> bfs(int start)
    {
        std::vector<int> distances(vertices, -1);
        std::queue<int> q;

        distances[start] = 0;
        q.push(start);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int v : adjacencyList[cur])
            {
                if (distances[v] == -1)
                {
                    distances[v] = distances[cur] + 1;
                    q.push(v);
                }
            }
        }
        return distances;
    }

    void print_graph()
    {
        for (int i = 0; i < this->vertices; ++i)
        {
            std::cout << "Вершина " << i << " связана с вершинами: ";
            for (int v : adjacencyList[i])
                std::cout << v << " ";
            std::cout << std::endl;
        }
    }

private:
    int vertices;
    std::vector<std::vector<int>> adjacencyList;
};

#endif // GPAPH_HPP_
