#include"headers/utils/PreprocessorMainDirectives.h"
#ifdef MAIN


#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "GUI/Windows.h"
#include "algorithms/VectorMultiplication.h"
#include "GUI/algorithms/NumberAdditionAlgorithm.h"
#include "GUI/algorithms/NumberSubtractionAlgorithm.h"
#include "GUI/algorithms/NumberMultiplicationAlgorithm.h"
#include "GUI/algorithms/NumberGCDAlgorithm.h"
#include "GUI/algorithms/NumberDivisionAlgorithm.h"
#include "GUI/algorithms/NumberRemainderAlgorithm.h"
#include "GUI/algorithms/PolynomialAdditionAlgorithm.h"
#include "GUI/algorithms/PolynomialSubtractionAlgorithm.h"
#include "GUI/algorithms/PolynomialMultiplicationAlgorithm.h"
#include <stdio.h>
#include <GLFW/glfw3.h>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "glfw Error %d: %s\n", error, description);
}

int main(int, char**)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) {
        return 1;
    }

    const char* glsl_version = "#version 330";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Lab", NULL, NULL);
    if (window == NULL) {
        return 1;
    }
    glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    Windows Windows;

    Windows.addAlgorithm<NumberAdditionAlgorithm>("Numbers");
    Windows.addAlgorithm<NumberSubtractionAlgorithm>("Numbers");
    Windows.addAlgorithm<NumberMultiplicationAlgorithm>("Numbers");
    Windows.addAlgorithm<NumberGCDAlgorithm>("Numbers");
    Windows.addAlgorithm<NumberDivisionAlgorithm>("Numbers");
    Windows.addAlgorithm<NumberRemainderAlgorithm>("Numbers");

    Windows.addAlgorithm<PolynomialAdditionAlgorithm>("RingPolynomial");
    Windows.addAlgorithm<PolynomialSubtractionAlgorithm>("RingPolynomial");
    Windows.addAlgorithm<PolynomialMultiplicationAlgorithm>("RingPolynomial");

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();

        ImGui::NewFrame();

        Windows.update();

        ImGui::Render();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);

        glViewport(0, 0, display_w, display_h);

        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);

        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
/*
#include <iostream>
#include "algorithms/MillerRabinTest.h"
#include "algorithms/Gcd.h"
#include "algorithms/Remainder.h"
#include "algorithms/Division.h"
#include <cmath>
#include <vector>

using namespace std;



int main() {
    //unsigned int k = 8;  // Number of iterations
    //BigInt n = 87178291199;

    //if (MillerRabinTest::run(n, k))
    //     cout <<"Number "<< n<<" is prime\n";  
    //else
    //    cout << "Number " << n << " is not prime\n";

    vector<int> a = {3, 0, 0, 0, 2, 1, 5};
    vector<int> b = {6, 1, 0, 2, 4};
    int mod = 7;
    vector<int> g = Gcd::run(a, b, mod);
    vector<int> remainder = Remainder::run(a, b, mod);
    vector<int> div = Division::run(a, b, mod);
    cout << "Gcd(";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << "x^" << a.size() - i - 1;
        if (i < a.size() - 1) cout << " + ";
    }
    cout << ", ";
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << "x^" << b.size() - i - 1;
        if (i < b.size() - 1) cout << " + ";
    }
    cout << ") = ";
    for (int i = 0; i < g.size(); i++) {
        cout << g[i] << "x^" << g.size() - i - 1;
        if (i < g.size() - 1) cout << " + ";
    }
    cout << endl;

    cout << "Remainder: ";
    for (int i = 0; i < remainder.size(); i++) {
        cout << remainder[i] << "x^" << remainder.size() - i - 1;
        if (i < remainder.size() - 1) cout << " + ";
    }
    cout << endl;

    cout << "Division result: ";
    for (int i = 0; i < div.size(); i++) {
        cout << div[i] << "x^" << div.size() - i - 1;
        if (i < div.size() - 1) cout << " + ";
    }
    cout << endl;

    return 0;
}
*/
#endif
