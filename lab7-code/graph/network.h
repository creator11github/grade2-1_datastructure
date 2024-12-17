#ifndef NETWORK
#define NETWORK

#include <map>
#include <list>
#include <queue>

using namespace std;

//template<class vertex, class Compare = less<vertex> >
template<class vertex>
class network
{
		//node in the adjacency list, a to-vetex, an associated weight
        struct vertex_weight_pair
        {
            vertex to;
            double weight;

            // Postcondition: this vertex_weight_pair has been initialized
            //                from x and y.
            vertex_weight_pair (const vertex& x, const double& y)
            {
                to = x;
                weight = y;
            } // two-parameter constructor

            // Postcondition: true has been returned if this
            //                vertex_weight_pair is less than x.
            //                Otherwise, false has been returned.
            bool operator> (const vertex_weight_pair& p) const
            {
                return weight > p.weight;
            } // operator>

        }; // class vertex_weight_pair

        typedef typename std::list<vertex_weight_pair> adj_list; //adjacency list
        typedef typename adj_list::iterator adj_list_itr; //adjacency list iterotor
		typedef typename std::map<vertex, adj_list> ver_adj_map; //map each vetex to its adjacency list
        typedef typename ver_adj_map::iterator ver_adj_map_itr;

    protected:
        ver_adj_map ver_adj; //vertex - adjacency list map

    public:

		// Postcondition: this network is empty.
		network() { }

		// Postcondition: the number of vertices in this network has been
		//                returned.
		unsigned int size()
		{
			return ver_adj.size();
		} // method size


		// Postcondition: true has been returned if this network contains no
		//                vertices.  Otherwise, false has been returned.
		bool empty()
		{
			return size() == 0;
		} // method empty


		// Postcondition: true has been returned if this network contains the
		//                edge <v1, v2>.  Otherwise, false has been returned.
		bool contains_edge(const vertex& v1, const vertex& v2)
		{
			ver_adj_map_itr itr = ver_adj.find(v1);
			if (itr == ver_adj.end() || ver_adj.find(v2) == ver_adj.end()) //not both exist
				return false;

			adj_list_itr list_itr;

			for (list_itr = ((*itr).second).begin(); //itr points to a pair in ver_adj_map: first:vertex, second:adj_list
					list_itr != ((*itr).second).end();
						list_itr++)
				if ((*list_itr).to == v2) //vertex-weight-struct
					return true;
			return false;
		} // method contains_edge


		// Postcondition: if v is already in this network, false has been
		//                returned. Otherwise, the map with v and an empty list
		//                has been added to this network and true has been
		//                returned.
		bool insert_vertex(const vertex& v)
		{
			return ver_adj.insert(
				pair<vertex, list<vertex_weight_pair> > //map stores pair type
				(v, list<vertex_weight_pair>()) //empty list
			).second; //map insert returns pair<iterator,bool> 
		} // method insert_vertex


		// Postcondition: if the edge <v1, v2> is already in this network false
		//                has been returned. Otherwise, that edge with the
		//                given weight has been inserted in this network and
		//                true has been returned.
		bool insert_edge(const vertex& v1, const vertex& v2, const double& weight)
		{
			if (contains_edge(v1, v2))
				return false;
			insert_vertex(v1); //may already exist
			insert_vertex(v2); //may already exist
			(*(ver_adj.find(v1))).second.push_back(vertex_weight_pair(v2, weight));
			return true;
		} // method insert_edge


		/*=======================================DIJKSTRA'S ALGORITHM==========================================================*/
        // Postcondition: the shortest path from v1 to v2 and its total weight
        //                have been returned; if such a path is found,
		//				  returns the list of vertices on the shortest path
		//				  and the total weight of the shortest path;
		//				  otherwise, returns an empty list and the value -1.0
        pair<list<vertex>, double> get_shortest_path (const vertex& v1, const vertex& v2)
        {
            const double MAX_PATH_WEIGHT = 1000000.0;

			map<vertex, vertex> path_predecessor; //reconstruct path
			map<vertex, double> partial_path_weight; //partial path weight
			
            if (ver_adj.find (v1) == ver_adj.end() || ver_adj.find (v2) == ver_adj.end()) //not both exist
                return pair<list<vertex>, double> (list<vertex>(), -1.0);

			//intialize partial path weight and path predecessor
			vertex curr_vertex;
			for (ver_adj_map_itr itr = ver_adj.begin(); itr != ver_adj.end(); itr++)
			{
				curr_vertex = (*itr).first; //vetex of map
				if (curr_vertex == v1)
				{
					partial_path_weight[curr_vertex] = 0.0;
					path_predecessor[curr_vertex] = curr_vertex;
				}
				else
				{
					partial_path_weight[curr_vertex] = MAX_PATH_WEIGHT;
					path_predecessor[curr_vertex] = vertex();
				}
			}

			priority_queue<vertex_weight_pair,
				vector<vertex_weight_pair>, //define storage
				greater<vertex_weight_pair> > pq; //define what priority is

			//initialize priority queue
			pq.push(vertex_weight_pair(v1, 0.0));

			//temp variables
			vertex to, from;
			adj_list curr_adj_list;
			double weight;
            bool path_found = false;
            while (!path_found && pq.empty()==false)
            {
                from = pq.top().to;  // get vertex in vertex_weight_pair
                                     // with smallest weight sum
                pq.pop();
                if (from == v2)
                    path_found = true;
                else
                {
                    curr_adj_list = ver_adj[from];
                    for (adj_list_itr curr_adj_list_itr = curr_adj_list.begin();
                         curr_adj_list_itr != curr_adj_list.end();
                         curr_adj_list_itr++)
                    {
                        to = (*curr_adj_list_itr).to;
                        weight = (*curr_adj_list_itr).weight;
						//update partial path weight
                        if (partial_path_weight[from] + weight < partial_path_weight[to])
                        {
                            partial_path_weight[to] = partial_path_weight[from] + weight;
                            path_predecessor[to] = from;
                            pq.push(vertex_weight_pair(to, partial_path_weight[to])); //what if to already exist? both kept?
                        } // if from_weight_sum + weight > to_weight_sum
                    } // for iterating over from's list
                } // else path not yet found
            } // while path not found

			//pq empty; not found
			if (!path_found)
				return pair<list<vertex>, double>(list<vertex>(), -1.0);

			else
			{
				//construct path
				list<vertex> path;
				vertex current = v2;
				while (current != v1)
				{
					path.push_front(current);
					current = path_predecessor[current];
				} // while not yet back to v1
				path.push_front(v1);

				return pair<list<vertex>, double>(path, partial_path_weight[v2]);
			}

        } // method get_shortest_path

}; // class network

#endif