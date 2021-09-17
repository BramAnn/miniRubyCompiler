//
// Created by Bram_ on 15/08/2021.
//

#include "defStmt.h"

DefStmt::DefStmt(IdExpr *functionName, ExpressionList *functionArgs, Statement *code )
    : functionName{functionName}
    , functionArgs{functionArgs}
    , code{code} {

}

DefStmt::~DefStmt() {

}