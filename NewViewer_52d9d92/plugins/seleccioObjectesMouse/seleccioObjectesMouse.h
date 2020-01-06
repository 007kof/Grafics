#ifndef _SELECCIOOBJECTESMOUSE_H
#define _SELECCIOOBJECTESMOUSE_H

#include "plugin.h"
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>

class SeleccioObjectesMouse: public QObject, public Plugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "Plugin") 
	Q_INTERFACES(Plugin)

  public:
	 void onPluginLoad();
	 void postFrame();
	 void generateVAO();
	 void generateCube();
	 void mouseReleaseEvent(QMouseEvent *e);
	 void setSelectedObject();
  private:
     QOpenGLShader *vs, *fs;
     QOpenGLShaderProgram *program;
     GLuint VAO;
     GLuint indexBufferID;
     GLuint coordBufferID;
     vector<float> vertices;
     vector<uint> indices;
     int selected;
     
     //vector<GLuint> VAOs;
     //vector<GLuint> coordBuffers;
     //vector<GLuint> normalBuffers;
     //vector<GLuint> stBuffers;
     //vector<GLuint> colorBuffers;
     //vector<GLuint> numIndices;
	 // add private methods and attributes here
};

#endif
