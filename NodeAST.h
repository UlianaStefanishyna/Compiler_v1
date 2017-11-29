//
// Created by uliana on 29/11/17.
//

#ifndef COMPILER_V3_NODEAST_H
#define COMPILER_V3_NODEAST_H

enum ASTNodeType {
    Undefined,
    OperatorPlus,
    OperatorMinus,
    OperatorMul,
    OperatorDiv,
    UnaryMinus,
    NumberValue
};

class ASTNode {
public:
    ASTNodeType Type;
    double Value;
    ASTNode *Left;
    ASTNode *Right;

    ASTNode() {
        Type = Undefined;
        Value = 0;
        Left = nullptr;
        Right = nullptr;
    }

    ~ASTNode() {
        delete Left;
        delete Right;
    }
};


#endif //COMPILER_V3_NODEAST_H
