//////////////////////////////////////////////////////////////////////////////
// This file is part of the Maple Engine                              		//
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>

namespace maple
{
	namespace ImNotification
	{
		enum class Type
		{
			None,
			Success,
			Warning,
			Error,
			Info
		};

		auto onImGui() -> void;
		auto makeNotification(const std::string& title, const std::string& str, const Type type) -> void;
	};        // namespace ImNotification
};            // namespace maple
