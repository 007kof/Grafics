#ifndef _BOUNDINGBOX_H
#define _BOUNDINGBOX_H

#include "plugin.h" 

class BoundingBox: public QObject, public Plugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "Plugin") 
	Q_INTERFACES(Plugin)

  public:
	 void onPluginLoad();
	 void preFrame();
	 void postFrame();

	 void onObjectAdd();
	 bool drawScene();
	 bool drawObject(int);

	 bool paintGL();

	 void keyPressEvent(QKeyEvent *);
	 void mouseMoveEvent(QMouseEvent *);
     
     void createBox_1();
     void createBox_2();
     void createVAO();
     void drawBoxes();
  private:
      
      QOpenGLShader* vs;
      QOpenGLShader* fs;
      QOpenGLShaderProgram* program;
      GLuint VAO;
      GLuint indexBufferID;
      GLuint coordBufferID;
      
	vector<float> vertices;
	vector<float> normals;
    vector<unsigned int> indices;
	// add private methods and attributes here
};

#endif
