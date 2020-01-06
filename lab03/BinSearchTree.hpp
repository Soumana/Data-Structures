//
// Created by Soumana Sylla on 10/8/19.
//

#ifndef LAB03_BINSEARCHTREE_HPP
#define LAB03_BINSEARCHTREE_HPP

#include "TreeNode.hpp"
#include <vector>
#include <queue>

class TreeNode;

class BinSearchTree {
public:
    void insert( int v );
    bool find( int v );
    bool iterFind( int v );
    int size();
    void inorderDump();
    int maxDepth();
    void levelOrderDump();
    bool remove( int v );
    int kthSmallest( int k );
    void valuesAtLevel( int k );
    void iterValuesAtLevel( int k );
    int iterMaxDepth();
    bool hasRootToLeafSum( int sum );
    bool areIdentical( BinSearchTree *bst );
    BinSearchTree *intersectWith( BinSearchTree *bst );
    BinSearchTree *unionWith( BinSearchTree *bst );
    BinSearchTree *differenceOf( BinSearchTree *bst );

private:
    TreeNode *local_insert( TreeNode *root, int v );
    bool findHelper( TreeNode *root, int v );
    int sizeHelper( TreeNode *root );
    void inorderDumpHelper( TreeNode *root );
    int maxDepthHelper( TreeNode *root );
    void valuesAtLevelHelper( TreeNode *root, int k );
    bool hasRootToLeafSumHelper( TreeNode* root, int sum );
    bool areIdenticalHelper( TreeNode *root, TreeNode *root2 );
    void intersectWithHelper( BinSearchTree *tree, TreeNode *root, TreeNode *root2 );
    void unionWithHelper( BinSearchTree *tree, TreeNode *root, TreeNode *root2 );
    void differenceOfHelper( BinSearchTree *tree, TreeNode *root, TreeNode *root2 );
    int kthSmallestHelper( TreeNode *root, int k );
    void removeHelper( int v, TreeNode *parent );
    void removeRootMatch();
    void removeMatch( TreeNode *parent, TreeNode *match, bool left );
    
    TreeNode *root;
    std::queue<TreeNode*> treeQue;
};

#endif //LAB03_BINSEARCHTREE_HPP
