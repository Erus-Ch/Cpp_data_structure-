template <class KEY, class OTHER)
int binarySearch(SET<KEY,OTHER>data[],int size,int high, int low,const KEY&x)
{
	int mid = (high+low)/2 ;
    if (sdata[mid] == key) 
    	eturn mid;
    if (low >= high) 
        return -1;
        cout<<"NULL"<<endl;
    else if (key > data[mid]) 
        return binarySearch(data[], mid+1, high, key);
    else if (key < data[mid]) 
    	return binarySearch(data[], low, mid-1, key);
	return -1;
}
