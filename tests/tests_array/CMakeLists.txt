
set(TESTS 01 02 03 04 05 06)

# Teste de push back
add_executable(test_array_push_back
    test_array_push_back.cpp)
include_directories(test_array_push_back
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_push_back vector-lib)

foreach(test_number ${TESTS})

    add_test(NAME ArrayPushBack${test_number}
        COMMAND $<TARGET_FILE:test_array_push_back>
        ${CMAKE_SOURCE_DIR}/tests/inputs/input-${test_number}.txt)

    set_tests_properties(ArrayPushBack${test_number}
        PROPERTIES
        TIMEOUT 2
    )

endforeach(test_number ${TESTS})


# Teste de push front
add_executable(test_array_push_front
    test_array_push_front.cpp)
include_directories(test_array_push_front
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_push_front vector-lib)

foreach(test_number ${TESTS})

    add_test(NAME ArrayPushFront${test_number}
        COMMAND $<TARGET_FILE:test_array_push_front>
        ${CMAKE_SOURCE_DIR}/tests/inputs/input-${test_number}.txt)

    set_tests_properties(ArrayPushFront${test_number}
        PROPERTIES
        TIMEOUT 20 # Aumentado o timeout para testes que envolvem push front
    )

endforeach(test_number ${TESTS})


# Teste de pop back
add_executable(test_array_pop_back
    test_array_pop_back.cpp)
include_directories(test_array_pop_back
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_pop_back vector-lib)

foreach(test_number ${TESTS})

    add_test(NAME ArrayPopBack${test_number}
        COMMAND $<TARGET_FILE:test_array_pop_back>
        ${CMAKE_SOURCE_DIR}/tests/inputs/input-${test_number}.txt)

    set_tests_properties(ArrayPopBack${test_number}
        PROPERTIES
        TIMEOUT 2
    )

endforeach(test_number ${TESTS})


# Teste de pop front
add_executable(test_array_pop_front
    test_array_pop_back.cpp)
include_directories(test_array_pop_front
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_pop_front vector-lib)

foreach(test_number ${TESTS})

    add_test(NAME ArrayPopFront${test_number}
        COMMAND $<TARGET_FILE:test_array_pop_front>
        ${CMAKE_SOURCE_DIR}/tests/inputs/input-${test_number}.txt)

    set_tests_properties(ArrayPopFront${test_number}
        PROPERTIES
        TIMEOUT 8
    )

endforeach(test_number ${TESTS})

# Teste do get_at
add_executable(test_array_get_at
    test_array_get_at.cpp)
include_directories(test_array_get_at
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_get_at vector-lib)

add_test(NAME ArrayGetAt
    COMMAND $<TARGET_FILE:test_array_get_at>)

set_tests_properties(ArrayGetAt
    PROPERTIES
    TIMEOUT 2
)

# Teste do insert_at
add_executable(test_array_insert_at
    test_array_insert_at.cpp)
include_directories(test_array_insert_at
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_insert_at vector-lib)

add_test(NAME ArrayInsertAt
    COMMAND $<TARGET_FILE:test_array_insert_at>)

set_tests_properties(ArrayInsertAt
    PROPERTIES
    TIMEOUT 2
)

# Teste do remove_at
add_executable(test_array_remove_at
    test_array_remove_at.cpp)
include_directories(test_array_remove_at
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_remove_at vector-lib)

add_test(NAME ArrayRemoveAt
    COMMAND $<TARGET_FILE:test_array_remove_at>)

set_tests_properties(ArrayRemoveAt
    PROPERTIES
    TIMEOUT 2
)
# Teste do clear
add_executable(test_array_clear
    test_array_clear.cpp)
include_directories(test_array_clear
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_clear vector-lib)

add_test(NAME ArrayClear
    COMMAND $<TARGET_FILE:test_array_clear>)

set_tests_properties(ArrayClear
    PROPERTIES
    TIMEOUT 2
)

# Teste do front
add_executable(test_array_front
    test_array_front.cpp)
include_directories(test_array_front
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_front vector-lib)

add_test(NAME ArrayFront
    COMMAND $<TARGET_FILE:test_array_front>)

set_tests_properties(ArrayFront
    PROPERTIES
    TIMEOUT 2
)

# Teste do back
add_executable(test_array_back
    test_array_back.cpp)
include_directories(test_array_back
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_back vector-lib)

add_test(NAME ArrayBack
    COMMAND $<TARGET_FILE:test_array_back>)

set_tests_properties(ArrayBack
    PROPERTIES
    TIMEOUT 2
)

# Teste do remove
add_executable(test_array_remove
    test_array_remove.cpp)
include_directories(test_array_remove
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_remove vector-lib)

add_test(NAME ArrayRemove
    COMMAND $<TARGET_FILE:test_array_remove>)

set_tests_properties(ArrayRemove
    PROPERTIES
    TIMEOUT 2
)

# Teste do find

add_executable(test_array_find
    test_array_find.cpp)
include_directories(test_array_find
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_find vector-lib)

add_test(NAME ArrayFind
    COMMAND $<TARGET_FILE:test_array_find>)

set_tests_properties(ArrayFind
    PROPERTIES
    TIMEOUT 2
)

# Teste do count

add_executable(test_array_count
    test_array_count.cpp)
include_directories(test_array_count
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_count vector-lib)

add_test(NAME ArrayCount
    COMMAND $<TARGET_FILE:test_array_count>)

set_tests_properties(ArrayCount
    PROPERTIES
    TIMEOUT 2
)

# Teste do sum

add_executable(test_array_sum
    test_array_sum.cpp)
include_directories(test_array_sum
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_sum vector-lib)

add_test(NAME ArraySum
    COMMAND $<TARGET_FILE:test_array_sum>)

set_tests_properties(ArraySum
    PROPERTIES
    TIMEOUT 2
)

# Testes de vazamento de memória com valgrind
set(CMAKE_MEMORYCHECK_COMMAND "valgrind")
set(CMAKE_MEMORYCHECK_COMMAND_OPTIONS
    --leak-check=full
    --show-leak-kinds=all
    --error-exitcode=1
    --verbose)

add_executable(test_array_memory_leak_ok
    test_array_memory_leak_ok.cpp)
include_directories(test_array_memory_leak_ok
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_memory_leak_ok vector-lib)

add_test(NAME ArrayMemoryLeakOk
    COMMAND ${CMAKE_MEMORYCHECK_COMMAND}
    ${CMAKE_MEMORYCHECK_COMMAND_OPTIONS}
    --log-file=valgrind-array-ok-out.txt
    $<TARGET_FILE:test_array_memory_leak_ok>)
set_tests_properties(ArrayMemoryLeakOk
    PROPERTIES
    TIMEOUT 8
)

add_executable(test_array_memory_leak_fail
    test_array_memory_leak_fail.cpp)
include_directories(test_array_memory_leak_fail
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_array_memory_leak_fail vector-lib)

add_test(NAME ArrayMemoryLeakFail
    COMMAND ${CMAKE_MEMORYCHECK_COMMAND} ${CMAKE_MEMORYCHECK_COMMAND_OPTIONS}
    --log-file=valgrind-array-fail-out.txt $<TARGET_FILE:test_array_memory_leak_fail>)

set_tests_properties(ArrayMemoryLeakFail
    PROPERTIES
    WILL_FAIL true
    TIMEOUT 8)

