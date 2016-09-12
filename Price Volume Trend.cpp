// PRICE VOLUME TREND

vector<double> PVT(vector<double> close, vector<double> volume)
{
	vector<double> pvt
	int i;
	for(i=close.size()-1;i>-1;i--)
	{
	    pvt[i]=((close[i]-close[i+1])/close[i+1])*volume[i]+pvt[i+1];
	}
	return pvt;
}
