#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class cmp{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution
{
	public:
	    void traverse(Node* root, string curr, vector<string> &res){
	        if(!root->left && !root->right){
	            res.push_back(curr);
	            return;
	        }
	        
	        traverse(root->left, curr + "0", res);
	        traverse(root->right, curr+ "1", res);
	    }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node*, vector<Node*>, cmp> pq;
		    
		    for(int i=0; i<N; i++){
		        Node* node = new Node(f[i]);
		        pq.push(node);
		    }
		    
		    while(pq.size() > 1){
		        Node* left = pq.top();
		        pq.pop();
		        
		        Node* right = pq.top();
		        pq.pop();
		        
		        Node* newNode = new Node(left->data + right->data);
		        newNode->left = left;
		        newNode->right = right;
		        pq.push(newNode);
		    }
		    
		    Node* root = pq.top();
		    pq.pop();
		    
		    vector<string> res;
		    traverse(root, "", res);
		    
		    return res;
		}
};

int main()
{
    string s;
    cout << "Enter string for huffman Encoding : ";
    cin >> s;
    
    int n = s.length();
    vector<int> f(n);
    cout << "\n\n\t| Frequencies of every character |" << endl;
    for(int i=0; i<n; i++){
        cout << "Enter frequency of " << s[i] << " character : ";
        cin >> f[i];
    }
    
    Solution S;
    vector<string> res = S.huffmanCodes(s, f, n);
    
    cout << "\n\n\t | Huffman Codes of every character |" << endl;
    for(int i=0; i<n; i++){
        cout << "Huffman Code of " << s[i] << " : " << res[i] << endl;
    }

    return 0;
}

/*
Enter string for huffman Encoding : abcdef


        | Frequencies of every character |
Enter frequency of a character : 45
Enter frequency of b character : 16
Enter frequency of c character : 13
Enter frequency of d character : 12
Enter frequency of e character : 9
Enter frequency of f character : 5


         | Huffman Codes of every character |
Huffman Code of a : 0
Huffman Code of b : 100
Huffman Code of c : 101
Huffman Code of d : 1100
Huffman Code of e : 1101
Huffman Code of f : 111
*/