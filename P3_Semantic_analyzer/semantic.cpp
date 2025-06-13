#include <vector>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
extern "C"
{
#include "proj2.h"
}
#include "proj3.h"

extern tree SyntaxTree;

using namespace std;

/* TODO: Add additional variable definitions as needed. */
void HandleMethodOp(tree treenode);
void SetFunctionTypeAttr(tree treenode, int index);
int SetFunctionArgs(tree treenode);
int InsertFunctionArg(tree curr);
void SetArgAttributes(tree curr, int index2, int offset);
void HandleMethodBody(tree treenode);

void HandleClassDefOp(tree treenode);


void HandleDeclOp(tree treenode);
int InsertDeclEntry(tree treenode);
void SetArrayDimensions(tree treenode, int index);
void SetCommonAttributes(tree treenode, int index);
void UpdateTreeNode(tree node, int index);



void HandleDefaultOp(tree treenode);

stack<int> offset_stk;


/// @brief While recurrsively traversing the tree, add symbol declarations to the symbol table and replace IDNodes, that are uses of symbols in the source code, with STNodes, or symbol table nodes.  IDNodes contain an index into the string table where the name is and STNodes contain an index into the symbol table where symbol attributes (including the name) are.
/// @param treenode Tree node to recurrsively traverse.
void MkST(tree treenode)
{
	/* TODO: Complete function as described in above comment. */

	if (treenode == SyntaxTree)
	{
		/* Open global scope for the entire source file. */
		OpenBlock();

		/* TODO: Change the right child of treenode (the program name) from an IDNode to an STNode. */
		int programindex = InsertEntry(IntVal(RightChild(treenode)), PROGRAM, 0);
        SetRightChild(treenode, MakeLeaf(STNode, programindex));

        /* Open the scope for program. */
		OpenBlock();
		/* Add the predefined classes and methods to symbol table, within program scope. */
		STAddPredefined();
		/* Traverse the body of the program and add rest of the symbols to symbol table. */
		MkST(LeftChild(treenode));
		CloseBlock();

		/* Close global scope for the entire source file. */
		CloseBlock();

		return;
	}
    if (!IsNull(treenode))
    {
        // deal with different kind of IDs
        switch (NodeOp(treenode))
        {
        case MethodOp:
            HandleMethodOp(treenode);
            break;
        case ClassDefOp:
            HandleClassDefOp(treenode);
            break;
        case DeclOp:
            HandleDeclOp(treenode);
            break;
        default:
            HandleDefaultOp(treenode);
            break;
        }
    }
    return;
}

void HandleMethodOp(tree treenode)
{
    int index = LookUp(IntVal(treenode->LeftC->LeftC)); //find the method in the table
    if (index == -1)
    {
        // Insert new function entry if not found
        index = InsertEntry(IntVal(treenode->LeftC->LeftC), FUNC, 0);
        SetFunctionTypeAttr(treenode, index);
        SetAttr(index, INIT_ATTR, reinterpret_cast<uintptr_t>(treenode->RightC));
         // Open new block for method scope
        OpenBlock();
        int args_counter = SetFunctionArgs(treenode);
        SetAttr(index, ARGNUM_ATTR, args_counter);
    }
    // Update the function node with the symbol table index
    UpdateTreeNode(treenode->LeftC->LeftC, index);
    HandleMethodBody(treenode);
}

void SetFunctionTypeAttr(tree treenode, int index)
{
    if (IsNull(treenode->LeftC->RightC->RightC))
    {
        //void method, no return
        SetAttr(index, TYPE_ATTR, reinterpret_cast<uintptr_t>(treenode->LeftC->RightC->RightC));
    }
    else
    {
        SetAttr(index, TYPE_ATTR, reinterpret_cast<uintptr_t>(treenode->LeftC->RightC->RightC->LeftC));
    }
}

int SetFunctionArgs(tree treenode)
{
    int count = 0; //arg counter
    tree curr = treenode->LeftC->RightC->LeftC; //first arg
    while (!IsNull(curr))
    {
        int index2 = InsertFunctionArg(curr);
        SetArgAttributes(curr, index2, count++);
        curr = curr->RightC; //next arg
    }
    return count;
}

