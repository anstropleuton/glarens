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

            set(ASSETS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${example_dir}/assets")

            if (EXISTS "${ASSETS_DIR}")
                add_custom_command(
                    TARGET ${example_target}
                    POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory
                            "${ASSETS_DIR}"
                            "$<TARGET_FILE_DIR:${example_target}>/assets"
                    COMMENT "Copying assets for ${example_target}"
                )

                file(GLOB_RECURSE SHADERS
                    "${ASSETS_DIR}/*.vert.hlsl"
                    "${ASSETS_DIR}/*.frag.hlsl"
                )

                foreach(shader_src ${SHADERS})
                    file(RELATIVE_PATH shader_rel "${ASSETS_DIR}" "${shader_src}")

                    string(REGEX REPLACE "\\.hlsl$" "" shader_rel_base "${shader_rel}")

                    set(shader_dest
                        "$<TARGET_FILE_DIR:${example_target}>/assets/${shader_rel_base}"
                    )

                    compile_shader(
                        TARGET ${example_target}
                        SOURCE "${shader_src}"
                        DEST   "${shader_dest}"
                    )
                endforeach()
            endif()
        endif()
    endif()
endforeach()
