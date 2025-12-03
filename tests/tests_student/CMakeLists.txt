
file(GLOB SOURCES "*.cpp")
foreach(test_source ${SOURCES})
    cmake_path(GET test_source STEM test_exe)
    add_executable(${test_exe}
        ${test_source})
    include_directories(${test_exe}
        ${CMAKE_SOURCE_DIR}/include/vector-lib)
    target_link_libraries(${test_exe} vector-lib)

    add_test(NAME ${test_exe}
        COMMAND $<TARGET_FILE:${test_exe}>)

    set_tests_properties(${test_exe}
        PROPERTIES
        TIMEOUT 10
    )

endforeach(test_source ${SOURCES})

