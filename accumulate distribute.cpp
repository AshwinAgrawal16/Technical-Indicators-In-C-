// ACCUMULATION AND DISTRIBUTION OSCILLATOR

vector<double> ADO(vector<double> close,vector<double> high,vector<double> low,vector<double> open,vector<double> volume)
{
	int i;
	vector<double> AD;
	for(i=0;i<close.size();i++)
	{
		AD[i]=((close[i]-open[i])/(high[i]-low[i]))*volume[i];
	}
	
	return AD;
	
}
