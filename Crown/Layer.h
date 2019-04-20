#pragma once

#include "Crown/Core.h"
#include "Crown/Events/Event.h"

namespace Crown {

	class CROWN_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		const char* m_DebugName;
	};

}