#include<bits/stdc++.h>
using namespace std;
vector<double> ultimate(vector<double> close,vector<double> low,vector<double> high )
{
	//double TL[10000];
	//double TH[10000];
	vector<double>TR;
	vector<double>BP;
	int i;
	for(i=0;i<close.size()-1;i++)
	{
	//	TL[i]=min(low[i],close[i+1]);
	//	TH[i]=max(high[i],close[i+1]);
		TR.push_back(max(high[i],close[i+1])-min(low[i],close[i+1]));
		BP.push_back(close[i]-min(low[i],close[i+1]));
	}
	//compute(TR,BP);
	vector<double> AVG7;
	vector<double> AVG14;
	vector<double> AVG28;
	vector<double> UO;
	//int i;
	for(i=0;i<TR.size()-28;i++)
	{
		AVG7.push_back(BP[i]+BP[i+1]);  //sum(BP+i,BP+i+7)/sum(TR+i,TR+i+7);
		AVG14.push_back(BP[i]+BP[i+1]+BP[i+2]+BP[i+3]);  //sum(BP+i,BP+i+14)/sum(TR+i,TR+i+14);
		AVG28.push_back(BP[i]+BP[i+1]+BP[i+2]+BP[i+3]+BP[i+4]+BP[i+5]+BP[i+6]+BP[i+7]);  //sum(BP+i,BP+i+28)/sum(TR+i,TR+i+28);
		UO.push_back((AVG7[i]+AVG14[i]*2+AVG28[i]*4)/(1+2+4));     //ARRAY OF STOCK WEIGHTS 
	}
	

	return UO;
}

	vector<double> close;
	vector<double> low;
	vector<double> high;
int main()
{

	for(int i=1;i<100;i++)
	{
	
	
	close.push_back(100+i);
	high.push_back(100-pow(-1,i)*0.1*i);
	low.push_back(100-0.2*i);
}
	vector<double> ult=ultimate(close,low,high);
	
		for(int j=0;j<10;j++)
	{
		cout<<ult[j]<<endl;
	}
	
}


/*double compute(array<double> TR,array<double> BP)
{
	array<double> AVG7;
	array<double> AVG14;
	array<double> AVG28;
	array<double> UO;
	int i;
	for(i=TR.begin();<i<TR.end()-28;i++)
	{
		AVG7[i]=sum(BP+i,BP+i+7)/sum(TP+i,TP+i+7);
		AVG14[i]=sum(BP+i,BP+i+14)/sum(TP+i,TP+i+14);
		AVG28[i]=sum(BP+i,BP+i+28)/sum(TP+i,TP+i+28);
		UO[i]=(AVG7[i]+AVG14[i]*2+AVG28[i]*4)/(1+2+4);
	}
	
}*/
