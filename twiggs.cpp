//TWIGGS MONEY FLOW FORMULA




double MA_Simple(int period, int ii,vector<double> price) {
    
        //stp.Start();
        decimal summ = 0;
        for (int i = ii; i > ii - period; i--) {
            summ = summ + price[i];
        }
        summ = summ / period;
        return summ;
        //stp.Stop();
        //if (ii == 1500) System.Windows.Forms.MessageBox.Show((stp.ElapsedTicks * 1000.0) / Stopwatch.Frequency + " ms");
       // return summ;
    } //else return -1;


vector<double> twiggs(vector<double> close,vector<double> high,vector<double> low,vector<double> volume)
{
	int i;
	vector<double> TRH;
	vector<double> TRL;
	vector<double> AD;
	vector<double> TWIGGS;
	for(i=0;i<close.size()-1;i++)
	{
		
		TRH[i]=max(high[i],close[i-1]);
		
	}
	for(i=0;i<close.size()-1;i++)
	{
		
		TRL[i]=min(low[i],close[i-1]);
		
	}
	for(i=0;i<close.size()-1;i++)
	{
		
		AD[i]=(((close[i]-TRL[i])-(TRH[i]-close[i]))/(TRH[i]-TRL[i]))*volume[i];
		
	}
	for(i=0;i<AD.size()-21;i++)
	{
		TWIGGS[i]=MA_Simple(21,i,AD);
	}
	return TWIGGS;
}

