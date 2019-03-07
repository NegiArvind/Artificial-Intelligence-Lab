#include<bits/stdc++.h>
using namespace std;
#define n 4
bool manPreferedOverAlreadyEngagedman(int a[2*n][n],int women,int man,int man1)
{
	for(int i=0;i<n;i++)
	{
		if(a[women][i]==man1)
			return true;

		if(a[women][i]==man)
			return false;
	}
}
void calculate_marriage_pair(int a[2*n][n])
{
	cout<<"hello";
	int womenPartner[n];
	int manFree[n],m;

	memset(womenPartner,-1,sizeof(womenPartner));
	memset(manFree,true,sizeof(manFree));

	int freeCount=n;
	while(freeCount>0)
	{
		int man;
		for(man=0;man<n;man++)
			if(manFree[man])
				break;

		for(int i=0;i<n && manFree[i]==true;i++)
		{
			int women=a[man][i];
			cout<<"womenpartner"<<womenPartner[women-n]<<" "<<women-n;
			if(womenPartner[women-n]==-1)
			{
				womenPartner[women-n]=man;
				manFree[man]=false;
				freeCount--;
			}
			else
			{
				int already_engaged_man=womenPartner[women-n];
				if(manPreferedOverAlreadyEngagedman(a,women,man,already_engaged_man))
				{
					womenPartner[women-n]=man;
					manFree[already_engaged_man]=true;
					manFree[man]=false;
				}
			}
		}
		// cout<<freeCount<<"\n";
	}
	cout << "Woman   Man" << endl; 
    for (int i=0;i<n;i++) 
       cout<<" "<<i+n<<"\t"<< womenPartner[i]<<"\n"; 
}
int main()
{
	int i,j;
	cout<<"Enter man and women preference\n";
	int a[2*n][n];
	for(i=0;i<2*n;i++)
		for(j=0;j<n;j++)
			// cout<<"hello\n";
			cin>>a[i][j];


	for(i=0;i<2*n;i++)
		for(j=0;j<n;j++)
			// cout<<"hello\n";
			cout<<a[i][j]<<" ";
		cout<<"\n";
	cout<<"pair\n";
	calculate_marriage_pair(a);
}