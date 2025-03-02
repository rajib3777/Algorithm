#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin >> t;

    while(t--)
    {
        cin >> n;
        vector<int> height(n);
        for(int i = 0;i < n;i++)
            cin >> height[i] ;

        int left = 0;
        int right = height.size() - 1;
        int area= 0;
        pair<int,int> r = {left,right};

        while(left < right)
        {
            int h = min(height[left],height[right]);
            if(h > area)
            {
                area = h;
                r = {left,right};
            }

            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        cout << r.first << " " << r.second << endl;
    }

    return 0;
}