//////////////////////////////////////////////////////////////////////////////
// This file is part of the Maple Engine                              		//
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ImGuiRenderer.h"

namespace maple
{
	class GLImGuiRenderer : public ImGuiRenderer
	{
	  public:
		GLImGuiRenderer(uint32_t width, uint32_t height, bool clearScreen);
		~GLImGuiRenderer();

		auto init(void * ptr) -> void override;
		auto newFrame(float dt) -> void override;
		auto render() -> void override;
		auto onResize(uint32_t width, uint32_t height) -> void override;
		auto rebuildFontTexture() -> void override;

	  private:
		void *windowHandle = nullptr;
		bool  clearScreen  = false;
	};
}        // namespace maple
