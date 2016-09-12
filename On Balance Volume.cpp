// ON BALANCE VOULME INDICATOR
vector<double> OBV(vector<double> close, vector<double> volume,int n)
{
	int i;
	vector<double> obv;
	for(i=0;i<close.size()-n;i++)
	{
		if(close[i]>=max_element(close+1+i,close+1+i+n))
		{
			obv[i]=close[i]+volume[i];
		}
		else
		obv[i]=close[i]-volume[i];
	}
	return obv;
}
