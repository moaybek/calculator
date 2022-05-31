#include "Calculator_Application.h"

#include "imgui.h"
#include <string>

const char* calculatorLayOut[] = { "7", "8", "9", "4", "5", "6", "1", "2", "3", " ", "0", " "};


namespace Calculator_Application {

    //Rendering function of the calculator app

    void Render_CalculatorUI() {

        static const char* calculatorOutput = "0";

        ImGui::Begin("MyCalculator by Onur Aybek");
        ImGui::TextWrapped(calculatorOutput);

        for (int i = 0; i < 12; i++) {

            if (i % 3) {
                ImGui::SameLine();
            }

            ImGui::PushID(i);
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.96f, 0.87f, 0.25f, 0.8f));
            if (ImGui::Button(calculatorLayOut[i]))
                calculatorOutput = calculatorLayOut[i];
            ImGui::PopStyleColor(1);
            ImGui::PopID();
        }
        ImGui::End();
    }
}