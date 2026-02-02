find_program(SH_COMPILER NAMES shadercross shadercross.exe)
if(NOT SH_COMPILER)
    message(FATAL_ERROR "shadercross not found")
endif()

function(compile_shader)
    cmake_parse_arguments(CS "" "TARGET;SOURCE;DEST" "" ${ARGN})

    if(NOT CS_TARGET OR NOT CS_SOURCE OR NOT CS_DEST)
        message(FATAL_ERROR
            "compile_shader requires TARGET, SOURCE, and DEST")
    endif()

    get_filename_component(shader_src "${CS_SOURCE}" ABSOLUTE)

    if(shader_src MATCHES "\\.vert\\.hlsl$")
        set(stage "vertex")
    elseif(shader_src MATCHES "\\.frag\\.hlsl$")
        set(stage "fragment")
    else()
        message(FATAL_ERROR
            "compile_shader: shader must end with .vert.hlsl or .frag.hlsl: ${CS_SOURCE}")
    endif()

    set(out_spv  "${CS_DEST}.spv")
    set(out_msl  "${CS_DEST}.msl")
    set(out_dxil "${CS_DEST}.dxil")

    get_filename_component(out_dir "${out_spv}" DIRECTORY)

    add_custom_command(
        TARGET ${CS_TARGET}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${out_dir}"
        COMMAND "${SH_COMPILER}" "${shader_src}" -t ${stage} -d SPIRV -o "${out_spv}"
        COMMAND "${SH_COMPILER}" "${shader_src}" -t ${stage} -d MSL   -o "${out_msl}"
        COMMAND "${SH_COMPILER}" "${shader_src}" -t ${stage} -d DXIL  -o "${out_dxil}"
        COMMENT "Compiling shader ${shader_src}"
        VERBATIM
    )
endfunction()
