#include "Render2DTexture.h"
#include "GameObject.h"
#include "Transform.h"
#include "RendererManager.h"

void Render2DTexture::Render()
{
    RendererManager::Instance()->GetRenderer()->
        Render2DTexture(p_GameObject->p_Transform->position, p_GameObject->p_Transform->scale, imageName);
}