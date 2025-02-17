macro(Kangaroo_configure_linker project_name)
    include(CheckCXXCompilerFlag)

    if (CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
        set(USER_LINKER_OPTION
                "lld"
                CACHE STRING "Linker to be used"
        )
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(USER_LINKER_OPTION
                "mold"
                CACHE STRING "Linker to be used"
        )
    endif ()

    set(USER_LINKER_OPTION_VALUES "lld" "gold" "bfd" "mold")
    set_property(CACHE USER_LINKER_OPTION PROPERTY STRINGS ${USER_LINKER_OPTION_VALUES})
    list(
            FIND
            USER_LINKER_OPTION_VALUES
            ${USER_LINKER_OPTION}
            USER_LINKER_OPTION_INDEX)

    if (${USER_LINKER_OPTION_INDEX} EQUAL -1)
        message(
                STATUS
                "Using custom linker: '${USER_LINKER_OPTION}', explicitly supported entries are ${USER_LINKER_OPTION_VALUES}")
    else ()
        message(
                STATUS
                "Using linker: '${USER_LINKER_OPTION}'")
    endif ()

    if (NOT Kangaroo_ENABLE_USER_LINKER)
        return()
    endif ()

    set(LINKER_FLAG "-fuse-ld=${USER_LINKER_OPTION}")

    check_cxx_compiler_flag(${LINKER_FLAG} CXX_SUPPORTS_USER_LINKER)
    if (CXX_SUPPORTS_USER_LINKER)
        target_link_options(${project_name} BEFORE INTERFACE ${LINKER_FLAG})
    endif ()
endmacro()