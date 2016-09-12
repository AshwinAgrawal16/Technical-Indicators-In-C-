//  SMOTHED 


double exponential(vector<double> price, double smoothingValue, int dataSetSize,int j)                //FUNCTION TO CALCULATE THE EXPONENTIAL MOVING AVERAGE
{
    int i;
    double cXAvg;
    cXAvg = price[ dataSetSize - 2 ] ;  

    for (i= dataSetSize - 2; i > -1+j; --i)   
        cXAvg += (smoothingValue * (price[ i ] - cXAvg)) ;

     return ( cXAvg) ;
}


vector<double> SROC(vector<double> close,int n,int m)
{
	int i;
	vector<double> ROC;
	vector<double> EMA13;
	for(i=0;i<close.size()-n;i++)
	{
		EMA13[i]=exponential(close,2/(1+n),i+n,i);
	}
	for(i=0;i<EMA13.size()-m;i++)
	{
		ROC[i]=(EMA13[i]-EMA13[i+m])/EMA13[i+m];
	}
	return ROC;
	
}
