#include "TriangleRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "RendererManager.h"

void TriangleRenderer::Render()
{
	RendererManager::Instance()->GetRenderer()->
		Render2DTriangle(p_GameObject->p_Transform->position, p_GameObject->p_Transform->scale);
}
