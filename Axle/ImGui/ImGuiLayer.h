#pragma once
#include "Layer.h"

namespace Axle
{
	class AXLE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;
		void OnDetach() override;

	private:

	};
}