#include "OpenGLRenderer.h"
#include <iostream>
#include "Camera.h"
#include "RendererManager.h"

OpenGLRenderer::OpenGLRenderer() :p_MyTextureObject(nullptr), textureNum(0), p_Camera(nullptr)
{
}

OpenGLRenderer::~OpenGLRenderer()
{
    for (auto x : m_TexRec)
    {
        delete x;
    }
    delete[]p_MyTextureObject;
}

void OpenGLRenderer::ResetDisplay()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    DisplayCamera();
    glutPostRedisplay();
}

bool OpenGLRenderer::Init(int argc, char** argv, int _width, int _height, const char* _title)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(_width, _height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(_title);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutSwapBuffers();
    return true;
}

void OpenGLRenderer::MakeTextureObjectArr(int _cnt)
{
    p_MyTextureObject = new unsigned int[_cnt];
}

void OpenGLRenderer::AddTexture(char* szFilename, std::string _textureName)
{
    try
    {
        if (LoadBMP(szFilename) == NULL)
        {
            throw std::string(szFilename);
        }
        m_TexRec.emplace_back(LoadBMP(szFilename));
    }
    catch (std::string& _errorMessege)
    {
        std::cout << _errorMessege << " -> 잘못된 리소스 경로(리소스 경로 재확인)" << "\n\n";
        return;
    }
    m_TextureInfo.insert(std::pair<std::string, int>(_textureName, textureNum++));
}

AUX_RGBImageRec* OpenGLRenderer::LoadBMP(char* szFilename)
{
    FILE* pFile = NULL; //파일 초기화
    if (!szFilename) {
        return NULL;
    }
    fopen_s(&pFile, szFilename, "r"); // szFilename의 파일 오픈
    if (pFile) {
        fclose(pFile);
        return auxDIBImageLoad(szFilename);     //파일로부터 메모리로
    }
    return NULL;
}

int OpenGLRenderer::GetMyTextureObject(std::string _name)
{
    auto iter = m_TextureInfo.find(_name);
    if (iter != m_TextureInfo.end())
        return p_MyTextureObject[iter->second];
    else
        return -1;
}

void OpenGLRenderer::Render2DCircle(Vector3 _pos, Vector3 _scale)
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    float radiusX = _scale.x;
    float radiusY = _scale.y;

    for (int i = 0; i < 360; i++)
    {
        double angle = i * 3.141592 / 180;
        double x = radiusX * cos(angle);
        double y = radiusY * sin(angle);
        glVertex2f(x + _pos.x, y + _pos.y);
    }
    glEnd();
    glFinish();
    glPopMatrix();
}

void OpenGLRenderer::Render2DTriangle(Vector3 _pos, Vector3 _scale)
{   
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex2f(_pos.x - (_scale.x / 2), _pos.y - (_scale.y / 2));
    glVertex2f(_pos.x + (_scale.x / 2), _pos.y - (_scale.y / 2));
    glVertex2f(_pos.x, _pos.y + (_scale.y / 2));
    glEnd();
    glFinish();
    glPopMatrix();
}

void OpenGLRenderer::Render2DSquare(Vector3 _pos, Vector3 _scale)
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2f(_pos.x - (_scale.x / 2), _pos.y - (_scale.y / 2));
    glVertex2f(_pos.x + (_scale.x / 2), _pos.y - (_scale.y / 2));
    glVertex2f(_pos.x + (_scale.x / 2), _pos.y + (_scale.y / 2));
    glVertex2f(_pos.x - (_scale.x / 2), _pos.y + (_scale.y / 2));
    glEnd();
    glFinish();
    glPopMatrix();
}

void OpenGLRenderer::Render2DTexture(Vector3 _pos, Vector3 _scale, std::string _textureName)
{
    int textureTypeNum = GetMyTextureObject(_textureName);
    
    if (textureTypeNum == -1)
    {
        std::cout << "텍스쳐 로딩 실패" << std::endl;
        return;
    }
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, textureTypeNum);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);   glVertex2f(_pos.x - (_scale.x / 2), _pos.y - (_scale.y / 2));
    glTexCoord2f(1.0f, 0.0f);   glVertex2f(_pos.x + (_scale.x / 2), _pos.y - (_scale.y / 2));
    glTexCoord2f(1.0f, 1.0f);   glVertex2f(_pos.x + (_scale.x / 2), _pos.y + (_scale.y / 2));
    glTexCoord2f(0.0f, 1.0f);   glVertex2f(_pos.x - (_scale.x / 2), _pos.y + (_scale.y / 2));
    glEnd();
    glFinish();
    glPopMatrix();
}

void OpenGLRenderer::SetCamera(Camera* _camera)
{
    if (!p_Camera)
    {
        p_Camera = _camera;
    }
}

void OpenGLRenderer::DisplayCamera()
{
    float camX = RendererManager::Instance()->GetCameraPos().x;
    float camY = RendererManager::Instance()->GetCameraPos().y;
    float camZ = RendererManager::Instance()->GetCameraPos().z;
    glTranslatef(-camX, -camY, -camZ);
}

int OpenGLRenderer::LoadGLTextures()
{
    int Status = FALSE;
    int objectCnt = 0;
    int size = m_TexRec.size();
    MakeTextureObjectArr(size);
     
    glGenTextures(size, &p_MyTextureObject[0]);
    for (auto x : m_TexRec)
    {
        glBindTexture(GL_TEXTURE_2D, p_MyTextureObject[objectCnt]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D,
            0, 3
            ,x->sizeX, x->sizeY,
            0,
            GL_RGB, GL_UNSIGNED_BYTE,
            x->data);
        objectCnt++;
    }

     for (auto x : m_TexRec)
    {
        if (x)
        {
            if (x->data) free(x->data);
            free(x);
        }
        else return FALSE;
    }

    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glDisable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    return TRUE;
}

void OpenGLRenderer::RenderReset()
{
    glutDisplayFunc(ResetDisplay);
}

void OpenGLRenderer::LoopEvent()
{
	glutSwapBuffers();
	glutMainLoopEvent();
}