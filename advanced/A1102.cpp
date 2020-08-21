#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	int index;
	TreeNode *left;
	TreeNode *right;

	TreeNode() {
		this->index = 0;
		this->left = NULL;
		this->right = NULL;
	}

	TreeNode(int index) {
		this->index = index;
		this->left = NULL;
		this->right = NULL;
	}
};

void invertBinaryTree(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	invertBinaryTree(root->left);
	invertBinaryTree(root->right);
	TreeNode *node = root->left;
	root->left = root->right;
	root->right = node;
}

void levelOrder(TreeNode *root, vector<int> &list) {
	queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty()) {
		int size = queue.size();

		for (int i = 0; i < size; i++) {
			TreeNode *node = queue.front();
			queue.pop();

			TreeNode *left = node->left;
			TreeNode *right = node->right;
			if (left != NULL) {
				queue.push(left);
			}
			if (right != NULL) {
				queue.push(right);
			}

			list.push_back(node->index);
		}
	}
}

void inorder(TreeNode *root, vector<int> &list) {
	TreeNode *left = root->left;
	TreeNode *right = root->right;
	if (left != NULL) {
		inorder(root->left, list);
	}
	list.push_back(root->index);
	if (right != NULL) {
		inorder(root->right, list);
	}
}

void print(vector<int> list) {
	for (unsigned int i = 0; i < list.size(); i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << list[i];
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;

	bool hash[n];
	fill(hash, hash + n, false);
	TreeNode tree[n];
	for (int i = 0; i < n; i++) {
		string left, right;

		cin >> left >> right;

		tree[i].index = i;
		if (left != "-") {
			int leftIndex = stoi(left);
			tree[i].left = &tree[leftIndex];
			tree[i].left->index = leftIndex;
			hash[leftIndex] = true;
		}
		if (right != "-") {
			int rightIndex = stoi(right);
			tree[i].right = &tree[rightIndex];
			tree[i].right->index = rightIndex;
			hash[rightIndex] = true;
		}
	}

	// 寻找根结点
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (!hash[i]) {
			idx = i;
			break;
		}
	}

	TreeNode *root = &tree[idx];

	// 翻转二叉树
	invertBinaryTree(root);

	// 层次遍历
	vector<int> levelList;
	levelOrder(root, levelList);
	print(levelList);

	// 中序遍历
	vector<int> inlist;
	inorder(root, inlist);
	print(inlist);
	return 0;
}
