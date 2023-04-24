cmake_minimum_required(VERSION 3.23)
project(Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab main.cpp
        sources/algorithms/VectorMultiplication.cpp headers/algorithms/VectorMultiplication.h
        imgui/imgui.h imgui/imgui.cpp
        imgui/imconfig.h
        imgui/imgui_impl_glfw.h imgui/imgui_impl_glfw.cpp
        imgui/imgui_internal.h
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/imstb_truetype.h
        imgui/imstb_textedit.h
        imgui/imstb_rectpack.h
        imgui/imgui_draw.cpp
        imgui/imgui_impl_opengl3.cpp
        imgui/imgui_impl_opengl3.h
        imgui/imgui_impl_opengl3_loader.h
        imgui/imgui_demo.cpp headers/utils/Object.h
        sources/GUI/inputComponents/InputComponent.cpp
        headers/GUI/inputComponents/InputComponent.h
        sources/GUI/inputComponents/VectorInputComponent.cpp
        headers/GUI/inputComponents/VectorInputComponent.h
        sources/utils/Float.cpp headers/utils/Float.h
        sources/utils/Vector.cpp headers/utils/Vector.h
        sources/GUI/Windows.cpp headers/GUI/Windows.h
        headers/GUI/algorithms/Algorithm.h
        sources/GUI/algorithms/VectorMultiplicationAlgorithm.cpp
        headers/GUI/algorithms/VectorMultiplicationAlgorithm.h)

include_directories(h headers)
include_directories(ImGui imgui)

find_package( OpenGL REQUIRED )

add_subdirectory(${PROJECT_SOURCE_DIR}/glew/build/cmake)
add_subdirectory(${PROJECT_SOURCE_DIR}/glfw)


target_include_directories(Lab PRIVATE ${PROJECT_SOURCE_DIR}/glew/include)

target_link_libraries(Lab glfw glew)
