//
// Created by Soumana Sylla on 10/8/19.
//

#include "BinSearchTree.hpp"
#include "TreeNode.hpp"
#include "iostream"

void BinSearchTree::insert(int v) {
    if(!find(v)) {
        root = local_insert(root, v);
    }
}

TreeNode *BinSearchTree::local_insert(TreeNode *root, int v) {
    if(root == nullptr) {
        return new TreeNode(v);
    }
    if( root->value() < v )
        root->rightSubtree( local_insert( root->rightSubtree(), v ) );
    else
        root->leftSubtree( local_insert( root->leftSubtree(), v ) );
    return root;
}

bool BinSearchTree::find(int v) {
    return findHelper(root, v);
}

bool BinSearchTree::findHelper(TreeNode *root, int v) {
    if(root == nullptr) {
        return false;
    }
    if(root->value() == v) {
        return true;
    }
    if(v > root->value()) {
        return findHelper(root->rightSubtree(), v);
    }
    return findHelper(root->leftSubtree(), v);
}

bool BinSearchTree::iterFind(int v) {
    TreeNode* rootCopy = root;

    while(rootCopy != nullptr) {
        if(rootCopy->value() == v) {
            return true;
        }
        if(v > rootCopy->value()) {
            rootCopy = rootCopy->rightSubtree();
        }
        else {
            rootCopy = rootCopy->leftSubtree();
        }
    }
    return false;
}

int BinSearchTree::size() {
    return sizeHelper(root);
}

int BinSearchTree::sizeHelper(TreeNode *root) {
    if(root == nullptr) {
        return 0;
    }
    return 1 + sizeHelper(root->leftSubtree()) + sizeHelper(root->rightSubtree());
}

void BinSearchTree::inorderDump() {
    inorderDumpHelper(root);
}

void BinSearchTree::inorderDumpHelper(TreeNode *root) {
    if(root == nullptr) {
        return;
    }

    inorderDumpHelper(root->leftSubtree());

    std::cout << root->value() << std::endl;

    inorderDumpHelper(root->rightSubtree());
}

int BinSearchTree::maxDepth() {
    return maxDepthHelper(root);
}

int BinSearchTree::maxDepthHelper(TreeNode *root) {
    if(root == nullptr) {
        return 0;
    }

    int left = maxDepthHelper(root->leftSubtree());

    int right = maxDepthHelper(root->rightSubtree());

    if(left > right)
        return 1 + left;
    return 1 + right;
}

void BinSearchTree::levelOrderDump() {
    if(root == nullptr) {
        return;
    }
    TreeNode* rootCopy = root;

    treeQue.push(rootCopy);

    while(!treeQue.empty()) {
        if(treeQue.front()->leftSubtree() != nullptr) {
            treeQue.push(treeQue.front()->leftSubtree());
        }
        if(treeQue.front()->rightSubtree() != nullptr) {
            treeQue.push(treeQue.front()->rightSubtree());
        }
        std::cout << treeQue.front()->value() << std::endl;
        treeQue.pop();
    }
}

int BinSearchTree::kthSmallest(int k) {
    if(k > sizeHelper(root) || k < 1) {
        return 0;
    }
    return kthSmallestHelper(root, k);
}

int BinSearchTree::kthSmallestHelper(TreeNode *root, int k) {
    if(k == sizeHelper(root->leftSubtree()) + 1) {
        return root->value();
    }
    if(k <= sizeHelper(root->leftSubtree())) {
        return kthSmallestHelper(root->leftSubtree(), k);
    }
    int size = sizeHelper(root->leftSubtree()) + 1;

    return kthSmallestHelper(root->rightSubtree(), k - size);
}

void BinSearchTree::valuesAtLevel(int k) {
    if(k < 1 || k > maxDepth()) {
        return;
    }
    valuesAtLevelHelper(root, k);
}

void BinSearchTree::valuesAtLevelHelper( TreeNode *root, int k) {
    if(k == 1) {
        std::cout << root->value() << std::endl;
        return;
    }
    if(root->leftSubtree() != nullptr) {
        valuesAtLevelHelper(root->leftSubtree(), k - 1);
    }
    if(root->rightSubtree() != nullptr) {
        valuesAtLevelHelper(root->rightSubtree(), k - 1);
    }
}

