/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
   
    Node* lowestCommonAncestor(Node* p, Node * q) {
        
    Node*a=p;
    Node*b=q;
    while(a!=b){
        a = (a!=NULL)?a->parent:q;
        b = (b!=NULL)?b->parent:p;
    }
      return a;

    }
};