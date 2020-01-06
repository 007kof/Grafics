#ifndef _ILLUMINATIONFS_H
#define _ILLUMINATIONFS_H

#include "plugin.h"
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>

class IlluminationFS: public QObject, public Plugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "Plugin") 
	Q_INTERFACES(Plugin)

  public:
	 void onPluginLoad();
	 void preFrame();
	 void postFrame();
  private:
    QOpenGLShader *vs, *fs;
    QOpenGLShaderProgram *program;
	// add private methods and attributes here
};

#endif
