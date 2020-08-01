#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* right;
    node* down;
    node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
struct compare { 
    bool operator()(node* a, node* b) 
    { 
        return a->data > b->data; 
    } 
}; 
void printt(node* node){
    while(node!= NULL){
        cout<<node->data<<" ";
        node = node->down;
    }
}
node* flatten(node* root){
    node* ptr = root;
    node* head = NULL;
    priority_queue<node*,vector<node*>,compare> pq;
    while(ptr != NULL ){
        pq.push(ptr);
        ptr = ptr->right;
    }
    while(!pq.empty()){
        node* temp = pq.top();
        pq.pop();
        if(temp->down != NULL){
            pq.push(temp->down);
        }
        if(head == NULL){
            head = temp;
            ptr = temp;
        }
        else{
            ptr->down = temp;
            ptr = temp;
        }
    }
    return head;
}
void push (node** head_ref, int new_data) 
{ 
    node* new_node = (node*) malloc(sizeof(node)); 
    new_node->right = NULL; 
    new_node->data  = new_data; 
    new_node->down = (*head_ref); 
    (*head_ref) = new_node; 
} 
/*flatten recursively
node* merge(node* a,node* b){
    if(a== NULL) return b;
    if(b== NULL) return a;
    node* result;
    if(a->data < b->data){
        result = a;
        result->down = merge(a->down,b);
    }
    else{
        result = b;
        result->down= merge(a,b->down);
    }
    result->right = NULL;
    return result;
}
node* flattenR (node* root){
    if(root = NULL || root->right == NULL){
        return root;
    }
    return merge(root,flattenR(root->right));
}*/
int main() {
    node* root = NULL; 
  
    /* Let us create the following linked list 
       5 -> 10 -> 19 -> 28 
       |    |     |     | 
       V    V     V     V 
       7    20    22    35 
       |          |     | 
       V          V     V 
       8          50    40 
       |                | 
       V                V 
       30               45 
    */
    push( &root, 30 ); 
    push( &root, 8 ); 
    push( &root, 7 ); 
    push( &root, 5 ); 
  
    push( &( root->right ), 20 ); 
    push( &( root->right ), 10 ); 
  
    push( &( root->right->right ), 50 ); 
    push( &( root->right->right ), 22 ); 
    push( &( root->right->right ), 19 ); 
  
    push( &( root->right->right->right ), 45 ); 
    push( &( root->right->right->right ), 40 ); 
    push( &( root->right->right->right ), 35 ); 
    push( &( root->right->right->right ), 28 ); 
    root = flatten(root); 
    printt(root); 
    return 0; 
}
