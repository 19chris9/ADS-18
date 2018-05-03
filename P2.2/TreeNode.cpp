#include "TreeNode.h"


TreeNode::TreeNode(string n, int a, double e, int p)
{
	name = n; alter = a; einkommen = e; PLZ = p;
	NodePosID = alter + einkommen + PLZ;
}
