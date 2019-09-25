#include <iostream>
#include <vector>

typedef long long ll;

ll code(std::vector<int> a,int n)
{
//	sort(a.begin(),a.end());
	int cur = 0;
	int m = a.size();

	ll res =0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i] == cur+1)
		{
			res++;
			cur = a[i];
			continue;
		}
		else
		{
			res++;
			int number_of_greater_nums = n - a[i];
			for(int j = a[i]-1,increment=1;j>cur;j--,increment++)
				res += 1LL << (number_of_greater_nums+increment);
			cur = a[i];
		}
	}
	return res;
}

int 	main()
{
	int arr[] = { 1, 15, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 2, 0 };
	int n = 16;

	std::vector<int> vect(arr, arr + n); 
	
 	dprintf(2, "%lld\n", code(vect, n));
	return 0; 
}
