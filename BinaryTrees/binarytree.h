#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
template <typename T> class BinaryTreeNode {
  T info;
  BinaryTreeNode<T> *llink;
  BinaryTreeNode<T> *rlink;
};

template <typename T> class BinaryTreeType {
public:
  const BinaryTreeType<T> &operator=(const BinaryTreeType<T> &otherTree) {
    if (this != &otherTree) {
      if (root != nullptr) // if it is there from before delete it
        destroy(root);
      if (otherTree.root == nullptr)
        root = nullptr;
      else
        copyTree(root, otherTree.root);
    }
    return *this;
  }

  bool isEmpty() const { return root == nullptr; }

  void inorderTraversal() const { inorder(root); }

  void preorderTraversal() const { preorder(root); }

  void postorderTraversal() const { postorder(root); }

  int treeHeight() const { height(root); }

  int treeNodeCount() const { nodecout(root); }

  int treeLeavesCount() const { leavesCount(root); }

  int destroyTree() { destroy(root); }

  BinaryTreeType() { root = nullptr; }

  BinaryTreeType(const BinaryTreeType<T> &otherTree) {
    if (otherTree.root == nullptr)
      root = nullptr;
    else
      copyTree(root, otherTree.root);
  }

  ~BinaryTreeType() { destroy(root); }

protected:
  BinaryTreeNode<T> *root;

private:
  void copyTree(BinaryTreeNode<T> &copiedTreeRoot,
                BinaryTreeType<T> &otherTreeRoot) {
    if (otherTreeRoot == nullptr)
      copiedTreeRoot = nullptr;
    else {
      copiedTreeRoot = new BinaryTreeNode<T>;
      copiedTreeRoot->info = otherTreeRoot->info;
      // easy method
      // tree is all about recursion isn't it
      copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
      copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
  }

  void destroy(BinaryTreeNode<T> *&p) {
    if (p != nullptr) {
      destroy(p->llink);
      destroy(p->rlink);
      delete p;
      p = nullptr;
    }
  }

  void inorder(BinaryTreeNode<T> *p) const {
    if (p != nullptr) {
      inorder(p->llink);
      std::cout << p->info << " ";
      inorder(p->rlink);
    }
  }

  void preorder(BinaryTreeNode<T> *p) const {
    std::cout << p->info << " ";
    preorder(p->llink);
    preorder(p->rlink);
  }

  void postorder(BinaryTreeNode<T> *p) const {
    postorder(p->llink);
    postorder(p->rlink);
    std::cout << p->info << " ";
  }

  int height(BinaryTreeNode<T> *p) const {
    if (p == nullptr)
      return 0;
    else
      return 1 + max(height(p->llink), height(p->rlink));
  }

  int max(int x, int y) const {
    if (x >= y)
      return x;
    else
      return y;
  }

  int nodeCount(BinaryTreeNode<T> *p) const;

  int leavesCount(BinaryTreeNode<T> *p) const;
};

#endif // !BINARYTREE_H
