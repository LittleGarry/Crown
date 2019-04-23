#include "cwpch.h"
#include "LayerStack.h"

namespace Crown {
	
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}


	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}


	void LayerStack::PushLayer(Layer* layer)
	{

	}


	void LayerStack::PushOverlay(Layer* overlay)
	{

	}


	void LayerStack::PopLayer(Layer* layer)
	{

	}


	void LayerStack::PopOverlay(Layer* overlay)
	{

	}

}