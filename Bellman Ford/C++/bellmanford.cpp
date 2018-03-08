#include <iostream>
#include <vector>
#include <limits>
#include <map>

class Graph
{

    struct Vertex
    {
        std::size_t id;
        int distance = std::numeric_limits<int>::max();
        Vertex(std::size_t id) : id(id) {}
    };
    std::vector<Vertex> vertices;
    std::map<std::pair<std::size_t, std::size_t>, int> edge_weight;

  public:
    Graph(std::size_t);
    void add_edge(std::size_t, std::size_t, int); //source, destination, weight
    bool bellman_ford(std::size_t); //source
    std::ostream& distance_from_source(std::ostream&) const;

  private:
    void relax(std::size_t, std::size_t, int); //source, destination, weight
};

Graph::Graph(std::size_t size)
{
    vertices.reserve(size);
    for (int i = 0; i < size; i++)
    {
        vertices.push_back(Vertex(i));
    }
}

void Graph::add_edge(std::size_t src, std::size_t dest, int weight)
{
    if (src == dest)
        throw std::logic_error("Source and destination vertices are same");

    if (src < 0 || vertices.size() <= src)
        throw std::out_of_range("Enter correct source vertex");

    if (dest < 0 || vertices.size() <= dest)
        throw std::out_of_range("Enter correct destination vertex");

    const auto inserted = edge_weight.insert(std::make_pair(
                          std::make_pair(src, dest), weight ));
    if (!inserted.second)
        throw std::logic_error("Existing edge");
}

void Graph::relax(std::size_t src, std::size_t dest, int weight)
{
    if (vertices[dest].distance > (vertices[src].distance + weight))
    {
        vertices[dest].distance = (vertices[src].distance + weight);
    }
}

bool Graph::bellman_ford(std::size_t src)
{
    //initialize distance of source
    vertices[src].distance = 0;

    for (int i = 0; i < vertices.size() - 1; i++)
    {
        for (auto it = edge_weight.begin(); it != edge_weight.end(); it++)
        {
            relax(it->first.first, it->first.second, it->second);
        }
    }

    for (auto it = edge_weight.begin(); it != edge_weight.end(); it++)
    {
        if (vertices[it->first.second].distance
            > (vertices[it->first.first].distance + it->second))
           return false;
    }
    return true;
}

std::ostream& Graph::distance_from_source(std::ostream& os) const
{
    os << "Vertex\t\tDistance from Source\n";
    for (int i = 0; i < vertices.size(); i++)
    {
        os << vertices[i].id <<"\t\t" << vertices[i].distance <<"\n";
    }
}


int main()
{
    Graph grp(5);
    grp.add_edge(0, 1, 6);
    grp.add_edge(0, 2, 7);
    grp.add_edge(1, 3, 5);
    grp.add_edge(1, 4, -4);
    grp.add_edge(1, 2, 8);
    grp.add_edge(2, 3, -3);
    grp.add_edge(2, 4, 9);
    grp.add_edge(3, 1, -2);
    grp.add_edge(4, 0, 2);
    grp.add_edge(4, 3, 7);

    bool res = grp.bellman_ford(0);
    if (res == true)
       std::cout << "Graph contains no negative cycle \n";
    else
       std::cout << "Graph conatins negative cycle \n";

    grp.distance_from_source(std::cout);
}
