%{
/** Code by @author Wonsun Ahn, Fall 2024
 * 
 * The parser implementation file.
 */

#include <stdlib.h>
#include <stdio.h>
#include "proj2.h"

extern int yylex();
static void yyerror(char *str);

tree SyntaxTree;
static tree method_type, tree_type;

/* TODO: Add variable definitons as needed. */

%}

%union {
  int intg;
  tree tptr;
}

/* Terminal (token) declarations */ //all of those are from the lexer
%token <intg>  PROGRAMnum IDnum SEMInum CLASSnum  DECLARATIONSnum  ENDDECLARATIONSnum
%token <intg>  COMMAnum EQUALnum LBRACEnum RBRACEnum LBRACnum RBRACnum LPARENnum RPARENnum VOIDnum
%token <intg>  INTnum METHODnum VALnum DOTnum ASSGNnum RETURNnum IFnum ELSEnum WHILEnum
%token <intg>  LTnum LEnum EQnum NEnum GEnum GTnum PLUSnum MINUSnum ORnum TIMESnum DIVIDEnum ANDnum
%token <intg>  ICONSTnum SCONSTnum

/* Non-terminal (tree node) declarations */
%type  <tptr>  Program
%type  <tptr>  ClassDecl
%type  <tptr>  ClassBody
%type  <tptr>  Decls
%type  <tptr>  FieldDecl
%type  <tptr>  FieldDecl_Rec
%type  <tptr>  VariableDecId
%type  <tptr>  ArrayCreationDimensions
%type  <tptr>  VariableInitializer
%type  <tptr>  ArrayInitializer
%type  <tptr>  MethodDecl
%type  <tptr>  MethodDecl_Rec
%type  <tptr>  FormalParameterList
%type  <tptr>  Block
%type  <tptr>  Type
%type  <tptr>  StatementList
%type  <tptr>  Statement
%type  <tptr>  AssignmentStatement
%type  <tptr>  MethodCallStatement
%type  <tptr>  ReturnStatement
%type  <tptr>  IfStatement
%type  <tptr>  WhileStatement
%type  <tptr>  Expression
%type  <tptr>  SimpleExpression
%type  <tptr>  Term
%type  <tptr>  Operate
%type  <tptr>  Factor
%type  <tptr>  UnsignedConstant
%type  <tptr>  Variable
%type  <tptr>  VariableDecIdList
%type  <tptr>  RAParameter
%type  <tptr>  ExpressionList
%type  <tptr>  ArrayCreationExpression
%type  <tptr>  ArrayVariableDecIdList
%type  <tptr>  Type_Rec
%type  <tptr>  Comp_op
%type  <tptr>  Statement_Rec
%type  <tptr>  ElseStatment
%type  <tptr>  VarList
%type  <tptr>  VAParameter
%type  <tptr>  Parameter

/* TODO: Add more non-terminal definitons as needed. */

%%

/* TODO: Fix this production rule so that it matches language specification. */
Program          :      PROGRAMnum IDnum SEMInum ClassDecl
                        { 
                          $$ = MakeTree(ProgramOp, $4, MakeLeaf(IDNode, $2));
                          SyntaxTree = $$;
                        }
                        ;

/* TODO: Add grammar rules and semantic actions for each non-terminal. */
ClassDecl           :   ClassDecl CLASSnum IDnum ClassBody
                        {
                          tree moreClass = MakeTree(ClassDefOp, $4, MakeLeaf(IDNode, $3));
                          $$ = MakeTree(ClassOp, $1 ,moreClass);
                        }
                        | CLASSnum IDnum ClassBody
                        {
                          tree oneClass = MakeTree(ClassDefOp, $3, MakeLeaf(IDNode, $2));
                          $$ = MakeTree(ClassOp, NullExp(),oneClass);
                        }
                        ;
ClassBody           :    LBRACEnum Decls MethodDecl_Rec RBRACEnum
                        {
                          // if($3 == NullExp())
                          // {
                          //   $$ = $2;
                          // }
                          // else if($2 != NullExp())
                          // {
                          //   $$ = NullExp();
                          // }
                          // else
                          // {
                            $$ = MkLeftC($2, $3);
                          //}
                        }
                        | LBRACEnum Decls RBRACEnum
                        {
                          $$ = $2;
                        }
                        | LBRACEnum MethodDecl_Rec RBRACEnum
                        {
                          $$ = $2;
                        }
                        | LBRACEnum RBRACEnum
                        {
                          $$ = NullExp();
                        }
                        ;

