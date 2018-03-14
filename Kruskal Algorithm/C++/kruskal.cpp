#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

class Graph
{
    std::size_t cost = 0;
    struct Vertex
    {
        std::size_t id;
        Vertex * parent = nullptr;
        std::size_t rank;
        Vertex(std::size_t id) : id(id) {}
    };

    using edges = std::pair<std::size_t, std::size_t>;

    std::vector<Vertex> vertices = {};
    std::vector< std::pair<edges, std::size_t> > edge_weight;
    std::unordered_set<std::size_t> processed = {};

  public:
    Graph(std::size_t);
    void add_edge(std::size_t, std::size_t, int);
    void kruskal();

  private:
    void make_set(std::size_t);
    void link(std::size_t, std::size_t);
    void union_(std::size_t, std::size_t);
    std::size_t find_set(std::size_t);
};

Graph::Graph(std::size_t size)
{
    vertices.reserve(size);
    for (int i = 0; i < size; i++)
    {
        vertices.emplace_back(i);
    }
}

std::size_t Graph::find_set(std::size_t vertex)
{
    auto it = vertices[vertex].parent;
    std::size_t parent_id = it->id;
    if (it != &vertices[vertex])
    {
        parent_id = find_set(it->id);
    }
    return parent_id;
}

void Graph::make_set(std::size_t vertex)
{
    vertices[vertex].parent = &vertices[vertex];
    vertices[vertex].rank   = 0;
}

void Graph::link(std::size_t to, std::size_t from)
{
    if (vertices[to].rank > vertices[from].rank)
    {
        vertices[from].parent = &vertices[to];
    }
    else
    {
        vertices[to].parent = &vertices[from];
        if (vertices[to].rank == vertices[from].rank)
        {
            vertices[from].rank = vertices[from].rank + 1;
        }
    }
}

void Graph::union_(std::size_t ver1, std::size_t ver2)
{
    link( find_set(vertices[ver1].id),
          find_set(vertices[ver2].id) );
}

void Graph::add_edge(std::size_t src, std::size_t dest, int weight)
{
    if (src == dest)
    {
        throw std::logic_error("src == dest");
    }

    if (src < 0 || vertices.size() <= src)
    {
        throw std::out_of_range("src");
    }

    if (dest < 0 || vertices.size() <= dest)
    {
        throw std::out_of_range("dest");
    }


    int flag = 0;
    for (auto& it: edge_weight)
    {
        if (it.first.first == src && it.first.second == dest)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        //insert vertices with their associated weight
        edge_weight.push_back({ {src, dest}, weight});
    }
    else
    {
        throw std::logic_error("existing edge");
    }
}

void Graph::kruskal()
{
    for (std::size_t i = 0; i < vertices.size(); i++)
    {
        make_set(i);
    }
    //sort according to weight in increasing order
    std::sort(edge_weight.begin(), edge_weight.end(),
              [](const auto& left, const auto& right)
              { return left.second < right.second; } );

    for (auto& e: edge_weight)
    {
        if ( find_set(vertices[e.first.first].id)
            != find_set(vertices[e.first.second].id) )
           {
                processed.insert(e.first.first);
                processed.insert(e.first.second);
                cost = cost + e.second;
                union_(e.first.first, e.first.second);
           }
    }
    std::cout << "The total cost is : " << cost << "\n";
}

int main()
{
    Graph grp(9);
    grp.add_edge(0, 1, 4);
    grp.add_edge(0, 2, 8);
    grp.add_edge(1, 2, 11);
    grp.add_edge(1, 3, 8);
    grp.add_edge(3, 4, 2);
    grp.add_edge(4, 2, 7);
    grp.add_edge(2, 5, 1);
    grp.add_edge(5, 4, 6);
    grp.add_edge(3, 6, 7);
    grp.add_edge(3, 8, 4);
    grp.add_edge(5, 8, 2);
    grp.add_edge(6, 7, 9);
    grp.add_edge(6, 8, 14);
    grp.add_edge(7, 8, 10);
    grp.kruskal();
}
