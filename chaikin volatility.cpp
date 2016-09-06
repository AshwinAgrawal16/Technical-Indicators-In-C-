// CHAIKIN VOLATILITY INDEX

double exponential(vector<double> price, double smoothingValue, int dataSetSize,int j)                //FUNCTION TO CALCULATE THE EXPONENTIAL MOVING AVERAGE
{
    int i;
    double cXAvg;
    cXAvg = price[ dataSetSize - 2 ] ;  

    for (i= dataSetSize - 2; i > -1+j; --i)   
        cXAvg += (smoothingValue * (price[ i ] - cXAvg)) ;

     return ( cXAvg) ;
}



vector<double> ChaikinVolatility(vector<double> high,vector<double> low)
{
	vector<double> Diff;
	vector<double> EMA10;
	vector<double> volatility;
	int i;
	
	for(i=0;i<high.size();i++)
	{
		Diff[i]=high[i]-low[i];
	}
    
	for(i=0;i<Diff.size()-10;i++)
	{
		EMA10[i]=exponential(Diff,2/(1+(i+10)),i+10,i);
	}	
	
	int j=10;                                       //DEFAULT VALUE OF CHAIKIN VOLATILITY OF SECOND MOVING AVERAGE
	
	for(i=0;i<Diff.size()-20;i++)
	{
		EMA20[i]=exponential(Diff,2/(1+(i+10)+j),i+10+j,j);
	}
	
	for(i=0;i<EMA20.size();i++)
	{
		volatility[i]=((EMA10[i]-EMA20[i])/EMA20[i])*100;
	}
	
	return volatility;
}
