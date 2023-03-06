#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <stack>
#include <map>
#include <ctime>
#include <array>
#include <set>
#include <list>
// 检验是否是有向无环图？ 
using namespace std;

//图的抽象类函数构建 
// Template Type Edge
template<class TypeOfEdge>
struct Edge_pair
{
	int point = 0;
	TypeOfEdge length = 0;
};
// Template Type Vertices
template<class TypeOfVer, class TypeOfEdge>
struct verNode
{
	TypeOfVer ver_data;
	list<Edge_pair<TypeOfEdge> > group;
	//Struct and destruct
	verNode()
	{
		group.clear();
		//ver_data = 0;
	}
	TypeOfVer getVer()
	{
		return ver_data;
	}
	//List Tableur
	list<Edge_pair<TypeOfEdge> > getHead()
	{
		return group;
	}
	void setdata(TypeOfVer value)
	{
		ver_data = value;
		return;
	}

 
	void creat_Point(int new_point, TypeOfEdge new_length)
	{
		Edge_pair<TypeOfEdge> Next_p;
		Next_p.point = new_point;
		Next_p.length = new_length;
		group.insert(group.begin(), Next_p);
		return;
	}

	void del_Point(int n)
	{
 
		return;
	}
};
 
template <class TypeOfVer, class TypeOfEdge>//Weight and Types
class adjlist_graph {
private:
	int Vers;//Number of vertices
	int Edges;//Number of edges 
	vector<verNode<TypeOfVer, TypeOfEdge> >ver;//Saving
	string GraphKind; 
	bool have_dir = false, have_w = false;
 
	vector<TypeOfVer> dfs_map;
	vector<bool> dfs_vis;
	//Delete edges
	bool Delete_Edge(int u, int v)
	{
		return false;
	}
	bool DFS(int t)//DFS recursion
	{
		dfs_map.push_back(ver[t].ver_data);
		dfs_vis[t] = true;
		for(auto i= ver[t].group.begin();i!= ver[t].group.end();i++)
			if (dfs_vis[i->point] == false)
				DFS(i->point);
		return true;
	}
 
public:
	adjlist_graph()
	{
		Edges = 0;
		Vers = 0;
	}
	//destruct
	~adjlist_graph()
	{
		;
	}
	bool GraphisEmpty()
	{
		return Vers == 0;
	}

	string GetGraphKind()
	{
		return GraphKind;
	}
	int GetVerNum()
	{
		return Vers;
	}

