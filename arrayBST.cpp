//converted sorted array to BST
// Time complexity = O(n)

class node* sortedArrayBST(int a[], int s, int e)
{
  if(s > e)
    return NULL;
  int mid = s + (e - s)/2;
  //create BST with root of mid
  node *root = new node(a[mid]);
  
  //start recursion
  root->left = sortedArrayBST(a, s, mid - 1);
  root->right = sortedArrayBST(a, mid + 1; e);
  return root;
}


//how to judge a tree is balanced binary tree
bool balance(TreeNode* root, TreeNode* leftp, TreeNode* rightp)
{
  if(root == NULL)
    return true;
   
  int left = depth(root->leftp);
  int right = depth(root->rightp);
  int diff = left - right;
  if(diff > 1 || diff < -1)
  {
    return false;
  }
  return balance(root->leftp) && balance(root->rightp);
}


