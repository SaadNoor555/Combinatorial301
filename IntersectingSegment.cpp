#include<bits/stdc++.h>

#define piin    pair<int, int>
#define sc      second
#define fr      first

typedef long long ll;

using namespace std;

piin p1, p2, q2, q1;

int orientation(piin p1, piin p2, piin q1)
{
    int ara= (p2.sc-p1.sc)*(q1.fr-p2.fr) - (p2.fr-p1.fr)*(q1.sc-p2.sc);

    return (ara==0)?ara:(ara>0)? 1:2;
}

bool onSeg(piin p, piin q, piin r)
{
    if(q.fr<=max(p.fr, r.fr) && q.fr>=min(p.fr, r.fr) && q.sc<=max(p.sc, r.sc) && q.sc>=min(p.sc, r.sc)) return 1;
    return 0;
}

bool intersect()
{
    int or1, or2, or3, or4;

    or1= orientation(p1, p2, q1);
    or2= orientation(p1, p2, q2);
    or3= orientation(q1, q2, p1);
    or4= orientation(q1, q2, p2);

    if(or1!=or2 && or3!=or4) return 1;

    if(!or1 && onSeg(p1, p2, q1)) return 1;
    if(!or2 && onSeg(p1, p2, q2)) return 1;
    if(!or3 && onSeg(q1, q2, p1)) return 1;
    if(!or4 && onSeg(q1, q2, p2)) return 1;

    return 0;
}

void input()
{
    cin>> p1.fr>> p1.sc;
    cin>> p2.fr>> p2.sc;
    cin>> q1.fr>> q2.sc;
    cin>> q2.fr>> q2.sc;
}

string prntans(bool val)
{
    return val? " " : " dont ";
}

int main()
{
    
    p1= {2, 0};
    p2= {1, 1};
    q1= {2, 2};
    q2= {0, 2};

    // input();

    cout<< "Given Segments" <<prntans(intersect())<< "intersect\n";
    
    cout<< "\nDefault input: {2,0}, {1,1}, {2,2}, {0,2}. uncomment the 66th line to allow custom inputs\n";
}