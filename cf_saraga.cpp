// #include <bits/stdc++.h>
// using namespace std;

// bool check(string &str, string &s, string &t, int i)
// {
//     int st = 1, end = str.size()-1;
//     while(st<i and st != end){
//         string s1= str.substr(st, str.size()-st);
//         string s2 = t.substr(str.size()-st);
//         if(s1 == s2){
//             return true;
//         }else{
//             st++;
//         }
//     }
//     return false;
// }

// int main()
// {
//     string s, t;
//     cin >> s >> t;
//     int i = 0;
//     int j = t.length() - 1;
//     while (i < s.length() and j >= 0)
//     {
//         if (j+1 < t.length()-1 and s[i] == t[j])
//         {   string str = s.substr(0, s.length() - i) + t.substr(j+1);
//             if (check(str,s,t,i))
//             {
//                 cout << str<<"\n";
//                 break;
//             }else{
//                 j--;
//             }
//         }
//         else
//         {
//             j--;
//         }
//         if (j == 0)
//         {
//             i++;
//             j = t.size() - 1;
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

bool check_combination(string s, string t) {
    int n = s.size(), m = t.size();

    for (int i = 0; i <= n; ++i) { // prefix length from s
        for (int j = 0; j <= m; ++j) { // suffix length from t
            string prefix = s.substr(0, i);
            string suffix = t.substr(m - j, j);
            string combined = prefix + suffix;
            if (t.find(combined) != string::npos) {
                cout << "Matching substring: " << combined << "\n";
                return true;
            }
        }
    }

    return false;
}

int main() {
    string s, t;
    cin >> s >> t;

    if (!check_combination(s, t)) {
        cout << "No match found\n";
    }

    return 0;
}
