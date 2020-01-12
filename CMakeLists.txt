cmake_minimum_required (VERSION 3.8)

project ("vlci")

set(CMAKE_EXECUTABLE_SUFFIX ".exe")

# Include sub-projects.
add_subdirectory ("vlcp")
add_subdirectory ("client")

# TESTING
option(ENABLE_TESTING "Enable or disable testing of vlci components" OFF)

if (ENABLE_TESTING)
    enable_testing()
    add_subdirectory("tests")
endif()


# DOCUMENTATION
find_package(Doxygen)
option(GENERATE_DOCS "Genetates documentation (require Doxygen)" DOXYGEN_FOUND)

if (GENERATE_DOCS)
    add_subdirectory("docs")
endif()
