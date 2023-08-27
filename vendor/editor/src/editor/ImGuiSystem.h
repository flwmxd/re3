//////////////////////////////////////////////////////////////////////////////
// This file is part of the Maple Engine                              		//
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include <memory>

namespace maple
{
	class ImGuiRenderer;
	class ImGuiSystem
	{
	public:
		using Ptr = std::shared_ptr<ImGuiSystem>;
		ImGuiSystem(bool clearScreen = false);
		~ImGuiSystem();
		auto newFrame(float dt) -> void;
		auto onInit(uint32_t width, uint32_t height, void* ptr) -> void;
		auto onRender() -> void;
		auto addIcon() -> void;
		auto onResize(uint32_t w, uint32_t h) -> void;
		auto setTheme() -> void;
		auto update() -> void;
		bool isHoldingMouse() const;
		static auto instance()->Ptr;
	private:
		bool                           clearScreen = false;
		std::shared_ptr<ImGuiRenderer> imguiRender;
	};
}        // namespace maple