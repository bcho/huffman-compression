include_directories(../src)

add_executable(test_table test_table.c)
target_link_libraries(test_table table)

add_executable(test_io test_io.c)
target_link_libraries(test_io io)

add_executable(test_priority_queue test_priority_queue.c)
target_link_libraries(test_priority_queue priority_queue)
