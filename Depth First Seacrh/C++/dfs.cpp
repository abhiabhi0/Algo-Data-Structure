#include <iostream>
#include <vector>

class Graph
{
  int vertexCount; //no of Vertices
  enum class Color { WHITE, GRAY, BLACK };

  struct Vertex
  {
  int id;
  Color color;
  Vertex(int vertex, Color clr) : id(vertex), color(clr) {}
  };
  std::vector< std::vector<bool> > adjMatrix; //adjacency Matrix
  std::vector<Vertex> vertices;

public:
  Graph(int);
  void addEdge(int, int);
  void depthFirstSearch(int);
};

Graph::Graph(int v)
{
  vertexCount = v;
  adjMatrix.resize(vertexCount, std::vector<bool>(vertexCount));
  for(int i = 0; i < vertexCount; i++)
  {
    vertices.push_back( Vertex(i, Color::WHITE));
    for(int j = 0; j < vertexCount; j++)
    {
      adjMatrix[i][j] = false;
    }
   }
}

void Graph::addEdge(int a, int b)
{
  adjMatrix[a][b] = true;
  adjMatrix[b][a] = true;
}

void Graph::depthFirstSearch(int u)
{
  vertices[u].color = Color::GRAY;
  std::cout << vertices[u].id <<" ";

    for(int j = 0; j < vertexCount; j++)
    {
      if(adjMatrix[u][j] == true)
      {
        if(vertices[j].color == Color::WHITE)
        depthFirstSearch(j);
      }
    }

  vertices[u].color = Color::BLACK; //blacken u, it is finished
}

int main()
{
  Graph grp(4);
  grp.addEdge(0, 1);
  grp.addEdge(1, 2);
  grp.addEdge(2, 3);
  grp.addEdge(2, 1);
  grp.addEdge(0, 3);

  grp.depthFirstSearch(2);
  return 0;
}
