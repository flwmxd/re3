//////////////////////////////////////////////////////////////////////////////
// This file is part of the Maple Engine                              		//
//////////////////////////////////////////////////////////////////////////////

#pragma once
#include <memory>

namespace maple
{
	class ImGuiRenderer
	{
	  public:
		static auto create(uint32_t width, uint32_t height, bool clearScreen) -> std::shared_ptr<ImGuiRenderer>;

		virtual ~ImGuiRenderer()                                       = default;
		virtual auto init(void * ptr) -> void                                    = 0;
		virtual auto newFrame(float dt) -> void              = 0;
		virtual auto render() -> void      = 0;
		virtual auto onResize(uint32_t width, uint32_t height) -> void = 0;
		virtual auto rebuildFontTexture() -> void                      = 0;
		virtual auto clear() -> void
		{}
	};
}        // namespace maple
