// Using original remove function as basis;
template <class KEY, class OTHER>
void BinarySearchTree<KEY,OTHER>::remove( const KEY & x )
{
	remove( x, root );
}
template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove( const KEY & x, BinaryNode * & t )
{
	if( t == NULL ) return;
	if ( x < t->data.key ) remove( x, t->left );
	else if( t->data.key < x ) remove( x, t->right );
	else if( t->left != NULL && t->right != NULL ) 
	{
		BinaryNode *tmp = t->right; 
		while (tmp->left != NULL) tmp = tmp->left;
		t->data = tmp->data;
		remove( t->data.key, t->right );
	}
	else 
	{ 
		BinaryNode *oldNode = t;
		t = ( t->left != NULL ) ? t->left : t->right; 
		delete oldNode; 
	}
}

// With the help of recursion;
// Delete elements greater than certain value x; 
template <class KEY, class OTHER>
void BinarySearchTree<KEY,OTHER>::removeUpper( const KEY & x )
{
	removeUpper( x, root );
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::removeUpper( const KEY & x, BinaryNode * & t )
{
	if( t == NULL ) return;
	if ( x >= t->data.key ) 
		removeUpper( x, t->right );
	else if( t->data.key > x ) 
	{
		if( t->left != NULL && t->right != NULL ) 
			BinaryNode *tmp = t->right; 
			while (tmp->left != NULL) 
				tmp = tmp->left; 
			t->data = tmp->data;
			remove( t->data.key, t->right );
		else  
			BinaryNode *oldNode = t;
			t = ( t->left != NULL ) ? t->left : t->right; 
			delete oldNode; 
		removeUpper( x, t->right );
		removeUpper( x, t->left  );	
	}
		
}

// Delete elements less than certain value x;
template <class KEY, class OTHER>
void BinarySearchTree<KEY,OTHER>::removeDown( const KEY & x )
{
	removeUpper( x, root );
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::removeDown( const KEY & x, BinaryNode * & t )
{
	if( t == NULL ) return;
	if ( x <= t->data.key ) 
		removeDown( x, t->left );
	else if( t->data.key < x ) 
	{
		if( t->left != NULL && t->right != NULL ) 
			BinaryNode *tmp = t->right; 
			while (tmp->left != NULL) 
				tmp = tmp->left; 
			t->data = tmp->data;
			remove( t->data.key, t->right );
		else
			BinaryNode *oldNode = t;
			t = ( t->left != NULL ) ? t->left : t->right; 
			delete oldNode; 
		removeDown( x, t->right );
		removeDown( x, t->left  );	
	}
}

// Delete elements in a range (x,y);

template <class KEY, class OTHER>
void BinarySearchTree<KEY,OTHER>::removeRange( const KEY & x, const KEY & y )
{
	removeUpper( x, y, root );
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::removeRange( const KEY & x, const KEY & y, BinaryNode * & t )
{
	if( t == NULL ) return;
	if ( y <= t->data.key ) 
		removerRange( x, y, t->left );
	else if ( x >= t->data.key ) 
		removeRange( x, y, t->right );
	else
	{
		if( t->left != NULL && t->right != NULL ) 
			BinaryNode *tmp = t->right; 
			while (tmp->left != NULL) 
				tmp = tmp->left; 
			t->data = tmp->data;
			remove( t->data.key, t->right );
		else
			BinaryNode *oldNode = t;
			t = ( t->left != NULL ) ? t->left : t->right; 
			delete oldNode; 
		removeRange( x, y, t->right );
		removeRange( x, y, t->left  );	
	}
}
