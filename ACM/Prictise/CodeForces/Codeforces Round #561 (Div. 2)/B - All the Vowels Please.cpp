#include<bits/stdc++.h>
using namespace std;

char vowels[] = {'a','e','i','o','u'};
int k,x,y,t,j;
int main()
{
	cin >> k;
    if(k < 25) return cout << "-1" << endl, 0;

    for(int i = 5;i <= sqrt(k); i++)
    {
        if(!(k % i))
            if(k / i >= 5)
            {
                if(k/i == 5 || i==5)
                {
                    while(1)
                    {
                        int j = x;
                        for(y = 0;y < 5;y++)
                        {
                            cout << vowels[j++]; 
                            t++;
                            if(t == k) return 0;
                            if(j == 5) j = 0;
                        }
                        x++;
                        if(x == 5) x = 0;
                        // cout << " ";
                    }
                }
                else
                {
                     for(int j = 0,t = 0;t < k && j < 5;t++, j++)
                    {
                        cout << vowels[j];
                        if(j+1 == 5) j = -1;
                    }
                }
                
                    
                    return 0;
            }
    }

    return cout << "-1" << endl, 0;
}