#pragma once

#include "cwpch.h"

#include "Crown/Core.h"
#include "Crown/Events/Event.h"

namespace Crown
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Crown Engine", unsigned int width = 1280, unsigned int height = 720)
			:Title(title), Width(width), Height(height) {}
	};

	class CROWN_API Window
	{
	public:
		virtual ~Window() {};

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const std::function<void(Event&)> callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}