int InsertFunctionArg(tree curr)
{
    if (NodeOp(curr) == RArgTypeOp)
    {
        return InsertEntry(IntVal(curr->LeftC->LeftC), REF_ARG, 0); // ref arg
    }
    else
    {
        return InsertEntry(IntVal(curr->LeftC->LeftC), VALUE_ARG, 0); // noraml value arg
    }
}

void SetArgAttributes(tree curr, int index2, int offset)
{
    SetAttr(index2, TYPE_ATTR, reinterpret_cast<uintptr_t>(curr->LeftC->RightC)); // set arg type
    SetAttr(index2, OFFSET_ATTR, offset); //set offset
	UpdateTreeNode(curr->LeftC->LeftC, index2);// Update argument node with symbol table index
}

void UpdateTreeNode(tree node, int index)
{
    node->NodeKind = STNode;
    node->IntVal = index;// Set symbol table index
}

void HandleMethodBody(tree treenode)
{
    offset_stk.push(0);// Push current offset to the stack
    MkST(RightChild(treenode));
    offset_stk.pop();// Pop offset after traversing
    CloseBlock();
}


void HandleClassDefOp(tree treenode)
{
    int index = LookUp(IntVal(treenode->RightC));
    if (index == -1)
    {
        index = InsertEntry(IntVal(treenode->RightC), CLASS, 0);// Insert new class entry if not found
    }
	UpdateTreeNode(treenode->RightC, index);

    // Open new block for class scope
    OpenBlock();
    offset_stk.push(0); // Push current offset to the stack
    MkST(LeftChild(treenode)); // Traverse class body
    offset_stk.pop(); // Pop offset after traversing
    CloseBlock(); // Close class scope
}

void HandleDeclOp(tree treenode)
{
    while (!IsNull(treenode) && NodeOp(treenode) == DeclOp)
    {
        int index = LookUpHere(IntVal(treenode->RightC->LeftC));
        if (index == -1)
        {
             // Insert new decl if not found
            index = InsertDeclEntry(treenode);
            SetCommonAttributes(treenode, index);
        }
        UpdateTreeNode(treenode->RightC->LeftC, index);
        MkST(RightChild(treenode));
        treenode = treenode->LeftC; // traverse to the next decl
    }
}

int InsertDeclEntry(tree treenode)
{
    int index;
    if (IsNull(treenode->RightC->RightC->LeftC->RightC))
    {
        // var entry
        index = InsertEntry(IntVal(treenode->RightC->LeftC), VAR, 0);
    }
    else
    {
        //array entry
        index = InsertEntry(IntVal(treenode->RightC->LeftC), ARR, 0);
        SetArrayDimensions(treenode, index);
    }
    return index;
}

void SetArrayDimensions(tree treenode, int index)
{
    vector<int> *dims = new vector<int>;
    tree arrayTypeNode = treenode->RightC->RightC->RightC;
    if (NodeOp(arrayTypeNode->LeftC) == CommaOp)
    {

        //comma-separated dimensions
        int counter = 0;
        for (tree curr = arrayTypeNode->LeftC; !IsNull(curr); curr = curr->LeftC)
        {
            counter++;
        }
        dims->push_back(counter);
    }
    //bound dimensions
    else if (NodeOp(arrayTypeNode->LeftC) == BoundOp)
    {
        for (tree curr = arrayTypeNode->LeftC; !IsNull(curr); curr = curr->LeftC)
        {
            dims->push_back(IntVal(curr->RightC));
        }
    }
    SetAttr(index, DIMEN_ATTR, reinterpret_cast<uintptr_t>(dims));
}

void SetCommonAttributes(tree treenode, int index)
{
    SetAttr(index, TYPE_ATTR, reinterpret_cast<uintptr_t>(treenode->RightC->RightC->LeftC));
    if (!IsNull(treenode->RightC->RightC->RightC))
    {
        SetAttr(index, INIT_ATTR, reinterpret_cast<uintptr_t>(treenode->RightC->RightC->RightC));
    }
    SetAttr(index, OFFSET_ATTR, offset_stk.top()++);// Set offset attribute
}

void HandleDefaultOp(tree treenode)
{
    if (NodeKind(treenode) == IDNode)
    {
		UpdateTreeNode(treenode, LookUp(IntVal(treenode)));
    }
    MkST(LeftChild(treenode));
    MkST(RightChild(treenode));
}