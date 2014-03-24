include_directories(../src)

add_executable(test_table test_table.c)
target_link_libraries(test_table table)
