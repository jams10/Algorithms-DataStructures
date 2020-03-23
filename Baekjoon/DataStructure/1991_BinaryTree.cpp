// #include <iostream>
// using namespace std;

// typedef struct TreeNode
// {
//   char data;
//   struct TreeNode *left=NULL;
//   struct TreeNode *right=NULL;
// }TreeNode;

// void preorder(const TreeNode *root)
// {
//   if(root)
//   {
//     cout<<root->data;
//     preorder(root->left);
//     preorder(root->right);
//   }
// }

// void inorder(const TreeNode *root)
// {
//   if(root)
//   {
//     inorder(root->left);
//     cout<<root->data;
//     inorder(root->right);
//   }
// }

// void postorder(const TreeNode *root)
// {
//   if(root)
//   {
//     postorder(root->left);
//     postorder(root->right);
//     cout<<root->data;
//   }
// }

// int main()
// {
//   int n=0;
//   char parent, left, right;
//   cin>>n;

//   TreeNode* tree = new TreeNode[n];

//   for(int i=0; i<n; ++i)
//   {
//     tree[i].data=char(i+65);
//   }
  
//   for(int i=0; i<n; ++i)
//   {
//     cin>>parent>>left>>right;
//     if(left!='.')
//     {
//       tree[int(parent)-65].left = &tree[int(left)-65];
//     }
//     if(right!='.')
//     {
//       tree[int(parent)-65].right = &tree[int(right)-65];
//     }
//   }

//   preorder(tree);
//   cout<<endl;
//   inorder(tree);
//   cout<<endl;
//   postorder(tree);

//   delete[] tree;
//   return 0;
// }