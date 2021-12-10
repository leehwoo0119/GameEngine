#include "CircleRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "RendererManager.h"

void CircleRenderer::Render()
{
	RendererManager::Instance()->GetRenderer()->
		Render2DCircle(p_GameObject->p_Transform->position, p_GameObject->p_Transform->scale);
}

