include(FetchContent)

find_package(doctest REQUIRED)

file(GLOB TEST_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

foreach(test_dir ${TEST_DIRS})
    if (IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${test_dir}")
        file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
            ${test_dir}/*.cpp
        )

        if (TEST_SOURCES)
            set(test_target "glarens_test_${test_dir}")

            add_executable(${test_target} ${TEST_SOURCES})

            target_include_directories(${test_target}
                PRIVATE
                    ${test_dir}
            )

            target_link_libraries(${test_target}
                PRIVATE
                    glarens::glarens
                    doctest::doctest
            )

            add_test(
                NAME ${test_target}
                COMMAND ${test_target}
            )
        endif()
    endif()
endforeach()
