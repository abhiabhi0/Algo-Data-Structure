#include <iostream>
#include <queue>
#include <limits>
#include <vector>

class Graph
{
  int vertexCount;
  //WHITE means Undiscovered, GRAY means Discovered, BLACK menas Processed
  enum class Color{ WHITE, GRAY, BLACK };

  const int imax = std::numeric_limits<int>::max();

  struct Vertex
  {
  	int id;
    Color color;
  	size_t distance;

  	Vertex(const int vertex, Color clr, int imax) : id(vertex),
                                                    color(clr),
                                                    distance(imax)
                                                    {};
  };
  std::vector< std::vector<bool> > adjMatrix; //adjacency adjMatrix
  std::vector<Vertex> vertices;
public:
	Graph(int size)
  {
    vertexCount = size;
    adjMatrix.resize(vertexCount, std::vector<bool>(vertexCount));
    for(int i = 0; i < vertexCount; i++)
    {
      vertices.push_back( Vertex(i, Color::WHITE, imax));
      for(int j = 0; j < vertexCount; j++)
        adjMatrix[i][j] = false;
    }
  }
	~Graph() {};

	void BFS(const int);
	void addEdge(int, int);
	void printMatrix();
};

void Graph::BFS(const int src)
{
	const auto s = vertices[src].id;
	vertices[s].color = Color::GRAY;
	vertices[s].distance = 0;


	std::queue<int> Q;
	Q.push(vertices[s].id);

	while(!Q.empty())
	{
		auto u = Q.front();
		Q.pop();

		for (int j = 0; j < vertexCount; j++)
		{
			if(vertices[j].color == Color::WHITE && adjMatrix[u][j] == true)
			{
				vertices[j].color = Color::GRAY;
				vertices[j].distance = vertices[u].distance + 1;
				Q.push(j);
			}
		}
		vertices[u].color = Color::BLACK;
    std::cout << vertices[u].id << " at level " << vertices[u].distance <<'\n';
	}
}

void Graph::addEdge(int u, int v)
{
	adjMatrix[u][v] = true;
  adjMatrix[v][u] = true;
}

void Graph::printMatrix()
{
	for(int i = 0; i < vertexCount; i++)
  {
    for(int j = 0; j < vertexCount; j++)
    {
      std::cout << adjMatrix[i][j] << " ";
    }
    std::cout << '\n';
  }
}

int main()
{
	Graph grp1(8);
	grp1.addEdge(0, 1);
  grp1.addEdge(0, 2);
  grp1.addEdge(1, 3);
  grp1.addEdge(1, 4);
  grp1.addEdge(2, 5);
  grp1.addEdge(3, 4);
  grp1.addEdge(3, 6);
  grp1.addEdge(4, 6);
  grp1.addEdge(4, 7);
  grp1.addEdge(6, 7);

	grp1.BFS(0);
  std::cout << "\nAdjacency Matrix for the Graph is \n";
	grp1.printMatrix();
}