	int GetEdgeNum()
	{
		return Edges;
	}
	// adjactent table
	bool Auto_build(void)
	{
		cin >> GraphKind;
		cin >> Vers;
		ver.resize(Vers);
		for (int i = 0; i < Vers; i++)
		{
			TypeOfVer now;
			cin >> now;
			ver[i].setdata(now);
		}
 
 
		cin >> Edges;
		vector<int> x_p, y_p, w_p;
		for (int i = 0; i < Edges; i++)
		{
			int c_x, c_y;
			cin >> c_x >> c_y;
			x_p.push_back(c_x);
			y_p.push_back(c_y);
		}

		if (GraphKind == "DG")//DGDirected
			have_dir = true, have_w = false;
		if (GraphKind == "DN")//DN Directed Network
			have_dir = true, have_w = true;
		if (GraphKind == "UDG")//Undirected
			have_dir = false, have_w = false;
		if (GraphKind == "UDN")
			have_dir = false, have_w = true;
 
		if (have_w)
			for (int i = 0; i < Edges; i++)
			{
				int c_w;
				cin >> c_w;
				w_p.push_back(c_w);
			}
 
 
		for (int i = 0; i < Edges; i++)
		{
			if (have_dir)
				if (have_w)
					ver[x_p[i]].creat_Point(y_p[i], w_p[i]);
				else
					ver[x_p[i]].creat_Point(y_p[i], 0);
			else
				if (have_w)
					ver[x_p[i]].creat_Point(y_p[i], w_p[i]), ver[y_p[i]].creat_Point(x_p[i], w_p[i]);
				else
					ver[x_p[i]].creat_Point(y_p[i], 0), ver[y_p[i]].creat_Point(x_p[i], 0);
		}
		return 1;
	}
	vector<TypeOfVer> GetVer(void)
	{
		vector<TypeOfVer> head_group;
		for (int i = 0; i < Vers; i++)
		{
			head_group.push_back(ver[i].getVer());
		}
		return head_group;
	}
	bool Print_photo()
	{
		int i;
		for (i = 0; i < Vers; i++)
		{
			cout << ver[i].getVer();
			if (ver[i].group.size() != 0)
				cout << "->";
			else
			{
				cout << endl;
				continue;
			}
			vector<Edge_pair<TypeOfEdge> > out_lis;
			out_lis.clear();
			for (auto j = ver[i].group.begin(); j != ver[i].group.end(); j++)
			{
				out_lis.push_back(*j);
			}
			int j;
			for (j = 0; j < out_lis.size() - 1; j++)
				if (have_w)
					cout << out_lis[j].point << "(" << out_lis[j].length << ")" << "->";
				else
					cout << out_lis[j].point << "->";
			if (have_w)
				cout << out_lis[j].point << "(" << out_lis[j].length << ")" << endl;
			else
				cout << out_lis[j].point << endl;
		}
		return 1;
	}
	bool InsertVer(const TypeOfVer& data)
	{
		verNode<TypeOfVer, TypeOfEdge> new_e;
		new_e.setdata(data);
		ver.push_back(new_e);
		Vers++;
		return true;
	}
	int Look_Ver(const TypeOfVer& data)
	{
		int i;
		for (i = 0; i < Vers; i++)
			if (ver[i].ver_data == data)
				return i;
		return -1;
	}
	bool del_Point(int place)
	{
		int need_del = 0;
		if (!(0 <= place && place < Vers))
			return false;
		int i;
		for (i = 0; i < Vers; i++)
		{
			for (auto j = ver[i].group.begin(); j != ver[i].group.end(); j++)
			{
				if (j->point == place)
				{
					need_del++;
					ver[i].group.erase(j);
					break;
				}
			}
			for (auto j = ver[i].group.begin(); j != ver[i].group.end(); j++)
			{
				if (j->point > place)
					j->point--;
			}
		}
		need_del += ver[place].group.size();
		ver.erase(ver.begin() + place);
		Vers--;
		if (have_dir)
			Edges -= need_del;
		else
			Edges -= (need_del / 2);
		return true;
	}
	bool Insert_Edge(int u, int v)
	{
		if (!(0 <= u && u < Vers))
			return false;
		if (!(0 <= v && v < Vers))
			return false;
		for (auto i = ver[u].group.begin(); i != ver[u].group.end(); i++)
		{
			if (i->point == v)
				return false;
		}
		for (auto i = ver[v].group.begin(); i != ver[v].group.end(); i++)
		{
			if (i->point == u)
				return false;
		}
		if (u == v)
			return false;
		if (have_dir)
		{
			Edges++;
			ver[u].creat_Point(v, 1);
			return true;
		}
		else
		{
			Edges++;
			ver[u].creat_Point(v, 1);
			ver[v].creat_Point(u, 1);
			return true;
		}
		return true;
	}
	bool Insert_Edge(int u, int v, TypeOfEdge w)
	{
		if (!(0 <= u && u < Vers))
			return false;
		if (!(0 <= v && v < Vers))
			return false;
		for (auto i = ver[u].group.begin(); i != ver[u].group.end(); i++)
		{
			if (i->point == v)
				return false;
		}
		for (auto i = ver[v].group.begin(); i != ver[v].group.end(); i++)
		{
			if (i->point == u)
				return false;
		}
		if (u == v)
			return false;
		if (have_dir)
		{
			Edges++;
			ver[u].creat_Point(v, w);
			return true;
		}
		else
		{
			Edges++;
			ver[u].creat_Point(v, w);
			ver[v].creat_Point(u, w);
			return true;
		}
		return true;
	}
	bool del_Edge(int u, int v)
	{
		if (!(0 <= u && u < Vers))
			return false;
		if (!(0 <= v && v < Vers))
			return false;
		if (u == v)
			return false;
		bool ok = true;
		if(have_dir)
			for (auto i = ver[u].group.begin(); i != ver[u].group.end(); i++)
			{
				if (i->point == v)
				{
					ver[u].group.erase(i);
					Edges--;
					return true;
				}
			}
		else
		{
			for (auto i = ver[u].group.begin(); i != ver[u].group.end(); i++)
			{
				if (i->point == v)
				{
					ver[u].group.erase(i);
					break;
				}
			}
			for (auto i = ver[v].group.begin(); i != ver[v].group.end(); i++)
			{
				if (i->point == u)
				{
					ver[v].group.erase(i);
					Edges--;
					return true;
				}
			}
		}
			
		return false;
	}
	
