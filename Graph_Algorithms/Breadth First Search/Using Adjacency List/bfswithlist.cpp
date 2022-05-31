#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <limits>

class Graph
{
  int vertex_count;
  enum Color {WHITE, GRAY, BLACK};

  enum { INFINITY = std::numeric_limits<int>::max() };

  struct Vertex
  {
     int id;
     int distance;
     Color color;

     Vertex(int _id) : id(_id),
                       color(Color::WHITE),
                       distance(INFINITY)
                       {}
  };

public:

  std::vector<Vertex> vertices;
  std::vector< std::list<int> > adjList;

  Graph(int);
  void addEdge(int, int);
  void breadthFirstSearch(int);
};

Graph::Graph(int v)
{
   vertex_count = v;
   adjList.resize(vertex_count);
   for (int i = 0; i < vertex_count; i++)
   {
       vertices.push_back( Vertex(i) );
   }
}

void Graph::addEdge(int src, int dest)
{
  //undirected graph
   adjList[src].push_back(dest);
   adjList[dest].push_back(src);
}

void Graph::breadthFirstSearch(int s)
{
   vertices[s].color = GRAY;
   vertices[s].distance = 0;
   std::queue<Vertex> q;
   q.push(vertices[s]);
   while (!q.empty())
   {
      auto u = q.front();
      q.pop();
      for (const auto& v : adjList[u.id])
      {
         if (vertices[v].color == WHITE)
         {
            vertices[v].color = GRAY;
            vertices[v].distance = u.distance + 1;
            q.push(vertices[v]);
         }
      }
      u.color = BLACK;
      std::cout << vertices[u.id].id << " at level " << vertices[u.id].distance <<'\n';
   }
}

int main()
{
   Graph grp(5);
   grp.addEdge(0, 1);
   grp.addEdge(0, 4);
   grp.addEdge(1, 3);
   grp.addEdge(1, 4);
   grp.addEdge(1, 2);
   grp.addEdge(2, 3);
   grp.addEdge(3, 4);
   grp.breadthFirstSearch(2);
}