void BinSearchTree::iterValuesAtLevel(int k) {
    if(k < 1 || k > maxDepth()) {
        return;
    }

    std::vector<TreeNode*> valueslevel;
    valueslevel.push_back(root);
    int count = 1;

    while(!valueslevel.empty()) {
        if(k == count) {
            for(int i = 0; i < valueslevel.size(); i++) {
                std::cout << valueslevel[i]->value() << std::endl;
            }
            return;
        }
        int valueslevelSize = valueslevel.size();

        for(int i = 0; i < valueslevelSize; i++) {
            if(valueslevel[i]->leftSubtree() != nullptr) {
                valueslevel.push_back(valueslevel[i]->leftSubtree());
            }
            if(valueslevel[i]->rightSubtree() != nullptr) {
                valueslevel.push_back(valueslevel[i]->rightSubtree());
            }
        }
        valueslevel.erase(valueslevel.begin(), valueslevel.begin() + valueslevelSize);
        count++;
    }
}

int BinSearchTree::iterMaxDepth() {
    if(root == nullptr) {
        return 0;
    }

    std::vector<TreeNode*> valuesDepth;
    valuesDepth.push_back(root);
    int depthCount = 1;

    while(!valuesDepth.empty()) {
        int removeNumElements = valuesDepth.size();
        for(int i = 0; i < removeNumElements; i++) {
            if(valuesDepth[i]->leftSubtree() != nullptr) {
                valuesDepth.push_back(valuesDepth[i]->leftSubtree());
            }
            if(valuesDepth[i]->rightSubtree() != nullptr) {
                valuesDepth.push_back(valuesDepth[i]->rightSubtree());
            }
        }
        if(removeNumElements == valuesDepth.size()) {
            return depthCount;
        }
        depthCount++;
        valuesDepth.erase(valuesDepth.begin(), valuesDepth.begin() + removeNumElements);
    }
    return depthCount;
}

bool BinSearchTree::hasRootToLeafSum(int sum) {
    return hasRootToLeafSumHelper(root, sum);
}

bool BinSearchTree::hasRootToLeafSumHelper(TreeNode *root, int sum) {
    if(root == nullptr) {
        return false;
    }

    sum = sum - root->value();

    if(sum == 0 && root->leftSubtree() == nullptr && root->rightSubtree() == nullptr) {
        return true;
    }
    return hasRootToLeafSumHelper(root->leftSubtree(), sum) || hasRootToLeafSumHelper(root->rightSubtree(), sum);
}

bool BinSearchTree::areIdentical(BinSearchTree *bst) {
    return areIdenticalHelper(root, bst->root);

}

bool BinSearchTree::areIdenticalHelper(TreeNode *root, TreeNode *root2) {
    if(root == nullptr && root2 == nullptr) {
        return true;
    }
    if((root != nullptr && root2 == nullptr) || (root == nullptr && root2 != nullptr)) {
        return false;
    }
    if(root->value() == root2->value()) {
        return areIdenticalHelper(root->leftSubtree(), root2->leftSubtree())
               && areIdenticalHelper(root->rightSubtree(), root2->rightSubtree());
    }
    return false;
}

BinSearchTree *BinSearchTree::intersectWith(BinSearchTree *bst) {
    BinSearchTree *tree = new BinSearchTree();
    intersectWithHelper(tree, root, bst->root);
    return tree;
}

void BinSearchTree::intersectWithHelper(BinSearchTree *tree, TreeNode *root, TreeNode *root2) {
    if(root == nullptr && root2 == nullptr) {
        return;
    }
    if((root != nullptr && root2 == nullptr) || (root == nullptr && root2 != nullptr)) {
        return;
    }
    intersectWithHelper(tree, root->leftSubtree(), root2);

    if(findHelper(root2, root->value())) {
        tree->insert(root->value());
    }

    intersectWithHelper(tree, root->rightSubtree(), root2);
}

BinSearchTree *BinSearchTree::unionWith(BinSearchTree *bst) {
    BinSearchTree *tree = new BinSearchTree();
    unionWithHelper(tree, root, bst->root);
    return tree;
}

