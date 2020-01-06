#ifndef _RESALTATDELOBJECTESELECCIONAT_H
#define _RESALTATDELOBJECTESELECCIONAT_H

#include "plugin.h" 

class Resaltatdelobjecteseleccionat: public QObject, public Plugin
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
	void mousePressEvent( QMouseEvent * );
	void createBox_2();
	void createVAO();
  private:
	// add private methods and attributes here
	QOpenGLShader* vs;
      	QOpenGLShader* fs;
      	QOpenGLShaderProgram* program;
      	GLuint VAO;
      	GLuint indexBufferID;
      	GLuint coordBufferID;
	int seleccionat;
	vector<float> vertices;
};

#endif
