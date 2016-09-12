// CHAIKIN OSCILLATOR


double exponential(vector<double> price, double smoothingValue, int dataSetSize,int j)                //FUNCTION TO CALCULATE THE EXPONENTIAL MOVING AVERAGE
{
    int i;
    double cXAvg;
    cXAvg = price[ dataSetSize - 2 ] ;  

    for (i= dataSetSize - 2; i > -1+j; --i)   
        cXAvg += (smoothingValue * (price[ i ] - cXAvg)) ;

     return ( cXAvg) ;
}




vector<double> CHAIKIN(vector<double> close,vector<double> high,vector<double> low,vector<double> open,vector<double> volume)
{
	vector<double> EMA10;
	vector<double> EMA3;
	vector<double> Chaikin;
	int i;
	vector<double> AD;
	for(i=0;i<close.size();i++)
	{
		AD[i]=((close[i]-open[i])/(high[i]-low[i]))*volume[i];
	}
	
	for(i=0;i<close.size()-10;i++)                          //10 DAY EMA OF AD -FAST MOVING AVERAGE
	{
		EMA10[i]=exponential(AD,2/(10+1),i+10,i);         //SMOTHING FACTOR IS DEFAULT 2/(1+n)
	}
	for(i=0;i<close.size()-3;i++)                           //3 DAY EMA OF AD -SLOW MOVING AVERAGE
	{
		EMA3[i]=exponential(AD,2/(3+1),i+3,i);
	}
	
	for(i=0;i<close.size()-10;i++)                         
	{
		Chaikin[i]=EMA10[i]-EMA3[i];
		
	}
}