void BinSearchTree::unionWithHelper(BinSearchTree *tree, TreeNode *root, TreeNode *root2) {
    if(root == nullptr && root2 == nullptr) {
        return;
    }
    if(root != nullptr && root2 == nullptr) {
        unionWithHelper(tree, root->leftSubtree(), root2);
        tree->insert(root->value());
        unionWithHelper(tree, root->rightSubtree(), root2);
        return;
    }
    if(root == nullptr && root2 != nullptr) {
        unionWithHelper(tree, root, root2->leftSubtree());
        tree->insert(root2->value());
        unionWithHelper(tree, root, root2->rightSubtree());
        return;
    }
    unionWithHelper(tree, root->leftSubtree(), root2->leftSubtree());
    tree->insert(root->value());
    tree->insert(root2->value());
    unionWithHelper(tree, root->rightSubtree(), root2->rightSubtree());
}

BinSearchTree *BinSearchTree::differenceOf(BinSearchTree *bst) {
    BinSearchTree *tree = new BinSearchTree();
    differenceOfHelper(tree, root, bst->root);
    return tree;
}

void BinSearchTree::differenceOfHelper(BinSearchTree *tree, TreeNode *root, TreeNode *root2) {
    if(root2 == nullptr) {
        return;
    }
    differenceOfHelper(tree, root, root2->leftSubtree());
    if(!findHelper(root, root2->value())) {
        tree->insert(root2->value());
    }
    differenceOfHelper(tree, root, root2->rightSubtree());
}

bool BinSearchTree::remove(int v) {
    int initialSize = sizeHelper(root);
    removeHelper(v, root);
    int sizeAfter = sizeHelper(root);

    if(initialSize != sizeAfter) {
        return true;
    }
    return false;
}

void BinSearchTree::removeHelper(int v, TreeNode *parent) {
    if(root == nullptr) {
        return;
    }
    if(v == root->value()) {
        removeRootMatch();
    }
    else {
        if(v < parent->value() && parent->leftSubtree() != nullptr) {
            v == parent->leftSubtree()->value() ? removeMatch(parent, parent->leftSubtree(), true) :
            removeHelper(v, parent->leftSubtree());
        }
        else if(v > parent->value() && parent->rightSubtree() != nullptr) {
            v == parent->rightSubtree()->value() ? removeMatch(parent, parent->rightSubtree(), false) :
            removeHelper(v, parent->rightSubtree());
        }
        else {
            return;
        }
    }
}

void BinSearchTree::removeRootMatch() {
    TreeNode *delPtr = root;

    if(root->leftSubtree() == nullptr && root->rightSubtree() == nullptr) {
        root = nullptr;
        delete delPtr;
    }
    else if(root->leftSubtree() != nullptr && root->rightSubtree() == nullptr) {
        root = root->leftSubtree();
        delPtr->leftSubtree(nullptr);
        delete delPtr;
    }
    else if(root->leftSubtree() == nullptr && root->rightSubtree() != nullptr) {
        root = root->rightSubtree();
        delPtr->rightSubtree(nullptr);
        delete delPtr;
    }
    else {
        int smallestInRightSubTree = kthSmallestHelper(root->rightSubtree(), 1);
        removeHelper(smallestInRightSubTree, root);
        root->value() = smallestInRightSubTree;
    }
}

void BinSearchTree::removeMatch(TreeNode *parent, TreeNode *match, bool left) {
    if(match->leftSubtree() == nullptr && match->rightSubtree() == nullptr) {
        left ? parent->leftSubtree(nullptr) : parent->rightSubtree(nullptr);
        delete match;
    }
    else if(match->leftSubtree() != nullptr && match->rightSubtree() == nullptr) {
        left ? parent->leftSubtree(match->leftSubtree()) : parent->rightSubtree(match->leftSubtree());
        match->leftSubtree(nullptr);
        delete match;
    }
    else if(match->leftSubtree() == nullptr && match->rightSubtree() != nullptr) {
        left ? parent->leftSubtree(match->rightSubtree()) : parent->rightSubtree(match->rightSubtree());
        match->rightSubtree(nullptr);
        delete match;
    }
    else {
        int smallestInRightSubTree = kthSmallestHelper(match->rightSubtree(), 1);
        removeHelper(smallestInRightSubTree, match);
        match->value() = smallestInRightSubTree;
    }
}