#include<iostream>
#include<vector>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(int d){
			this->data=d;
			this->left=this->right=NULL;
		}
};

class BST{
	public:
		Node* root;
		BST(){
			this->root=NULL;
		}
};

Node* insertBST(Node* root,int d){
	if(root==NULL){
		Node* temp=new Node(d);
		return temp;
	}
	if(root->data > d){
		root->left=insertBST(root->left,d);
	}
	if(root->data < d){
		root->right=insertBST(root->right,d);
	}
	return root;
}



void inorderPrint(Node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";      //preorder.....................
	inorderPrint(root->left);
//	cout<<root->data<<" ";       //Inorder.....................
	inorderPrint(root->right);
//	cout<<root->data<<" ";       //postorder...................
	return;
}

Node* largestNodeBST(Node* root){
	Node* curr=root;
	while(curr && curr->left){
		curr=curr->left;
	}
	return curr;
}


Node* deleteNode(Node* root,int key){
	if(root==NULL) return NULL;
	if(root->data > key){
		root->left=deleteNode(root->left,key);
	}
	else if(root->data < key){
		root->right=deleteNode(root->right,key);
	}
	else{
		if(root->left==NULL && root->right==NULL){
            cout<<root->data<<" is deleted from BST"<<endl;
			free(root);
			return NULL;
		}
		else if(root->left==NULL){
			Node* temp=root->right;
            cout<<root->data<<" is deleted from BST"<<endl;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			Node* temp=root->left;
            cout<<root->data<<" is deleted from BST"<<endl;
			free(root);
			return temp;
		}
		//root has two child............
		else{
			Node* justSmallerval=largestNodeBST(root->right);
			root->data=justSmallerval->data;
			root->right=deleteNode(root->right,justSmallerval->data);
		}
	}
	return root;
}

bool searchBST(Node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (root->data > key) {
        return searchBST(root->left, key);
    }
    return searchBST(root->right, key);
}

int main(){
	BST b;
	int n;
    cout<<"Enter size of BST: ";
	cin>>n;   // if input 5 
	int data;
    cout<<"Enter ele : ";
	for(int i=0;i<n;i++){
		cin>>data;                       // if input 1 2 3 4 5
		b.root=insertBST(b.root,data);  
	}
    //print inorder
    cout<<"Inorder Triversal: ";
	inorderPrint(b.root);
    cout<<endl;

    //delete
    cout<<endl<<"Enter ele for delete : ";
    int del;
    cin>>del; 
	deleteNode(b.root,del);

    //search
    cout<<endl<<"Enter search Key for : ";
    int key;
    cin>>key; 
    if(searchBST(b.root,key)){
        cout<<key<<" present in BST";
    }else{
        cout<<key<<" not present in BST";
    }
	cout<<endl;


    //print inorder
    cout<<"Inorder Triversal: ";
	inorderPrint(b.root);
    cout<<endl;
	return 0;
}