#ifndef _SELECCIOOBJECTESMOUSE_H
#define _SELECCIOOBJECTESMOUSE_H

#include "plugin.h" 

class Seleccioobjectesmouse: public QObject, public Plugin
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
	void mouseReleaseEvent(QMouseEvent *e);
	void createBox_2();
	void createVAO();
  private:
	// add private methods and attributes here
	QOpenGLShader* vs;
      	QOpenGLShader* fs;
      	QOpenGLShaderProgram* program;
        QOpenGLShaderProgram* program2;
      	GLuint VAO;
      	GLuint indexBufferID;
      	GLuint coordBufferID;
	int seleccionat;
	vector<float> vertices;
};

#endif