Decls               :   DECLARATIONSnum FieldDecl_Rec ENDDECLARATIONSnum
                        {
                          $$ = $2;
                        }
                        | DECLARATIONSnum ENDDECLARATIONSnum
                        {
                          $$ = MakeTree(BodyOp, NullExp(), NullExp());
                        }
                        ;
FieldDecl_Rec         : /*
                        {
                          $$ = NullExp();
                        }
                        | */FieldDecl_Rec FieldDecl
                        {
                          $$ = MakeTree(BodyOp, $1, $2);
                        }
                        | FieldDecl
                        {
                          $$ = MakeTree(BodyOp, NullExp(), $1);
                        }
                        ;
FieldDecl           :   Type VariableDecIdList SEMInum
                        {
                          $$ = $2;
                        }
                        ;

VariableDecIdList   :   VariableDecId
                        {
                          tree comma = MakeTree(CommaOp,tree_type, NullExp());
                          tree var = MakeTree(CommaOp, $1, comma);
                          $$ = MakeTree(DeclOp, NullExp(),var);
                        }
                        | VariableDecIdList COMMAnum VariableDecId
                        {
                          tree comma = MakeTree(CommaOp,tree_type, NullExp());
                          tree var = MakeTree(CommaOp, $3, comma);
                          $$ = MakeTree(DeclOp, $1,var);
                        }  
                        | VariableDecIdList COMMAnum VariableDecId EQUALnum VariableInitializer
                        {
                          tree comma = MakeTree(CommaOp,tree_type, $5);
                          tree var = MakeTree(CommaOp, $3, comma);
                          $$ = MakeTree(DeclOp, $1,var);
                        }
                        | VariableDecId EQUALnum VariableInitializer
                        {
                          tree comma = MakeTree(CommaOp,tree_type, $3);
                          tree var = MakeTree(CommaOp, $1, comma);
                          $$ = MakeTree(DeclOp, NullExp(),var);
                        }                      
                        ;
VariableDecId       :   IDnum
                        {
                          $$ = MakeLeaf(IDNode, $1);
                        }
                        /* | IDnum EQUALnum VariableInitializer
                        {
                          tree comma = MakeTree(CommaOp, tree_type, $3); // $3 is the initializer subtree
                          tree var = MakeTree(CommaOp, MakeLeaf(IDNode, $1), comma);
                          $$ = MakeTree(DeclOp, NullExp(), var);
                        } */
                        |IDnum LBRACnum RBRACnum
                        {
                          $$ = MakeLeaf(IDNode, $1);
                        }
                        ;
Type                :   IDnum Type_Rec
                        {
                          $$ = tree_type = MakeTree(TypeIdOp, MakeLeaf(IDNode, $1), $2);
                        }
                        |	INTnum Type_Rec
                        {
                          $$  = tree_type = MakeTree(TypeIdOp, MakeLeaf(INTEGERTNode, $1), $2);
                        }
                        | DOTnum Type
                        {
                          $$ = MakeTree(FieldOp,$2, NullExp()); 
                        }
                        /*|e
                        {
                          $$ = NullExp();
                        }*/
                        ;
Type_Rec            :   LBRACnum RBRACnum Type_Rec
                        {
                          $$  = MakeTree(IndexOp, NullExp(), $3);
                        }
                        | DOTnum Type
                        {
                          $$ = MakeTree(FieldOp,$2, NullExp()); 
                        }
                        |/*e*/
                        {
                          $$ = NullExp();
                        }
                        ;
VariableInitializer :   Expression
                        {
                          $$ = $1;
                        }
                        | ArrayInitializer
                        {
                          $$ = $1;
                        }
                        | ArrayCreationExpression
                        {
                          $$ = $1;
                        }
                        ;
ArrayInitializer    :  LBRACEnum ArrayVariableDecIdList RBRACEnum
                        {
                          // if($2 == NullExp())
                          // {
                          //   tree comma = MakeTree(CommaOp, NullExp(), NullExp());
                          //   $$ = MakeTree(ArrayTypeOp, tree_type, comma);
                          // }
                          // else
                          // {
                            $$ = MakeTree(ArrayTypeOp, $2, tree_type);
                          //}
                        }
                        | LBRACEnum RBRACEnum
                        {
                          tree comma = MakeTree(CommaOp, NullExp(), NullExp());
                          $$ = MakeTree(ArrayTypeOp, tree_type, comma);
                        }
                        ;
