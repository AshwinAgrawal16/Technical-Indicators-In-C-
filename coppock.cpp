//COpPOCK INDICATOR(OSCILLATOR)

#include<bits/stdc++.h>
using namespace std;
vector<double> Coppock(vector<double> close,double T1,double T2,double T3)
{
	int i;
	vector<double> ROC1;
	vector<double> ROC2;
	vector<double> ROC;
	vector<double> WMA1;
	for(i=0;i<close.size()-(T1>T2?T2:T1);i++)
	{
		ROC1[i]=ROC(close,T1,i);    //FUNCTION TO CALCULATE THE RATE OF CHANGE OF PRICE
	}
	
	
	for(i=0;i<close.size()-(T1>T2?T2:T1);i++)
	{
		ROC2[i]=ROC(close,T2,i);
	}
	
	
	for(i=0;i<close.size()-(T1>T2?T2:T1);i++)
	{
		ROC[i]=ROC1[i]+ROC2[i];
	}
	
	
	for(i=0;i<close.size()-T3;i++)
	{
		WMA1[i]=WMA(ROC,T3,i);     //FUNCTION TO CALCULATE THE WEIGHTED MOVING AVERAGE OF PRICE(ROC)
	}
	//return ROC;
	return WMA1;
	
}

