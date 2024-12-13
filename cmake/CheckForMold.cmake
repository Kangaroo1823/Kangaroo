

macro(Kangaroo_enable_mold)
    if(NOT (CMAKE_EXE_LINKER_FLAGS MATCHES ".*-fuse=mold.*"))
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=mold")
    endif()

    if(NOT (CMAKE_SHARED_LINKER_FLAGS MATCHES ".*-fuse=mold.*"))
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=mold")
    endif()

endmacro()