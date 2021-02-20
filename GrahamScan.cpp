#include<bits/stdc++.h>

#define piin    pair<int, int>
#define x       first
#define y       second

typedef long long ll;

using namespace std;

piin fp;
stack<piin>sol;

int orientation(piin p1, piin p2, piin q1)
{
    int ara= (p2.y-p1.y)*(q1.x-p2.x) - (p2.x-p1.x)*(q1.y-p2.y);

    return (ara==0)?ara:(ara>0)? 1:2;
}

bool cmp1(piin a, piin b)
{
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}

int dis2(piin p, piin q)
{
    return (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y);
}

bool cmp2(piin a, piin b)
{
    int o= orientation(fp, a, b);

    if(!o) return dis2(fp, a)<dis2(fp, b);
    return (o==2);
}

vector<piin> resize(vector<piin> points, int n)
{
    vector<piin> fin;
    fin.push_back(points[0]);

    for(int i=1; i<n; i++)
    {
        while(i<n-1 && orientation(fp, points[i], points[i+1])==0)
            i++;

        fin.push_back(points[i]);
    }
    return fin;
}

piin nxtop(stack<piin> sol)
{
    sol.pop();
    return sol.top();
}


stack<piin> convexHull(vector<piin> points, int n)
{
    sort(points.begin(), points.end(), cmp1);
    fp= points[0];
    sort(points.begin()+1, points.end(), cmp2);

    points= resize(points, n);
    n=points.size();

    sol.push(fp);
    sol.push(points[1]);
    sol.push(points[2]);

    for(int i=3; i<n; i++)
    {
        while (orientation(nxtop(sol), sol.top(), points[i])!=2)
            sol.pop();
        
        sol.push(points[i]);
    }

    return sol;
}

void printStack(stack<piin> s)
{
    cout<< "{ ";
    while(!s.empty())
    {
        piin p= s.top();
        cout<< '{'<< p.x<< ','<< p.y<< '}';
        s.pop();
        if(!s.empty()) cout<< " , ";
    }
    cout<< " }\n";
}

void input(int n, vector<piin> p)
{
    cin>> n;
    piin tmp;
    for(int i=0; i<n; i++)
    {
        cin>> tmp.x>> tmp.y;
        p.push_back(tmp);
    }
}

int main()
{
    int n=8;
    vector<piin>points;
    // uncomment the "input()" function for custom input
    input(n, points);
    // points= {{0, 3}, {1, 1}, {2, 2}, {4, 4}, 
    //         {0, 0}, {1, 2}, {3, 1}, {3, 3}};

    stack<piin> ans= convexHull(points, points.size());

    printStack(ans);    
}