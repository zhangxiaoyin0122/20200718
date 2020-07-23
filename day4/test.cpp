#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(const int v = int())
		:val()
		,next(nullptr)
	{

	}
};


class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr)
			return nullptr;
		ListNode* fast = pListHead;
		ListNode* slow = pListHead;
		while (k > 0 && fast) {
			fast = fast->next;
			k--;
		}
		while (fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return k > 0 ? nullptr : slow;
	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		//三指针法:
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;
		ListNode* first = pHead;
		ListNode* second = first->next;
		ListNode* third = second->next; //有可能为空
		while (third) {
			second->next = first;
			first = second;
			second = third;
			third = third->next;
		}
		second->next = first;
		pHead->next = nullptr;
		pHead = second;
		return pHead;
	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		//头插法
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;
		ListNode* newHead = nullptr;
		while (pHead) {
			ListNode* p = pHead;
			pHead = p->next;
			p->next = newHead;
			newHead = p;
		}
		return newHead;
	}
};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;
		ListNode* newHead = nullptr;
		ListNode* end = nullptr;
		while (pHead1 && pHead2) {
			ListNode* p = pHead1->val > pHead2->val ? pHead2 : pHead1;
			if (p == pHead1) {
				p = pHead1;
				pHead1 = p->next;
			}
			else {
				p = pHead2;
				pHead2 = p->next;
			}
			if (newHead == nullptr) {
				newHead = end = p;
			}
			else {
				end->next = p;
				end = p;
			}
		}
		if (pHead1 != nullptr)
			end->next = pHead1;
		if (pHead2 != nullptr)
			end->next = pHead2;
		return newHead;
	}
};

class Solution {
public:
	//判断两棵树是否相同
	bool IsSame(TreeNode* begin, TreeNode* begin_sub) {
		if (begin_sub == nullptr)
			return true;
		if (begin == nullptr)
			return false;
		if (begin->val != begin_sub->val)
			return false;
		return IsSame(begin->left, begin_sub->left) && IsSame(begin->right, begin_sub->right);
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		bool result = false;
		//根节点相同
		if (pRoot1->val == pRoot2->val) {
			//判断两棵树是否相同
			result = IsSame(pRoot1, pRoot2);
		}
		if (!result) {
			result = HasSubtree(pRoot1->left, pRoot2);
		}
		if (!result) {
			result = HasSubtree(pRoot1->right, pRoot2);
		}
		return result;
	}
};

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		//递归出口
		if (pRoot == nullptr)
			return;
		//镜像根节点的左右节点
		TreeNode* tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		//递归左右子树
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};