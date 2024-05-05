#include <bits/stdc++.h>
using namespace std;
int main()
{
    int noOfprocesses, noOfresources;
    cout << "Enter the number of processes\n";
    cin >> noOfprocesses;
    cout << "Enter the number of resources\n";
    cin >> noOfresources;
    vector<vector<int>>allocation(noOfprocesses, vector<int>(noOfresources, -1));
    vector<vector<int>> maxNeed(noOfprocesses, vector<int>(noOfresources, -1));
    vector<vector<int>> remNeed(noOfprocesses, vector<int>(noOfresources, -1));
    vector<int> available(noOfresources, -1);
    vector<int> safeSeq;
    unordered_set<int> st;
    cout << "Enter the resource allocation matrix\n";
    for (int i = 0; i < noOfprocesses; i++)
    {
        for (int j = 0; j < noOfresources; j++)
        {
            cin >> allocation[i][j];
        }
    }
    cout << "Enter the Maximum need matrix\n";
    for (int i = 0; i < noOfprocesses; i++)
    {
        for (int j = 0; j < noOfresources; j++)
        {
            cin >> maxNeed[i][j];
        }
    }
    cout << "Enter the available resources\n";
    for (int i = 0; i < noOfresources; i++)
    {
        cin >> available[i];
    }
    // Remaining need calculation
    for (int i = 0; i < noOfprocesses; i++)
    {
        for (int j = 0; j < noOfresources; j++)
        {
            remNeed[i][j] = maxNeed[i][j] - allocation[i][j];
            cout << remNeed[i][j] << " ";
        }
        cout << "\n";
    }
    // Safe Sequence
    bool deadlock = false;
    while (st.size() != noOfprocesses && !deadlock)
    {
        deadlock = true;
        for (int i = 0; i < noOfprocesses; i++)
        {
            if (st.find(i) != st.end())
                continue;
            int canallocate = 0;
            for (int j = 0; j < noOfresources; j++)
            {
                if (available[j] >= remNeed[i][j])
                    canallocate++;
            }
            if (canallocate != noOfresources)
                continue;
            for (int k = 0; k < noOfresources; k++)
                available[k] +=
                    allocation[i][k];
            st.insert(i);
            safeSeq.push_back(i);
            deadlock = false;
        }
    }
    if (st.size() != noOfprocesses)
    {
        cout << "The system is in deadlock state\n";
    }
    else
    {
        cout << "Safe sequence is: ";
        for (auto it : safeSeq)
            cout << "P" << it << " ";
    }
    return 0;
}
