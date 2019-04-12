#pragma once

#include "Event.h"

#include <sstream>

namespace Crown {

	class CROWN_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard);
	protected:
		KeyEvent(int keyCode)
			: m_KeyCode(keyCode) {}

		int m_KeyCode;
	};

	class CROWN_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats";

			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class CROWN_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;

			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}