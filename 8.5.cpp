template<class KEY, class OTHER>
int seqSearch(SET<KEY,OTHER>data[],int size, const KEY &x)
{
	data[0].key=x;
	for(int i=size; x!=data[i].key;--i);
	data[i].key=data[i+1].key;
	data[i+1].key=data[0].key;
	return i+1;
}
