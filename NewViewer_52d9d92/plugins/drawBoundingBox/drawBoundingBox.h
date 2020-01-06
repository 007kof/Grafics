#ifndef _DRAWBOUNDINGBOX_H
#define _DRAWBOUNDINGBOX_H

#include "plugin.h"
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>

class DrawBoundingBox: public QObject, public Plugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "Plugin") 
	Q_INTERFACES(Plugin)

  public:
	 void onPluginLoad();
	 void postFrame();
	 void generateVAO();
	 void generateCube();
  private:
     QOpenGLShader *vs, *fs;
     QOpenGLShaderProgram *program;
     GLuint VAO;
     GLuint indexBufferID;
     GLuint coordBufferID;
     vector<float> vertices;
     vector<uint> indices;
     
     //vector<GLuint> VAOs;
     //vector<GLuint> coordBuffers;
     //vector<GLuint> normalBuffers;
     //vector<GLuint> stBuffers;
     //vector<GLuint> colorBuffers;
     //vector<GLuint> numIndices;
	 // add private methods and attributes here
};

#endif
