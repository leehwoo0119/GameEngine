#ifndef _IRENDERER_H_
#define _IRENDERER_H_

__interface IRenderer
{
public:
	virtual void Init(int argc, char** argv) = 0;
	virtual void RenderReset() = 0;
	virtual void LoopEvent() = 0;
	virtual int LoadGLTextures() = 0;
	virtual void AddTexture(char* szFilename) = 0;
	virtual unsigned int GetMyTextureObject(int _index) = 0;
};

#endif 