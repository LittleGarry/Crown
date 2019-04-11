#pragma once

#include "Crown/Core.h"

#include <string>

namespace Crown {

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput		 = BIT(1),
		EventCategoryKeyboard	 = BIT(2),
		EventCategoryMouse		 = BIT(3),
		EventCategoryMouseButton = BIT(4),
	};

#define EVENT_CLASS_TYPE(type) virtual EventType GetEventType() const override { return EventType::##type; }\
							   virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags const override { return category; }

	class CROWN_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetEventCategory() & category;
		}

	protected:
		bool m_Handled = false;
	};

}