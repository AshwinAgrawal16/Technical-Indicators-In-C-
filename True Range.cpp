// TRUE RANGE

/* Function maximum definition */
/* x, y and z are parameters */
double maximum(double x, double y, double z) {
	int max = x; /* assume x is the largest */

	if (y > max) { /* if y is larger than max, assign y to max */
		max = y;
	} /* end if */

	if (z > max) { /* if z is larger than max, assign z to max */
		max = z;
	} /* end if */

	return max; /* max is the largest value */
} /* end function maximum */


vector<double>TR(vector<double> close,vector<double> high, vector<double> low)
{
	vector<double> tr;
	int i;
	for(i=0;i<close.size()-1;i++)
	{
		tr[i]=maximum(high[i]-low[i],high[i]-close[i-1],close[i-1]-low[i]);
	}
	return tr;
}
