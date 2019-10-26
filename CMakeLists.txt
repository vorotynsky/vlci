cmake_minimum_required (VERSION 3.8)

project ("vlci")

# Include sub-projects.
add_subdirectory ("vlcp")
add_subdirectory ("client")

option(ENABLE_TESTING "Enable or disable testing of vlci components" ON)

if (ENABLE_TESTING)
    enable_testing()
    add_subdirectory("tests")
endif()
