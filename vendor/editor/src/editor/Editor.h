//////////////////////////////////////////////////////////////////////////////
// This file is part of the Maple Engine                              		//
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace maple
{
	class Editor
	{
	public:
		using Ptr = std::shared_ptr<Editor>;
		auto drawMenu() -> void;
		auto beginDockSpace() -> void;
		auto endDockSpace() -> void;

		static auto instance()->Ptr;
	};
}