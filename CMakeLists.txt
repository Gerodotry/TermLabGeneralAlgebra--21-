cmake_minimum_required(VERSION 3.23)
project(Lab)

set(CMAKE_CXX_STANDARD 17)

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
        headers/GUI/algorithms/VectorMultiplicationAlgorithm.h
        headers/GUI/algorithms/NumberAdditionAlgorithm.h
        sources/GUI/algorithms/NumberAdditionAlgorithm.cpp
        headers/GUI/algorithms/NumberSubtractionAlgorithm.h
        sources/GUI/algorithms/NumberSubtractionAlgorithm.cpp
        headers/GUI/algorithms/NumberMultiplicationAlgorithm.h
        sources/GUI/algorithms/NumberMultiplicationAlgorithm.cpp
        headers/GUI/algorithms/PolynomialAdditionAlgorithm.h
        sources/GUI/algorithms/PolynomialAdditionAlgorithm.cpp
        headers/GUI/algorithms/PolynomialSubtractionAlgorithm.h
        sources/GUI/algorithms/PolynomialSubtractionAlgorithm.cpp
        headers/GUI/algorithms/PolynomialMultiplicationAlgorithm.h
        sources/GUI/algorithms/PolynomialMultiplicationAlgorithm.cpp
        headers/GUI/algorithms/NumberGCDAlgorithm.h
        sources/GUI/algorithms/NumberGCDAlgorithm.cpp
        headers/GUI/algorithms/NumberDivisionAlgorithm.h
        sources/GUI/algorithms/NumberDivisionAlgorithm.cpp
        headers/GUI/algorithms/NumberRemainderAlgorithm.h
        sources/GUI/algorithms/NumberRemainderAlgorithm.cpp
        headers/algorithms/NumberMultiplication.h
        headers/algorithms/NumberAddition.h
        headers/utils/Number.h
        headers/utils/Polynomial.h
        sources/utils/Polynomial.cpp
        headers/algorithms/NumberSubtraction.h
        headers/algorithms/NumberGCD.h
        sources/algorithms/NumberGCD.cpp
        sources/algorithms/NumberRemainder.cpp
        headers/algorithms/NumberRemainder.h
        sources/algorithms/NumberDivision.cpp
        headers/algorithms/NumberDivision.h
        headers/algorithms/NumberSubtraction.h
        sources/utils/Number.cpp
        sources/algorithms/NumberAddition.cpp
        sources/algorithms/NumberMultiplication.cpp
        sources/algorithms/NumberSubtraction.cpp
        sources/utils/RingPolynomial.cpp
        headers/utils/RingPolynomial.h
        sources/utils/FieldPolynomial.cpp
        headers/utils/FieldPolynomial.h
        sources/utils/PolynomialTerm.cpp
        headers/utils/PolynomialTerm.h
        headers/algorithms/RingPolynomialAddition.h
        sources/algorithms/RingPolynomialAddition.cpp
        sources/algorithms/RingPolynomialSubtraction.cpp
        headers/algorithms/RingPolynomialSubtraction.h
        sources/algorithms/RingPolynomialMultiplication.cpp
        headers/algorithms/RingPolynomialMultiplication.h
        headers/GUI/inputComponents/NumberInputComponent.h
        sources/GUI/inputComponents/NumberInputComponent.cpp
        headers/GUI/inputComponents/PolynomialInputComponent.h
        sources/GUI/inputComponents/PolynomialInputComponent.cpp
        sources/GUI/inputComponents/IntInputComponent.cpp
        headers/GUI/inputComponents/IntInputComponent.h
        sources/utils/Int.cpp
        headers/utils/Int.h
        sources/algorithms/MillerRabinTest.cpp tests/MillerRabinTestTests.cpp  headers/algorithms/Gcd.h sources/algorithms/Gcd.cpp sources/algorithms/Gcd.cpp tests/GcdTests.cpp sources/algorithms/Remainder.cpp headers/algorithms/Remainder.h sources/algorithms/Division.cpp headers/algorithms/Division.h sources/utils/BigInt.cpp       )

include_directories(h headers)
include_directories(ImGui imgui)

find_package( OpenGL REQUIRED )

add_subdirectory(${PROJECT_SOURCE_DIR}/glew/build/cmake)
add_subdirectory(${PROJECT_SOURCE_DIR}/glfw)


target_include_directories(Lab PRIVATE ${PROJECT_SOURCE_DIR}/glew/include)

target_link_libraries(Lab glfw glew)