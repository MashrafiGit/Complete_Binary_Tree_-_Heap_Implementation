#include <bits/stdc++.h>
using namespace std;

void insert_heap(vector<int> &v, int val)
{
    v.push_back(val);
    int cur_idx = v.size() - 1;

    while (cur_idx != 0)
    {
        int par_idx = (cur_idx - 1) / 2;
        if (v[par_idx] > v[cur_idx])
            swap(v[par_idx], v[cur_idx]);
        else
            break;

        cur_idx = par_idx;
    }
}

void print_heap(const vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

void delete_heap(vector<int> &v)
{
    if (v.empty())
        return;

    v[0] = v.back();
    v.pop_back();

    int cur_idx = 0;
    while (true)
    {
        int left_idx = cur_idx * 2 + 1;
        int right_idx = cur_idx * 2 + 2;

        int smallest = cur_idx;

        if (left_idx < v.size() && v[left_idx] < v[smallest])
            smallest = left_idx;
        if (right_idx < v.size() && v[right_idx] < v[smallest])
            smallest = right_idx;

        if (smallest == cur_idx)
            break;

        swap(v[cur_idx], v[smallest]);
        cur_idx = smallest;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert_heap(v, val);
    }

    print_heap(v);
    delete_heap(v);
    print_heap(v);

    return 0;
}
