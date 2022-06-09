#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <list>
#include <queue>

class Graph
{
    enum Color {WHITE, BLACK};

    struct Vertex
    {
        std::size_t id;
        int distance = std::numeric_limits<int>::max();
        Color color = WHITE;
        Vertex(std::size_t id) : id(id) {}
    };

    // struct Edge
    // {
    //     std::size_t from;
    //     std::size_t to;
    //     bool operator<(const Edge& other) const
    //     {
    //         return std::tie(from, to) < std::tie(other.from, other.to);
    //     }
    // };

    using pair_ = std::pair<std::size_t, int>;
    std::vector<Vertex> vertices = {};

    //to store processed vertex
    std::vector<std::size_t> processed  = {};
    //adjacency list , store src, dest, and weight
    std::vector< std::vector< pair_> > adj_list;
    //to store unprocessed vertex min-priority queue
    std::priority_queue< pair_, std::vector<pair_>,
                         std::greater<pair_> > unprocessed;

  public:
    Graph(std::size_t size);
    void add_edge(std::size_t src, std::size_t dest, int weight);
    void dijkstra(std::size_t src);
    std::ostream& print_distance(std::ostream&) const;

  private:
    void relax(std::size_t src, std::size_t dest, int weight);
};

Graph::Graph(std::size_t size)
{
    vertices.reserve(size);
    adj_list.resize(size);
    for (int i = 0; i < size; i++)
    {
        vertices.emplace_back(i);
    }
}

void Graph::add_edge(std::size_t src , std::size_t dest, int weight)
{
    if(weight >= 0)
    {
        if (src == dest)
        {
            throw std::logic_error("Source and destination vertices are same");
        }

        if (src < 0 || vertices.size() <= src)
        {
            throw std::out_of_range("Enter correct source vertex");
        }

        if (dest < 0 || vertices.size() <= dest)
        {
            throw std::out_of_range("Enter correct destination vertex");
        }

        int flag = 0, i = src;
        for (auto& it : adj_list[i])
        {
            if (it.first == dest)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            adj_list[src].push_back( {dest, weight} );
        }
        else
        {
            throw std::logic_error("Existing edge");
        }

    }
    else
    {
        std::cerr << "Negative weight\n";
    }
}

void Graph::relax(std::size_t src, std::size_t dest, int weight)
{
    auto& next_dist = vertices[dest].distance;
    const auto curr_dist = vertices[src].distance + weight;
    if (curr_dist < next_dist)
    {
        next_dist = curr_dist;
        //update distance in unprocessed queue
        unprocessed.push( std::make_pair(next_dist, dest));
    }
}

void Graph::dijkstra(std::size_t src)
{
    //initialize distance of source
    vertices[src].distance = 0;

    unprocessed.push( std::make_pair(vertices[src].distance, src) );
    while (!unprocessed.empty())
    {
         int curr_vertex_dist = unprocessed.top().first;
         std::size_t curr_vertex = unprocessed.top().second;
         unprocessed.pop();

        if (vertices[curr_vertex].color == WHITE)
        {
            processed.push_back(curr_vertex);
        }
        vertices[curr_vertex].color = BLACK;
        for (auto& ver: adj_list[curr_vertex])
        {
            relax(curr_vertex, ver.first, ver.second);
        }
    }
}

std::ostream& Graph::print_distance(std::ostream& os) const
{
    os << "Vertex\t\tDistance from Source\n";
    for (auto vertex: vertices)
    {
        os << vertex.id << "\t\t" << vertex.distance << "\n";
    }
    return os;
}

int main()
{
    Graph grp(5);
    grp.add_edge(0, 1, 10);
    grp.add_edge(0, 2, 5);
    grp.add_edge(1, 3, 1);
    grp.add_edge(1, 2, 2);
    grp.add_edge(2, 1, 3);
    grp.add_edge(2, 3, 9);
    grp.add_edge(2, 4, 2);
    grp.add_edge(3, 4, 4);
    grp.add_edge(4, 3, 6);
    grp.add_edge(4, 0, 7);
    grp.dijkstra(0);
    grp.print_distance(std::cout);
}
