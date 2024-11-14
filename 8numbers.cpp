#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int q[8]={0},c=0,solution=0;
	int a[8][5]={{-1},
	             {0,-1},
	             {0,-1},
	             {0,1,2,-1},
	             {0,1,3,-1},
	             {1,4,-1},
	             {2,3,4,-1},
	             {3,4,5,6,-1}};
q[0]=1;
	nc:
		c++;
		if(c==8)goto print;
		q[c]=0;
	nr:	
		q[c]++;
		if(q[c]==9)goto backtrack;
	
		for(int i=0;i<c;i++){
			if(q[i]==q[c])goto nr;
		}
	 
		  for(int i=0;a[c][i]!=-1;i++){
			if(abs(q[c]-q[a[c][i]])==1)goto nr;
		}
		goto nc;
	backtrack:
		c--;
		if(c==-1)return 0;
		goto nr;
	print:
		solution++;
		cout<<"solution # "<<solution<<endl;
		for(int i=0;i<8;i++){
			cout<<q[i]<<" ";
		}
		cout<<endl<<endl;
		goto backtrack;
}