	int GetFirst_AdjVex(int u)
	{
		if(ver[u].group.empty())
			return -1;
		return ver[u].group.begin()->point;
	}
	int GetNext_AdjVex(int u, int v)
	{
		if (ver[u].group.size() == 1)
			return -1;
		for (auto i = ver[u].group.begin(); i != ver[u].group.end(); i++)
		{
			if (i->point == v)
			{
				if ((++i) == ver[u].group.end())
					return -1;
				return i->point;
			}
		}
		return -1;
	}
 
	bool look_Edge(int u, int v)
	{
		if (!(0 <= u && u < Vers))
			return false;
		if (!(0 <= v && v < Vers))
			return false;
		if (u == v)
			return false;
		for (auto i = ver[u].group.begin(); i != ver[u].group.end(); i++)
		{
			if (i->point == v)
				return true;
		}
		for (auto i = ver[v].group.begin(); i != ver[v].group.end(); i++)
		{
			if (i->point == u)
				return true;
		}
		return false;
	}
	int Get_legthOfEdge(int u, int v)
	{
		if (!have_w)
			return -1;
		if (!(0 <= u && u < Vers))
			return -1;
		if (!(0 <= v && v < Vers))
			return -1;
		if (u == v)
			return -1;
		for (auto i = ver[u].group.begin(); i != ver[u].group.end(); i++)
		{
			if (i->point == v)
				return i->length;
		}
		return -1;
	}
	int Search_enterDegree(int p)
	{
		if (!(0 <= p && p < Vers))
			return -1;
		if (!have_dir)
			return ver[p].group.size();
		int cnt = 0;
		for (int i = 0; i < Vers; i++)
		{
			if(i!=p)
				for (auto j = ver[i].group.begin(); j != ver[i].group.end(); j++)
				{
					if (j->point == p)
						cnt++;
				}
		}
		return cnt;
	}
	int Search_outDegree(int p)
	{
		if (!(0 <= p && p < Vers))
			return -1;
		return ver[p].group.size();
	}
	bool look_haveDir(void)
	{
		return have_dir;
	}
	//DFS
	void DFS_Traverse(int star)
	{
		dfs_map.clear();
		dfs_vis.clear();
		for (int i = 0; i < Vers; i++)
			dfs_vis.push_back(false);
		DFS(star);
		int i;
		for (i = 0; i < dfs_map.size()-1; i++)
			cout << dfs_map[i] << "->";
		cout << dfs_map[i] << endl;
		return;
	}
	//BFS
	void BFS_Traverse(int star)
	{
		vector<TypeOfVer> bfs_lis;
		vector<bool>bfs_vis;
 
		bfs_lis.clear();
		bfs_vis.clear();
		for (int i = 0; i < Vers; i++)
			bfs_vis.push_back(false);
 
		queue<int> Q;
		Q.push(star);
		bfs_vis[star] = true;
		bfs_lis.push_back(ver[star].ver_data);
 
		int now;
		while (!Q.empty())
		{
			now = Q.front();
			Q.pop();
			for (auto i = ver[now].group.begin(); i != ver[now].group.end(); i++)
					if (bfs_vis[i->point] == false)
					{
						bfs_lis.push_back(ver[i->point].ver_data);
						bfs_vis[i->point] = true;
						Q.push(i->point);
					}
		}
		int i;
		for (i = 0; i < bfs_lis.size() - 1; i++)
			cout << bfs_lis[i] << "->";
		cout << bfs_lis[i] << endl;
 
		return;
	}
	//If there is any path?
	bool Search_way(int star, int v)
	{
		vector<bool>bfs_vis;
 
		bfs_vis.clear();
		for (int i = 0; i < Vers; i++)
			bfs_vis.push_back(false);
 
		queue<int> Q;
		Q.push(star);
		bfs_vis[star] = true;
 
		int now;
		while (!Q.empty())
		{
			now = Q.front();
			if (now == v)
				return true;
			Q.pop();
			for (auto i = ver[now].group.begin(); i != ver[now].group.end(); i++)
				if (bfs_vis[i->point] == false)
				{
					bfs_vis[i->point] = true;
					Q.push(i->point);
				}
		}
		return false;
	}
	// Topology Ording and output
	bool TopologicalSort(void)
	{
		if (Edges == 0)
			return 0;
		int i, j;
		vector<int> indegree;
		indegree.clear();
		for (i = 0; i < Vers; i++)
			indegree.push_back(Search_enterDegree(i));
		queue<int> S;
		for (i = 0; i < indegree.size(); i++)
			if (indegree[i] == 0)
				S.push(i);
		vector<int> sort_list;//the way of sort
		//BFS
		while (!S.empty())
		{
			int now;
			now = S.front();
			S.pop();
			sort_list.push_back(now);
			int next_p;
			next_p = GetFirst_AdjVex(now);
			while (next_p != -1)
			{
				--indegree[next_p];
				if (indegree[next_p] == 0)
					S.push(next_p);
				next_p = GetNext_AdjVex(now, next_p);
			}
		}
		if (sort_list.size() == 0)
			return 0;
		for (i = 0; i < sort_list.size() - 1; i++)
			cout << ver[sort_list[i]].ver_data << "->";
		cout << ver[sort_list[i]].ver_data << endl;
		if (sort_list.size() < Vers)
			return 0;
		return 1;
	}
	bool Check_circle()
	{
		if (Edges == 0)
			return 0;
		int i, j;
		vector<int> indegree;
		indegree.clear();
		for (i = 0; i < Vers; i++)
			indegree.push_back(Search_enterDegree(i));
		queue<int> S;
		for (i = 0; i < indegree.size(); i++)
			if (indegree[i] == 0)
				S.push(i);
		vector<int> sort_list;//the way of sort
		//BFS
		while (!S.empty())
		{
			int now;
			now = S.front();
			S.pop();
			sort_list.push_back(now);
			int next_p;
			next_p = GetFirst_AdjVex(now)
			while (next_p != -1)
			{
				--indegree[next_p];
				if (indegree[next_p] == 0)
					S.push(next_p);
				next_p = GetNext_AdjVex(now, next_p);
			}
		}
		if (sort_list.size() < Vers)
			return 1;
		return 0;
	}
	bool Check_DAG()
	{
		if (Edges == 0)
			return 0;
		int i, j;
		vector<int> indegree;
		indegree.clear();
		for (i = 0; i < Vers; i++)
			indegree.push_back(Search_enterDegree(i));
		queue<int> S;
		for (i = 0; i < indegree.size(); i++)
			if (indegree[i] == 0)
				S.push(i);
		vector<int> sort_list;//the way of sort
		//BFS
		while (!S.empty())
		{
			int now;
			now = S.front();
			S.pop();
			sort_list.push_back(now);
			int next_p;
			next_p = GetFirst_AdjVex(now);
			while (next_p != -1)
			{
				--indegree[next_p];
				if (indegree[next_p] == 0)
					S.push(next_p);
				next_p = GetNext_AdjVex(now, next_p);
			}
		}
		if (sort_list.size() < Vers)
			return 0;
		return 1;
	}
};
 
 
int main()
{
	int i;
	adjlist_graph<string, int> a;
	a.Auto_build();
	vector <string> ans;
	ans = a.GetVer();
	for (i = 0; i < ans.size() - 1; i++)
		cout << ans[i] << " ";
	cout << ans[i] << endl;
	a.Print_photo();	
	cout << endl;
	if (a.Check_DAG())
		cout << "true" << endl;
	else
		cout << "false" << endl;
 
	return 0;
}
