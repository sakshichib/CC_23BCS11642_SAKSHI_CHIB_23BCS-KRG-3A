#include <bits/stdc++.h>
using namespace std;

int max_score(vector<int> &tokens, int n, int power)
{
    sort(tokens.begin(), tokens.end());
    int score = 0;
    int newscore = 0;

    int i = 0;
    int j = n-1;

    while(i <= j)
    {
        if(power >= tokens[i])
        {
            score++;
            tokens[i] -= power;
            i++;
        }

        else if(score >= 1)
        {
            power += tokens[i];
            score--;
            j--;
        }

        else{
            break;
        }

        newscore = max(newscore, score);
    }

    return newscore;
}

int main()
{
    int n;
    cin>>n;
    vector<int> tokens(n);

    for(int i=0; i<n; i++)
    {
        cin>>tokens[i];
    }

    int power;
    cin >> power;

    cout<<max_score(tokens, n, power);
}