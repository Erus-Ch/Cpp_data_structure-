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

class binaryTree
{
    public:
        binaryTree();
        ~binaryTree();
 
        void insert(int key);
        node *search(int key);
        void destroy_tree();
 
    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
         
        node *root;
};

binaryTree::binaryTree()
{
  root=NULL;
}

void binaryTree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void binaryTree::insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

node *binaryTree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->key_value)
      return leaf;
    if(key<leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

void btree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->key_value=key;
    root->left=NULL;
    root->right=NULL;
  }
}
