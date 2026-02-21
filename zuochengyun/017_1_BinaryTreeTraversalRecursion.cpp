#include <iostream>
using namespace std;

struct TreeNode
{
    int val;         // 节点值
    TreeNode *left;  // 左子节点指针
    TreeNode *right; // 右子节点指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void preOrder(TreeNode *head);
void inOrder(TreeNode *head);
void postOrder(TreeNode *head);
int main()
{
    /* 初始化二叉树 */
    // 初始化节点
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n7 = new TreeNode(7);
    // 构建节点之间的引用（指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    preOrder(n1);
    cout << '\n';
    inOrder(n1);
    cout << '\n';
    postOrder(n1);

}

void preOrder(TreeNode *head)
{
    if(head == NULL) return;
    
    cout << head->val;
    // 第1次来
    preOrder(head->left);
    // 第2次来
    preOrder(head->right);
    // 第3次来
}

void inOrder(TreeNode *head)
{
    if(head == NULL) return;

    // 第1次来
    inOrder(head->left);
    cout << head->val;
    // 第2次来
    inOrder(head->right);
    // 第3次来
}

void postOrder(TreeNode *head)
{
    if(head == NULL) return;

    // 第1次来
    postOrder(head->left);
    // 第2次来
    postOrder(head->right);
    cout << head->val;
    // 第3次来
}