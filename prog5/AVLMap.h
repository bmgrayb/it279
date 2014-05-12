/*
 *Programmer: Brandon Graybeal
 *ULID: bmgrayb
 *Date: 4/10/14
 */

#ifndef _AVLMAP_H_
#define _AVLMAP_H_

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "MapInterface.h"
using namespace std;

template<class S, class T>
  class AVLMap: public MapInterface<S,T>
 {

  class TreeNode
  {
  public:
    TreeNode *leftChild;
    TreeNode *rightChild;
    T value;
    S key;
    int height;
    
    TreeNode(T val, S k)
    {
      value = val;
      key = k;
      height = 0;
      leftChild = NULL;
      rightChild = NULL;
    }
    
    ~TreeNode()
    {
    }

  };

  ///////////////////////////////////////////////////////////
  //Private methods for AVL map
 private:
  TreeNode *root;
  
  int getHeight(TreeNode *node)const
  {
    if(node == NULL)
      return -1;
    else
      return node->height;
  }
  

  //This method recursively adds an element to the tree
  TreeNode* insert(TreeNode *node, T value, S key)    
  {
    if(node == NULL)
      node = new TreeNode(value, key);
    else
    {
      if(key < node->key)
      {
	  node->leftChild = insert(node->leftChild, value, key);
      }
      else if(key > node->key)
      {
	  node->rightChild = insert(node->rightChild, value, key);
      }
      else
      {
	  node->value = value;
      }
    }

    return node;
  }
  
  

  
  /*
  //This method recursively inserts into the tree, and balances it
  TreeNode* insert(TreeNode *node, T value, S key)
  {
    cout << "first " << key << endl;
    if(node == NULL)
    {
      node = new TreeNode(value, key);
    }
    else if(key < node->key)
    {
      insert(node->leftChild, value, key);
      if(getHeight(node->leftChild) - getHeight(node->rightChild) == 2)
      {
	if(key < node->leftChild->key)
	  rotateLeftChild(node);
	else
	  doubleLeftChild(node);
      }
    }
    else if(node->key < key)
    {
      insert(node->rightChild,value, key);
      if(getHeight(node->rightChild) - getHeight(node->leftChild) == 2)
      {
	if(node->rightChild->key < key)
	  rotateRightChild(node);
	else
	  doubleRightChild(node);
      }
    }
    else
      ;

    cout << "second " << key << endl;
    node->height = max(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
    return node;

  }

  */
  
  //This method adds an element to a tree
  void insert(T value, S key)
  {
    root = insert(root, value, key); 
  }


  //This method recursively searches the tree for a node with the given key
  TreeNode* searchTree(TreeNode *node, S key)
  {
    TreeNode *foundNode = NULL;

    if(node != NULL)
    {
      if(node->key == key)
	foundNode = node;
      else if(key < node->key)
	foundNode = searchTree(node->leftChild, key);
      else if(key > node->key)
	foundNode = searchTree(node->rightChild, key);
    }

    return foundNode;
  }


  //This method recursively deletes every node
  void deleteTree(TreeNode *node)
  {
    if(node != NULL)
    {
      deleteNode(node->leftChild);
      deleteNode(node->rightChild);
      
      delete node;
    }
  }

  //This method creates a vector of nodes 
  void getNodes(TreeNode *node, vector<TreeNode*> *nodeList)
  {
    if(node != NULL)
    {
      getNodes(node->leftChild, nodeList);
      nodeList->push_back(node);
      getNodes(node->rightChild, nodeList);
    }
  }

  //this method rotates the left child
  void rotateLeftChild(TreeNode *&k2)
  {
    TreeNode *k1 = k2->leftChild;
    k2->leftChild = k1->rightChild;
    k1->rightChild = k2;
    k2->height = max(getHeight(k2->leftChild), getHeight(k2->rightChild)) + 1;
    k1->height = max(getHeight(k1->leftChild), getHeight(k2)) + 1;
    k2 = k1;
    
  }

  //this method rotates the right child
  void rotateRightChild(TreeNode *&k2)
  {
    TreeNode *k1 = k2->rightChild;
    k2->rightChild = k1->leftChild;
    k1->leftChild = k2;
    k2->height = max(getHeight(k2->rightChild), getHeight(k2->leftChild)) + 1;
    k1->height = max(getHeight(k1->rightChild), getHeight(k2)) + 1;
    k2 = k1;
  }

  //this method double rotates the left child
  void doubleLeftChild(TreeNode *&k3)
  {
    rotateRightChild(k3->leftChild);
    rotateLeftChild(k3);
  }

  //thie method double rotates the right child
  void doubleRightChild(TreeNode *&k3)
  {
    rotateLeftChild(k3->rightChild);
    rotateRightChild(k3);
  }

  ///////////////////////////////////////////////////////
  //Public methods for AVL map
 public:
  AVLMap()
  {
    root = NULL;
  }

  ~AVLMap()
  {
    deleteTree(root);
  }

  //returns a boolean if there is node containing the key
  bool find(const S& key)
  {
    TreeNode *node = searchTree(root, key);

    if(node != NULL)
      return true;
    else
      return false;
   
  }

  //overides the operator function
  T& operator[](const S& key)
  {
    TreeNode *node = searchTree(root, key);

    if(node != NULL)
      return node->value;
    else
    {
      insert(NULL, key);
      node = searchTree(root, key);

      return node->value;
    }
  }

  //returns a vector of all the keys
  vector<S> getKeys()
  {
    vector<S>keyList;
    vector<TreeNode*>nodeList;

    getNodes(root, &nodeList);

    int i;
    for(i = 0; i < nodeList.size(); i++)
    {
      keyList.push_back(nodeList[i]->key);
    }

    return keyList;
  }

};

#endif
