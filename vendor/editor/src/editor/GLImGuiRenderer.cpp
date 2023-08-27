//////////////////////////////////////////////////////////////////////////////
// This file is part of the Maple Engine                              		//
//////////////////////////////////////////////////////////////////////////////

#include "GLImGuiRenderer.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

namespace maple
{
	GLImGuiRenderer::GLImGuiRenderer(uint32_t width, uint32_t height, bool clearScreen) :
	    clearScreen(clearScreen)
	{
	}

	GLImGuiRenderer::~GLImGuiRenderer()
	{
		ImGui_ImplOpenGL3_Shutdown();
	}

	auto GLImGuiRenderer::init(void *ptr) -> void
	{
		windowHandle = ptr;
		ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)ptr,true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	auto GLImGuiRenderer::newFrame(float dt) -> void
	{
		ImGuiIO &io  = ImGui::GetIO();
		io.DeltaTime = dt;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	auto GLImGuiRenderer::render() -> void
	{
		
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow *backupCurrentContext = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backupCurrentContext);
		}
	}

	auto GLImGuiRenderer::onResize(uint32_t width, uint32_t height) -> void
	{
	}

	auto GLImGuiRenderer::rebuildFontTexture() -> void
	{
		ImGui_ImplOpenGL3_DestroyFontsTexture();
		ImGui_ImplOpenGL3_CreateFontsTexture();
	}
}        // namespace maple
