#include <iostream>
#include <fstream>
#include <string>

#include "Graph/Graph.hpp"

#define FILENAME "./../data/graph.txt"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Неверные аргументы. Правильный запуск: ./GraphBFS <filename>" << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input)
    {
        std::cerr << "Не удалось открыть файл." << std::endl;
        return 1;
    }

    int vertices, edges;
    input >> vertices >> edges;
    if (!input)
    {
        std::cerr << "Неверный ввод." << std::endl;
        return 1;
    }

    Graph graph(vertices);

    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        input >> u >> v;
        if (!input)
        {
            std::cerr << "Неверный ввод." << std::endl;
            return 1;
        }

        graph.addEdge(u, v);
    }

    int start;
    input >> start;
    if (!input)
    {
        std::cerr << "Неверный ввод." << std::endl;
        return 1;
    }

    for (int distance : graph.bfs(start))
        std::cout << distance << std::endl;

    return 0;
}