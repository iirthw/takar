#pragma once

#include <memory>
#include <vector>

#include "rendering/renderable.h"

namespace tkr {
	class Node {
	public:
		Node() = default;
		Node(std::shared_ptr<Renderable> renderable);

		const std::vector<std::shared_ptr<Renderable>>& 
			renderables() const { return mRenderables; }

	private:
		std::vector<std::shared_ptr<Renderable>> mRenderables;
	}; // class Node
} // namespace tkr