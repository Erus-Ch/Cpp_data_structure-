//Return to the Depth of certain elements;
template <class KEY, class OTHER>
SET<KEY, OTHER> * BinarySearchTree<KEY, OTHER>::findDepth(const KEY &x ) const
{ 
	int n=0;
	return findDepth( x, root ); 
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::find(const KEY & x, BinaryNode *t ) const
{ 
	if ( t == NULL )
		cout<<"The element did not exist. "<<endl;
		return (SET<KEY, OTHER> *) t; 
	if( x < t->data.key ) 
		n=n+1;
		return findDepth( x, t->left );
	else if
		n=n+1;
		return findDepth( x, t->right );
	else
		cout<<"The depth is ",n<<endl;
		return (SET<KEY, OTHER> *) t;
}
