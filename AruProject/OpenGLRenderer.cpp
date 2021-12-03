#include "OpenGLRenderer.h"
#include <stdio.h>

float plus = 0.0f;
void ResetDisplay()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	glTranslatef(plus, 0.0, 0);
  
	//plus += 0.02;
	glutPostRedisplay();
}

OpenGLRenderer::~OpenGLRenderer()
{
    for (auto x : texRec)
    {
        delete x;
    }
    delete[]MyTextureObject;
}

void OpenGLRenderer::Init(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Drawing Example");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutSwapBuffers();
}

void OpenGLRenderer::MakeTextureObjectArr(int _cnt)
{
    MyTextureObject = new unsigned int[99]; // 동적할당 
}

void OpenGLRenderer::AddTexture(char* szFilename)
{
    texRec.emplace_back(LoadBMP(szFilename));
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

unsigned int OpenGLRenderer::GetMyTextureObject(int _index)
{
    return MyTextureObject[_index];
}

int OpenGLRenderer::LoadGLTextures()
{
    int Status = FALSE;
    int objectCnt = 0;
    int size = texRec.size();
    MakeTextureObjectArr(size);
     
    glGenTextures(size, &MyTextureObject[0]);
    for (auto x : texRec)
    {
        glBindTexture(GL_TEXTURE_2D, MyTextureObject[objectCnt]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D,
            0,
            3,
            x->sizeX,
            x->sizeY,
            0,
            GL_RGB,
            GL_UNSIGNED_BYTE,
            x->data);
        objectCnt++;
    }

     for (auto x : texRec)
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
    ////////////////////////////////////////////////////////////////////
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