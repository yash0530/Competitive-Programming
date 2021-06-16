#include <iostream>
using namespace std;
int find_max_index(int left, int right, int* A)
{
    if((right - left) < 1)
    {
        return left;
    }
    else
    {
        int mid = (left + right)/2;
        if(A[mid] <= A[mid + 1])
        {
            return find_max_index(mid+1,right,A);
        }
        else
        {
            return find_max_index(left,mid,A);
        }
        
    }
}
int main ()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int marks[N];
        for(int i = 0; i < N; i++)
        {
            cin>>marks[i];
        }
        int freq[101];
        for(int i=0;i<101;i++)freq[i]=0;
        for(int j = 0; j < N; j++)
        {
            freq[marks[j]]++;
        }
        int r = 0;
        for(int k = 0; k < 101; k++)
        {
            if(freq[k] != 0)
            {
                r++;
            }
        }
        int real_freq[r], h = 0;
        for(int i=0;i<r;i++)real_freq[i]=0;
        for(int y = 0; y < 101; y++)
        {
            if(freq[y] != 0)
            {
                real_freq[h] = freq[y];
	            h++;
            }
        }
        for(int p = 0; p < r; p++)
        {
            cout<<real_freq[p]<<" ";
        }
        cout<<"\n";
        int ans = find_max_index(0,r-1,real_freq);
        cout<<real_freq[ans]<<endl;
    }
    return 0;
}