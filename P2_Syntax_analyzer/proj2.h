#ifndef PROJ2_H_
#define PROJ2_H_

/* Define syntax tree node and pointer type tree. */
typedef struct treenode {
        int NodeKind, NodeOpType, IntVal;
        struct treenode *LeftC, *RightC;
} ILTree, *tree;

#define ProgramOp 100 //node for program, root node
#define BodyOp 101 //node for class body, method body, decl body, statmentlist body
#define DeclOp 102 //node for each declaration
#define CommaOp 103 //node for "," operator
#define ArrayTypeOp 104 //node for array type
#define TypeIdOp 105 //node for type of a variable or method
#define BoundOp 106 //node for array bound in variable declaration
#define RecompOp 107
#define ToOp 108
#define DownToOp 109
#define ConstantIdOp 110
#define ProceOp 111
#define FuncOp 112
#define HeadOp 113 //node for head of method
#define RArgTypeOp 114 //node for each argument
#define VArgTypeOp 115 //node for each argument specified by "VAL" .e.g. abc(VAL int x)
#define StmtOp 116 //node for statement
#define IfElseOp 117 //node for if-then-else
#define LoopOp 118 //node for while statement
#define SpecOp 119 //node for specification of parameters
#define RoutineCallOp 120 //node for routine call
#define AssignOp 121 //node for assign operator
#define ReturnOp 122 //node for return statement
#define AddOp 123
#define SubOp 124
#define MultOp 125
#define DivOp 126
#define LTOp 127
#define GTOp 128
#define EQOp 129
#define NEOp 130
#define LEOp 131
#define GEOp 132
#define AndOp 133
#define OrOp 134
#define UnaryNegOp 135
#define NotOp 136
#define VarOp 137 //node for variables
#define SelectOp 138 //node for accessing an element/field variable
#define IndexOp 139 //node created when using "[]" to access an element
#define FieldOp 140 //node created when using "." to access a field
#define SubrangeOp 141
#define ExitOp 142
#define ClassOp 143
#define MethodOp 144 // node for each method
#define ClassDefOp 145 //node for each class defintion

#define IDNode 200 // ID 
#define NUMNode 201 // int 
#define CHARNode 202
#define STRINGNode 203 // string 
#define DUMMYNode 204 // Null
#define EXPRNode 205 //
#define INTEGERTNode 206
#define CHARTNode 207
#define BOOLEANTNode 208

tree NullExp();
tree MakeLeaf(int, int);
tree MakeTree(int, tree, tree);
tree LeftChild(tree);
tree RightChild(tree);
tree MkLeftC(tree, tree);
tree MkRightC(tree, tree);

int NodeOp(tree T);
int NodeKind(tree T);
int IntVal(tree T);
int IsNull(tree T);

void SetNode(tree, tree);
void SetNodeOp(tree, int);
void SetLeftTreeOp(tree, int);
void SetRightTreeOp(tree, int);
void SetLeftChild(tree, tree);
void SetRightChild(tree, tree);

void printtree(tree nd, int depth);

#endif /* #ifndef PROJ2_H_ */