//DONCHIAN CHANNELS

vector<double> Donchian(vector<double> high,vector<double> low,double time)
{
	vector<double> maxh1;
	vector<double> minl1;
	vector<double> DON;
	int i;
	for(i=1;i<high.size()-time;i++)      //i=1 because the donchian channels takes max of high of past 20 dyas nad not including the current day
	{
		maxh1[i]=MAX(high,time,i);
	}
	for(i=1;i<high.size()-time;i++)     //i=1 because the donchian channels takes max of high of past 20 dyas nad not including the current day
	{
		minl1[i]=MIN(low,time,i);
	}
	
	
	for(i=1;i<MIN.size()-time;i++)
	{
		DON[i]=(maxh1[i]+minl1[i])/2;
	}
	
	return DON;
	
	
	/*double maxh=0;
	int i;
	for(i=1;i<=time;i++)  //i=1 because the donchian channels takes max of high of past 20 dyas nad not including the current day
	  if(high[i]>max)
		maxh=high[i];
	
	double minl=0;
	for(i=1;i<=time;i++)
	  if(low[i]>max)
		minl=low[i];*/
		
		
}
