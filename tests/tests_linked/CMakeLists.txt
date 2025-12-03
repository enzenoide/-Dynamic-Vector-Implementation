
set(TESTS 01 02 03 04 05 06)

# Teste de push back
add_executable(test_linked_push_back
    test_linked_push_back.cpp)
include_directories(test_linked_push_back
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_push_back vector-lib)

foreach(test_number ${TESTS})

    add_test(NAME LinkedPushBack${test_number}
        COMMAND $<TARGET_FILE:test_linked_push_back>
        ${CMAKE_SOURCE_DIR}/tests/inputs/input-${test_number}.txt)

    set_tests_properties(LinkedPushBack${test_number}
        PROPERTIES
        TIMEOUT 2
    )

endforeach(test_number ${TESTS})


# Teste de push front
add_executable(test_linked_push_front
    test_linked_push_front.cpp)
include_directories(test_linked_push_front
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_push_front vector-lib)

foreach(test_number ${TESTS})

    add_test(NAME LinkedPushFront${test_number}
        COMMAND $<TARGET_FILE:test_linked_push_front>
        ${CMAKE_SOURCE_DIR}/tests/inputs/input-${test_number}.txt)

    set_tests_properties(LinkedPushFront${test_number}
        PROPERTIES
        TIMEOUT 20 # Aumentado o timeout para testes que envolvem push front
    )

endforeach(test_number ${TESTS})


# Teste de pop back
add_executable(test_linked_pop_back
    test_linked_pop_back.cpp)
include_directories(test_linked_pop_back
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_pop_back vector-lib)

foreach(test_number ${TESTS})

    add_test(NAME LinkedPopBack${test_number}
        COMMAND $<TARGET_FILE:test_linked_pop_back>
        ${CMAKE_SOURCE_DIR}/tests/inputs/input-${test_number}.txt)

    set_tests_properties(LinkedPopBack${test_number}
        PROPERTIES
        TIMEOUT 2
    )

endforeach(test_number ${TESTS})


# Teste de pop front
add_executable(test_linked_pop_front
    test_linked_pop_back.cpp)
include_directories(test_linked_pop_front
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_pop_front vector-lib)

foreach(test_number ${TESTS})

    add_test(NAME LinkedPopFront${test_number}
        COMMAND $<TARGET_FILE:test_linked_pop_front>
        ${CMAKE_SOURCE_DIR}/tests/inputs/input-${test_number}.txt)

    set_tests_properties(LinkedPopFront${test_number}
        PROPERTIES
        TIMEOUT 8
    )

endforeach(test_number ${TESTS})

# Teste do get_at
add_executable(test_linked_get_at
    test_linked_get_at.cpp)
include_directories(test_linked_get_at
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_get_at vector-lib)

add_test(NAME LinkedGetAt
    COMMAND $<TARGET_FILE:test_linked_get_at>)

set_tests_properties(LinkedGetAt
    PROPERTIES
    TIMEOUT 2
)

# Teste do insert_at
add_executable(test_linked_insert_at
    test_linked_insert_at.cpp)
include_directories(test_linked_insert_at
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_insert_at vector-lib)

add_test(NAME LinkedInsertAt
    COMMAND $<TARGET_FILE:test_linked_insert_at>)

set_tests_properties(LinkedInsertAt
    PROPERTIES
    TIMEOUT 2
)

# Teste do remove_at
add_executable(test_linked_remove_at
    test_linked_remove_at.cpp)
include_directories(test_linked_remove_at
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_remove_at vector-lib)

add_test(NAME LinkedRemoveAt
    COMMAND $<TARGET_FILE:test_linked_remove_at>)

set_tests_properties(LinkedRemoveAt
    PROPERTIES
    TIMEOUT 2
)
# Teste do clear
add_executable(test_linked_clear
    test_linked_clear.cpp)
include_directories(test_linked_clear
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_clear vector-lib)

add_test(NAME LinkedClear
    COMMAND $<TARGET_FILE:test_linked_clear>)

set_tests_properties(LinkedClear
    PROPERTIES
    TIMEOUT 2
)

# Teste do front
add_executable(test_linked_front
    test_linked_front.cpp)
include_directories(test_linked_front
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_front vector-lib)

add_test(NAME LinkedFront
    COMMAND $<TARGET_FILE:test_linked_front>)

set_tests_properties(LinkedFront
    PROPERTIES
    TIMEOUT 2
)

# Teste do back
add_executable(test_linked_back
    test_linked_back.cpp)
include_directories(test_linked_back
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_back vector-lib)

add_test(NAME LinkedBack
    COMMAND $<TARGET_FILE:test_linked_back>)

set_tests_properties(LinkedBack
    PROPERTIES
    TIMEOUT 2
)

# Teste do remove
add_executable(test_linked_remove
    test_linked_remove.cpp)
include_directories(test_linked_remove
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_remove vector-lib)

add_test(NAME LinkedRemove
    COMMAND $<TARGET_FILE:test_linked_remove>)

set_tests_properties(LinkedRemove
    PROPERTIES
    TIMEOUT 2
)

# Teste do find

add_executable(test_linked_find
    test_linked_find.cpp)
include_directories(test_linked_find
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_find vector-lib)

add_test(NAME LinkedFind
    COMMAND $<TARGET_FILE:test_linked_find>)

set_tests_properties(LinkedFind
    PROPERTIES
    TIMEOUT 2
)

# Teste do count

add_executable(test_linked_count
    test_linked_count.cpp)
include_directories(test_linked_count
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_count vector-lib)

add_test(NAME LinkedCount
    COMMAND $<TARGET_FILE:test_linked_count>)

set_tests_properties(LinkedCount
    PROPERTIES
    TIMEOUT 2
)

# Teste do sum

add_executable(test_linked_sum
    test_linked_sum.cpp)
include_directories(test_linked_sum
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_sum vector-lib)

add_test(NAME LinkedSum
    COMMAND $<TARGET_FILE:test_linked_sum>)

set_tests_properties(LinkedSum
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

add_executable(test_linked_memory_leak_ok
    test_linked_memory_leak_ok.cpp)
include_directories(test_linked_memory_leak_ok
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_memory_leak_ok vector-lib)

add_test(NAME LinkedMemoryLeakOk
    COMMAND ${CMAKE_MEMORYCHECK_COMMAND}
    ${CMAKE_MEMORYCHECK_COMMAND_OPTIONS}
    --log-file=valgrind-linked-ok-out.txt
    $<TARGET_FILE:test_linked_memory_leak_ok>)
set_tests_properties(LinkedMemoryLeakOk
    PROPERTIES
    TIMEOUT 8
)

add_executable(test_linked_memory_leak_fail
    test_linked_memory_leak_fail.cpp)
include_directories(test_linked_memory_leak_fail
    ${CMAKE_SOURCE_DIR}/include/vector-lib)
target_link_libraries(test_linked_memory_leak_fail vector-lib)

add_test(NAME LinkedMemoryLeakFail
    COMMAND ${CMAKE_MEMORYCHECK_COMMAND} ${CMAKE_MEMORYCHECK_COMMAND_OPTIONS}
    --log-file=valgrind-linked-fail-out.txt $<TARGET_FILE:test_linked_memory_leak_fail>)

set_tests_properties(LinkedMemoryLeakFail
    PROPERTIES
    WILL_FAIL true
    TIMEOUT 8)