ArrayVariableDecIdList  : VariableInitializer
                          {
                            $$ = MakeTree(CommaOp, NullExp(),$1);
                          }
                          | ArrayVariableDecIdList COMMAnum VariableInitializer
                          {
                            $$ = MakeTree(CommaOp, $1,$3);
                          };
ArrayCreationExpression : INTnum LBRACnum Expression RBRACnum ArrayCreationDimensions
                         {
                           /* Create the int type leaf */
                           tree integr = MakeLeaf(INTEGERTNode, 0);

                           /* Handle array dimensions recursively */
                           tree dimensionTree = MakeTree(BoundOp, $5, $3);

                           /* Create the final array type node */
                           $$ = MakeTree(ArrayTypeOp, dimensionTree, integr);
                         }
                       ;

ArrayCreationDimensions : LBRACnum Expression RBRACnum ArrayCreationDimensions
                         {
                           /* Recursive case: Adding array dimension using BoundOp */
                           $$ = MakeTree(BoundOp, $4, $2);
                         }
                         |
                         {
                          $$ = NullExp();
                         }
                       ;

MethodDecl_Rec      :   /* e, it's zero or more
                        {
                          $$ = NullExp();
                        } 
                      |*/ MethodDecl_Rec MethodDecl
                        {
                          $$ = MakeTree(BodyOp, $1, $2);
                        }
                      | MethodDecl
                        {
                          $$ = MakeTree(BodyOp, NullExp(), $1);
                        }
                        ;
MethodDecl          : METHODnum VOIDnum IDnum LPARENnum FormalParameterList RPARENnum Block
                      {
                        method_type = NullExp();
                        tree head = MakeTree(HeadOp, MakeLeaf(IDNode, $3), $5);
                        $$ = MakeTree(MethodOp, head, $7);
                      }
                    | METHODnum VOIDnum IDnum LPARENnum RPARENnum Block
                    {
                        method_type = NullExp();
                        tree spec = MakeTree(SpecOp, NullExp(), method_type);
                        tree head = MakeTree(HeadOp, MakeLeaf(IDNode, $3), spec);
                        $$ = MakeTree(MethodOp, head, $6);
                    }
                    | METHODnum Type IDnum LPARENnum FormalParameterList RPARENnum Block
                      {
                        method_type = $2;
                        tree head = MakeTree(HeadOp, MakeLeaf(IDNode, $3), $5);
                        $$ = MakeTree(MethodOp, head, $7);
                      }
                    | METHODnum Type IDnum LPARENnum RPARENnum Block
                    {
                      method_type = $2;
                      tree spec = MakeTree(SpecOp, NullExp(), method_type);
                      tree head = MakeTree(HeadOp, MakeLeaf(IDNode, $3), spec);
                      $$ = MakeTree(MethodOp, head, $6);
                    }
                    ;
FormalParameterList : /* empty 
                     {
                       
                       $$ = NullExp();
                     }
                    | */Parameter
                     {
                       /* Single parameter */
                       $$ = MakeTree(SpecOp, $1, tree_type);
                     }
                   ;
Parameter           : 
                      {
                        $$ = NullExp();
                      }
                      | INTnum RAParameter
                      {
                        $$ = $2;
                      }
                      | VALnum INTnum VAParameter
                      {
                        $$ = $3;
                      }
                      | INTnum RAParameter SEMInum Parameter
                      {
                        $$ = MkRightC($4,$2);
                      }
                      | VALnum INTnum VAParameter SEMInum Parameter
                      {
                        $$ = MkRightC($5, $3);
                      }
                      ;
RAParameter     :     IDnum
                      {
                        tree comma = MakeTree(CommaOp, MakeLeaf(IDNode, $1), MakeLeaf(INTEGERTNode, 0));
                        $$ = MakeTree(RArgTypeOp, comma, NullExp());
                      }
                      | IDnum COMMAnum RAParameter
                      {
                        tree comma = MakeTree(CommaOp, MakeLeaf(IDNode, $1), MakeLeaf(INTEGERTNode, 0));
                        $$ = MakeTree(RArgTypeOp, comma, $3);
                      }
                    ;
VAParameter   :     IDnum
                      {
                        tree comma = MakeTree(CommaOp, MakeLeaf(IDNode, $1), MakeLeaf(INTEGERTNode, 0));
                        $$ = MakeTree(VArgTypeOp, comma, NullExp());
                      }
                      | IDnum COMMAnum VAParameter
                      {
                        tree comma = MakeTree(CommaOp, MakeLeaf(IDNode, $1), MakeLeaf(INTEGERTNode, 0));
                        $$ = MakeTree(VArgTypeOp, comma, $3);
                      }
                    ;
