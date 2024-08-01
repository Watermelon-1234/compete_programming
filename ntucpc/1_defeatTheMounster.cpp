#include<bits/stdc++.h>

using namespace std;

string input,testment;
priority_queue <string,vector<string>,greater<string>> pq;
int main()
{
	cin>>input>>testment;
	for(int i = 0; i<testment.length()-input.length()+1; i++)
	{
		int wronged = 0;	
		for(int k=0;k<input.length();k++)
		{
			if(testment[i+k]!=input[k])
			{
				if(wronged)
				{
					wronged++;
					break;
				}
				else
					wronged++;
			}
		}
		if(wronged==2)
			continue;
		pq.push(testment.substr(i,input.length()));
	}
	if(pq.empty())
	{
		printf("Not found");
		return 0;
	}
	while(!pq.empty())
	{
		printf("%s\n",pq.top().c_str());
		// cout<<pq.top();
		// print("");
		pq.pop();
	}
}
