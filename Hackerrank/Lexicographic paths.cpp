#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long func(long long a, long long b)
{
    if(a<b)
        swap(a,b);
    long long f1=1,f2=1;
    for(long long i=0;i<b;i++)
        f1*=(a+b-i);
    for(long long i=b;i>0;i--)
        f2*=i;
    return f1/f2;
}
// Complete the solve function below.
string solve(int x, int y, int k) {
    stringstream ss;
    while(x>0)
    {
        long long rem=func(x-1,y);
        if(k>=rem)
        {
            k-=rem;
            ss<<"V";
            y--;
        }
        else{
            ss<<"H";
            x--;
        }
    }
    while(y--)
        ss<<"V";
    return ss.str();
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string xyk_temp;
        getline(cin, xyk_temp);

        vector<string> xyk = split_string(xyk_temp);

        int x = stoi(xyk[0]);

        int y = stoi(xyk[1]);

        int k = stoi(xyk[2]);

        string result = solve(x, y, k);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
