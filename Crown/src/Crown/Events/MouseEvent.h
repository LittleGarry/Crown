#pragma once

#include "Event.h"

#include <sstream>

namespace Crown {

	class CROWN_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}
		
		inline float GetX() { return m_MouseX; }
		inline float GetY() { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;

			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	protected:
		float m_MouseX, m_MouseY;
	};

	class CROWN_API MouseScrolledEvent : public Event
	{
	public:
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse)
	protected:
	};

	class CROWN_API MouseButtonEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouseButton)
	protected:
	};

	class CROWN_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		EVENT_CLASS_TYPE(MouseButtonPressed)
	protected:
	};

	class CROWN_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		EVENT_CLASS_TYPE(MouseButtonReleased)
	protected:
	};
}