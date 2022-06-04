#include <iostream>
#include <vector>

class Graph
{
   int vertex_count;
   enum Color {WHITE, GRAY, BLACK};

   struct Vertex
   {
      int id;
      Color color;
      Vertex(int _id) : id(_id),
                        color(Color::WHITE)
                        {}
   };

   struct Adj_list_node
   {
      int dest_id;
      Adj_list_node * next;
      Adj_list_node(int _dest_id) : dest_id(_dest_id),
                                    next (nullptr)
                                    {}
   };

   struct Adj_list
   {
      Adj_list_node *head;
   };

   std::vector<Vertex> vertices;
   std::vector<Adj_list> adjacent;

public:
   Graph(int);
   void add_edge(int, int);
   void depth_first_search();

 private:
   void depth_first_search_visit(int);
};

Graph::Graph(int v)
{
   vertex_count = v;
   adjacent.resize(vertex_count);

   for (int i = 0; i < vertex_count; i++)
   {
       vertices.push_back( Vertex(i) );
       adjacent[i].head = nullptr;
   }
}

void Graph::depth_first_search()
{
   for (const auto& u: vertices)
   {
      if (vertices[u.id].color == WHITE)
      {
         depth_first_search_visit(u.id);
      }
   }
}

void Graph::depth_first_search_visit(int u)
{
   vertices[u].color = GRAY;
   std::cout << vertices[u].id <<" ";
   const auto& v = adjacent[u].head;
      if (vertices[v->dest_id].color == WHITE)
      {
         depth_first_search_visit(v->dest_id);
      }
   vertices[u].color = BLACK;
}

void Graph::add_edge(int src, int dest)
{
   Adj_list_node *node = new Adj_list_node(dest);
   if (adjacent[src].head == nullptr)
   {
      adjacent[src].head = node;
   }
   else
   {
      Adj_list_node *tmp = adjacent[src].head;
      while (tmp->next != nullptr)
             tmp = tmp->next;

      tmp->next = node;
   }

   //undirected graph
   node = new Adj_list_node(src);
   if (adjacent[dest].head == nullptr)
   {
      adjacent[dest].head = node;
   }
   else
   {
     Adj_list_node *tmp = adjacent[dest].head;
     while (tmp->next != nullptr)
            tmp = tmp->next;

     tmp->next = node;
   }
}

int main()
{
   Graph grp(4);
   grp.add_edge(0, 1);
   grp.add_edge(1, 2);
   grp.add_edge(2, 3);
   grp.add_edge(2, 1);
   grp.add_edge(0, 3);
   grp.depth_first_search();
   std::cout << "\n";
}