Block               :/*  e */
                      {
                        $$ = MakeTree(BodyOp, NullExp(), NullExp());
                      }
                      | Decls StatementList
                      {
                        $$ = MakeTree(BodyOp, $1, $2);
                      }
                      | Decls
                      {
                        $$ = MakeTree(BodyOp,  $1, NullExp());
                      }
                      | StatementList
                      {
                        $$ = MakeTree(BodyOp, NullExp(), $1);
                      }
                      ;
StatementList       : LBRACEnum RBRACEnum
                      {
                        $$ = MakeTree(BodyOp, NullExp(), NullExp());
                      }
                      | LBRACEnum Statement_Rec RBRACEnum
                      {
                        $$ = $2;
                      }
                      ;
Statement_Rec       : Statement SEMInum
                      {
                        $$ = MakeTree(StmtOp, NullExp(),$1);
                      }
                      | Statement_Rec Statement SEMInum
                      {
                        $$ = MakeTree(StmtOp, $1, $2);
                      }
Statement           : /*empty
                      {
                        $$ = NullExp();
                      }
                      | */AssignmentStatement
                      {
                        $$ = $1;
                      }
                      | MethodCallStatement
                      {
                        $$ = $1;
                      }
                      | ReturnStatement
                      {
                        $$ = $1;
                      }
                      | IfStatement 
                      {
                        $$ = $1;
                      }
                      | WhileStatement
                      {
                        $$ = $1;
                      }
                      ;
AssignmentStatement : Variable ASSGNnum Expression
                      {
                        tree innerA = MakeTree(AssignOp, NullExp(), $1);
                        $$ = MakeTree(AssignOp,innerA, $3);
                      }
                      ;
MethodCallStatement : Variable LPARENnum ExpressionList RPARENnum
                      {
                        if($3 == NullExp())
                        {
                          $$ = MakeTree(RoutineCallOp,$1, NullExp());
                        }
                        else
                        {
                          $$ = MakeTree(RoutineCallOp, $1, $3);
                        }
                      }
                      ;
Variable            : IDnum VarList
                      {
                        $$ = MakeTree(VarOp, MakeLeaf(IDNode, $1), $2);
                      }
                    ;
VarList             : /* empty */
                      {
                        /* Represents an empty sequence of selectors */
                        $$ = NullExp();
                      }
                    | DOTnum IDnum VarList
                      {
                        /* Field access followed by more selectors */
                        tree field = MakeTree(FieldOp, MakeLeaf(IDNode, $2), NullExp());
                        $$ = MakeTree(SelectOp, field, $3);
                      }
                    | LBRACnum Expression RBRACnum VarList
                      {
                        /* Array index followed by more selectors */
                        tree index = MakeTree(IndexOp, $2, NullExp());
                        $$ = MakeTree(SelectOp, index, $4);
                      }
                            ;  
ExpressionList      :  Expression
                      {
                        $$ = MakeTree(CommaOp, $1, NullExp());
                      }
                      | Expression COMMAnum ExpressionList
                      {
                        $$ = MakeTree(CommaOp, $1, $3);
                      }
                      |
                      {
                        $$ = NullExp();
                      }
                      ;
ReturnStatement     : RETURNnum Expression
                      {
                        $$ = MakeTree(ReturnOp,$2, NullExp());
                      }
                      | RETURNnum
                      {
                        $$ = MakeTree(ReturnOp,NullExp(), NullExp());
                      }
                      ;
IfStatement         : IFnum LPARENnum Expression RPARENnum StatementList ElseStatment
                      {
                        /* Handle an if-else statement */
                        tree comma = MakeTree(CommaOp, $3, $5); // Combines the if condition and statement block
                        tree ifElse = MakeTree(IfElseOp, NullExp(), comma); // If part
                        $$ = MkLeftC(ifElse, $6); // Attach the else block
                      }
                      | IFnum LPARENnum Expression RPARENnum StatementList
                      {
                        /* Handle an if statement without an else part */
                        tree comma = MakeTree(CommaOp, $3, $5); // Combines the if condition and statement block
                        $$ = MakeTree(IfElseOp, NullExp(), comma); // Simple if without else
                      }
                      | IFnum LPARENnum Expression RPARENnum StatementList ELSEnum IFnum LPARENnum Expression RPARENnum StatementList
                      {
                        tree comma = MakeTree(CommaOp, $3, $5);
                        tree elseif = MakeTree(CommaOp, $9, $11);
                        $$ = MakeTree(IfElseOp, comma, elseif);
                      }
                      ;
