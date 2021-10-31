#include<bits/stdc++.h>
using namespace std;
//This is one base indexing
//Array should be on n+1 size and 1 based indexed
//Query of type l->r both l and r inclusive
struct segmenttree {
    int size;
    vector<int> value;
    void intit(int n)
    {
        size = 1;
        while (size < n)size *= 2;

        value.assign(2 * size, INT_MAX);
    }

    void build(vector<int> & ar, int x, int lx, int rx)
    {
        if (rx == lx)
        {
            if (lx < (int)ar.size())
                value[x] = ar[lx];

            return;
        }

        int m = (lx + rx) / 2;
        build(ar, 2 * x , lx, m);
        build(ar, 2 * x + 1, m + 1, rx);
        value[x] = min(value[2 * x] , value[2 * x + 1]);
    }
    void build(vector<int> & ar)
    {
        build(ar, 1, 1, size);
    }

    void set(int i, int v, int x, int lx, int rx)
    {
        if (rx == lx)
        {
            value[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i <= m)
        {
            set(i, v, 2 * x, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 1, m + 1, rx);
        }

        value[x] = min(value[2 * x] , value[2 * x + 1]);
    }
    void set(int i, int v)
    {
        set(i, v, 1, 1, size);
    }

    int mini(int l, int r, int x, int lx, int rx)
    {
        if (l > rx || r < lx)
            return INT_MAX;

        if (lx >= l &&  rx <= r)
            return value[x];

        int m = (lx + rx) / 2;
        int s1 = mini(l, r, 2 * x, lx, m);
        int s2 = mini(l, r, 2 * x + 1, m + 1, rx);

        return min(s1, s2);
    }
    int mini(int l, int r)
    {
        return mini(l, r, 1, 1, size);
    }

    void show()
    {
        for (int i = 1; i < 2 * size; i++)
            cout << value[i] << " ";
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    //initialize empty segment tree st.intit(n);

    //build segment tree st.build(ar);

    //set value at poition index i to v st.set(i,v);

    //st.show display the segment tree

    return 0;
}