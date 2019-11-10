cmake_minimum_required (VERSION 3.8)

find_package(Doxygen)
option(GENERATE_DOCS "Genetates documentation (require Doxygen)" DOXYGEN_FOUND)

if (DOXYGEN_FOUND)
    find_package(Doxygen REQUIRED)
    find_program(MOXYGEN moxygen REQUIRED)

    set(DOXYGEN_PROJECT_NAME "vlci")
    set(DOXYGEN_PROJECT_BRIEF "Vorotynsky's lambda calculus interpreter")
    set(DOXYGEN_ALLOW_UNICODE_NAMES YES)
    set(DOXYGEN_RECURSIVE YES)
    
    set(DOXYGEN_GENERATE_HTML NO)
    set(DOXYGEN_GENERATE_LATEX NO)
    set(DOXYGEN_GENERATE_DOCBOOK NO)
    set(DOXYGEN_GENERATE_RTF NO)
    set(DOXYGEN_GENERATE_MAN NO)
    
    set(DOXYGEN_GENERATE_XML YES)
    set(DOCUMENTATION_DIRECTORY ${PROJECT_SOURCE_DIR}/docs)
    set(DOXYGEN_XML_OUTPUT ${DOCUMENTATION_DIRECTORY}/xml)
    
    doxygen_add_docs(
        doxygen ALL
        ${PROJECT_SOURCE_DIR}/vlcp # documentation only for `vlcp`.
        COMMENT "Generate man pages"
        )

    if (MOXYGEN)
        add_custom_target(
            moxygen
            ${MOXYGEN} ${DOXYGEN_XML_OUTPUT}
            WORKING_DIRECTORY ${DOCUMENTATION_DIRECTORY}
        )
    else()
        message(SEND_ERROR "Moxygen not found")
    endif()

    add_custom_target(documentation doxygen moxygen)
endif()