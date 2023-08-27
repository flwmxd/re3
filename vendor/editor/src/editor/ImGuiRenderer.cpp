//////////////////////////////////////////////////////////////////////////////
// This file is part of the Maple Engine                              		//
//////////////////////////////////////////////////////////////////////////////
#include "ImGuiRenderer.h"
#include "GLImGuiRenderer.h"
namespace maple
{

	auto ImGuiRenderer::create(uint32_t width, uint32_t height, bool clearScreen) -> std::shared_ptr<ImGuiRenderer>
	{
		return std::make_shared<GLImGuiRenderer>(width,height,clearScreen);
	}
}        // namespace maple
