// #include <bits/stdc++.h>//???DE?????bug

// using namespace std;

// int t,n,c,d;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin>>t;
//     while(t--)
//     {
//         cin>>n>>c>>d;
//         vector<int> a(n*n);
//         vector<int> b(n*n);
//         for(int i=0; i<n*n; i++)
//         {
//             cin>>a[i];
//         }
//         for(int i=0;i<n;++i)
//         {
//             for(int j=0;j<n;++j)
//             {
//                 b.emplace_back(a[0]+i*c+j*d);
//             }
//         }
//         sort(a.begin(),a.end());
//         sort(b.begin(),b.end());
//         for(int i=0;i<n*n;++i)
//         {
//             if(a[i]!=b[i])
//             {
//                 cout<<"No\n";
//                 break;
//             }
//             else if(i==n*n-1)
//             {
//                 cout<<"Yes\n";
//             }
//         }
//     }
// }
//?????
// #include <bits/stdc++.h>
// #define int int64_t
// using namespace std;
// signed main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n,c,d;
//         cin >> n >> c >> d;
//         vector<int> a(n*n),b;
//         for(int i=0;i<n*n;++i)
//             cin >> a[i];
//         for(int i=0;i<n;++i)
//         {
//             for(int j=0;j<n;++j)
//             {
//                 b.emplace_back(c*i+d*j);
//             }
//         }
//         sort(a.begin(),a.end());
//         sort(b.begin(),b.end());
//         for(int i=0;i<n*n;++i)
//         {
//             if(b[i]-a[i]!=b[0]-a[0])
//             {
//                 cout << "No\n";
//                 break;
//             }
//             else if(i==n*n-1)
//             {
//                 cout << "Yes\n";
//             }
//         }
//     }
// }