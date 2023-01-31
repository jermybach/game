if(WIN32)
set(DIRENT_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_library(dirent INTERFACE)
target_include_directories(dirent INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/dirent/include")
endif()