ElseStatment        : ELSEnum StatementList //one else
                      {
                        $$ = MakeTree(IfElseOp, NullExp(),$2);
                      }
                      | ELSEnum IFnum LPARENnum Expression RPARENnum StatementList
                      {
                        tree comma = MakeTree(CommaOp, $4, $6);
                        $$ = MakeTree(IfElseOp, NullExp(), comma);
                      }
                      | ELSEnum IFnum LPARENnum Expression RPARENnum StatementList ElseStatment//one or more elseif
                      {
                        tree comma = MakeTree(CommaOp, $4, $6);
                        tree ifElse = MakeTree(IfElseOp, NullExp(),comma);
                        $$ = MkLeftC(ifElse, $7);
                      }
                      ;
WhileStatement      : WHILEnum LPARENnum Expression RPARENnum StatementList
                      {
                        $$ = MakeTree(LoopOp, $3, $5);
                      }
                      ;
Expression          :  SimpleExpression {$$ = $1;}
                      | SimpleExpression Comp_op SimpleExpression
{ MkLeftC($1, $2); $$ = MkRightC($3, $2); }
;
SimpleExpression    : 
                      Term
                      {
                          $$ = $1;
                      }
                      /* | PLUSnum Term
                      {
                        $$ = $2;
                      }
                      | MINUSnum Term
                      {
                        $$ = MakeTree(UnaryNegOp, $2, NullExp());
                      } */
                      | SimpleExpression PLUSnum Term
                        {
                          /* Binary addition */
                          $$ = MakeTree(AddOp, $1, $3);
                        }
                      | SimpleExpression MINUSnum Term
                        {
                          /* Binary subtraction */
                            $$ = MakeTree(SubOp, $1, $3);
                        }
                      | SimpleExpression ORnum Term
                        {
                          /* Logical OR */
                          $$ = MakeTree(OrOp, $1, $3);
                        }
                        ;
Comp_op               : LTnum
                        {
                          $$ = MakeTree(LTOp, NullExp(), NullExp());
                        }
                      | LEnum
                        {
                          $$ = MakeTree(LEOp, NullExp(), NullExp());
                        }
                      | EQnum
                        {
                          $$ = MakeTree(EQOp, NullExp(), NullExp());
                        }
                      | NEnum
                        {
                          $$ = MakeTree(NEOp, NullExp(), NullExp());
                        }
                      | GEnum
                        {
                          $$ = MakeTree(GEOp, NullExp(), NullExp());
                        }
                      | GTnum
                        {
                          $$ = MakeTree(GTOp, NullExp(), NullExp());
                        }
                      ;

Term                  : Factor
                        {
                          $$ = $1;
                        }
                        | Term Operate Factor
                        {
                           MkLeftC($1, $2); $$ = MkRightC($3, $2);
                        }
                        ;
Operate               : TIMESnum
                        {
                          $$ = MakeTree(MultOp, NullExp(), NullExp());
                        }
                        | DIVIDEnum
                        {
                          $$ = MakeTree(DivOp, NullExp(), NullExp());
                        }
                        |ANDnum
                        {
                          $$ = MakeTree(AndOp, NullExp(), NullExp());
                        }
                        ;

Factor                : UnsignedConstant
                        {
                            $$ =  $1;
                        }
                        | Variable
                        {
                            $$ = $1;
                        }
                        | MethodCallStatement
                        {
                            $$ = $1;
                        }
                        | LPARENnum Expression RPARENnum
                        {
                            $$ = $2;  // Simply returns the enclosed expression
                        }
                        | MINUSnum Factor
                        {
                            $$ = MakeTree(UnaryNegOp, $2, NullExp());
                        }
                        ;
UnsignedConstant      : SCONSTnum
                        {
                          $$ = MakeLeaf(STRINGNode, $1);
                        }
                        | ICONSTnum
                        {
                          $$ = MakeLeaf(NUMNode, $1);
                        }
                        ;
                       

%%

int yycolumn = 1, yyline = 1;

void yyerror(char *str)
{
  printf("yyerror: %s at line %d\n", str, yyline);
  exit(0);
}

#include "lex.yy.c"