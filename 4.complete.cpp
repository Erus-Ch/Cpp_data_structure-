template<class T>
bool Complete(binaryTree<T>::Node *t)
{
	if(t == null) return true;
    queue<Node *> queue;
    queue.push(t);
    while (!queue.empty()){
	{
		Node* cur=queue.front();
        queue.pop();
		if(cur==null)
		{
			break;
		}
		else{
			queue.push(cur->left);
			queue.push(cur->right);
		}
	}
    while (!queue.empty()){
	{
		Node* cur=queue.front();
        queue.pop();
		if(cur!=null)  
			return false;
	}
	return true;
}

