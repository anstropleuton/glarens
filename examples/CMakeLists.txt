file(GLOB EXAMPLE_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *)

foreach(example_dir ${EXAMPLE_DIRS})
    if (IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${example_dir}")
        file(GLOB_RECURSE EXAMPLE_SOURCES CONFIGURE_DEPENDS
            ${example_dir}/*.cpp
        )

        if (EXAMPLE_SOURCES)
            set(example_target "glarens_example_${example_dir}")

            add_executable(${example_target} ${EXAMPLE_SOURCES})

            target_include_directories(${example_target}
                PRIVATE
                    ${example_dir}
            )

            target_link_libraries(${example_target}
                PRIVATE
                    glarens::glarens
            )
        endif()
    endif()
endforeach()
