cmake_minimum_required (VERSION 3.8)

add_library (LambdaProcessor 
    "Lexer/tokens.cpp" 
    "Lexer/lexer.cpp"

    "AST/lambda.cpp"
    "AST/variable.cpp"
    "AST/application.cpp"
    "AST/abstraction.cpp"
    "AST/boundedVariable.cpp"

    "Parser/VectorSlice/VectorSlice.hpp"
    "Parser/parsedTree.cpp"
    )
