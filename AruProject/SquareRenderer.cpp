#include "SquareRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "RendererManager.h"

void SquareRenderer::Render()
{
	RendererManager::Instance()->GetRenderer()->
		Render2DSquare(p_GameObject->p_Transform->position, p_GameObject->p_Transform->scale);
}
