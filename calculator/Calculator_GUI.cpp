#include "Calculator_GUI.h"

#include "imgui.h"
#include <string>

const char* calculatorLayOut[16] = {"7", "8", "9", "X", "4", "5", "6", "-", "1", "2", "3", "+", "C", "0", ".", "="};


namespace Calculator_GUI {

    //Rendering function of the calculator app

    void Render_CalculatorUI() {

        static std::string calculatorOutput = "0";

        ImGui::Begin("MyCalculator by Onur Aybek", NULL,ImGuiWindowFlags_NoResize);
        ImGui::TextWrapped(calculatorOutput.c_str());

        for (int i = 0; i < 16; i++) {

            if (i % 4) {
                ImGui::SameLine();
            }

            ImGui::PushID(i);
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.96f, 0.87f, 0.25f, 0.8f));
            if (ImGui::Button(calculatorLayOut[i], ImVec2(30.0f, 30.0f))) {
                if (calculatorOutput.compare("0") == 0) {
                    calculatorOutput = "";
                }

                if (calculatorLayOut[i] == "C") {
                    calculatorOutput = "0";
                }
                else {
                    calculatorOutput += calculatorLayOut[i];
                }
            }
            ImGui::PopStyleColor(1);
            ImGui::PopID();
        }
        ImGui::End();
    }
}