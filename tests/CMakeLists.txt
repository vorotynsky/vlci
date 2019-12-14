cmake_minimum_required (VERSION 3.8)

# install Catch2 testing library
# (https://github.com/catchorg/Catch2/blob/master/docs/c.. or use packet manager)
find_package(Catch2 REQUIRED)

add_executable(tests 
    "tests.cpp"
    "lexer_tests.cpp"

    "ast_equality/lambdas.cpp"
    "ast_equality/variable_tests.cpp"
    "ast_equality/application_tests.cpp"
    "ast_equality/abstraction_tests.cpp"

    "parser/vector_slice_tests.cpp"
)

target_link_libraries(tests
    Catch2::Catch2
    LambdaProcessor
)

include(CTest)
include(Catch)
catch_discover_tests(tests)