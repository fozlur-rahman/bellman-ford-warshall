#include <bits/stdc++.h>
using namespace std;
class Edges
{
public:
    int u;
    int v;
    int w;
    Edges(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edges> v;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edges ed(a, b, w);
        v.push_back(ed);
    }

    int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edges ed = v[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    bool cycle = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edges ed = v[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dis[a] + w < dis[b])
            {
                cycle = true;
                break;
                dis[b] = dis[a] + w;
            }
        }
    }
    if (cycle)
    {
        cout << "Cycle Exist";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "Node" << i << " : " << dis[i];
            cout << endl;
        }
    }

    return 0;
}