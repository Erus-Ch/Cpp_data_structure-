template<class T>
bool binaryTree<T>::symmetric(const binaryTree<T> *t1, const binaryTree<T> *t2)
{
	if (t1 == nullptr && t2 == nullptr) 
		return true;
	if (t1 == nullptr || t2 == nullptr) 
		return false;
	if (t1->data != t2->data) 
		return false;
	return symmetric(t1->left, t2->right) && symmetric(t1->right, t2->left);
//	Recursive Realization
}

