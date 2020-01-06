#include "illuminationFS.h"
#include "glwidget.h"

void IlluminationFS::onPluginLoad()
{
	QString vs_path = "./illuminationFS.vert";
	vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
	vs->compileSourceFile(vs_path);
	cout << "VS log:" << vs->log().toStdString() << endl;
	QString fs_path = "./illuminationFS.frag";
	fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
	fs->compileSourceFile(fs_path);
	cout << "FS log:" << fs->log().toStdString() << endl;
	program = new QOpenGLShaderProgram(this);
	program->addShader(vs);
	program->addShader(fs);
	program->link();
	cout << "Link log:" << program->log().toStdString() << endl;
}

void IlluminationFS::preFrame()
{
	program->bind();
	QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();
	program->setUniformValue("modelViewProjectionMatrix", MVP);
	QMatrix4x4 MV = camera()->viewMatrix();
	program->setUniformValue("modelViewMatrix", MV);
	QMatrix3x3 NM = camera()->viewMatrix().normalMatrix();
	program->setUniformValue("normalMatrix", NM);
	QVector4D matAmbient, matDiffuse, matSpecular, lightAmbient, lightDiffuse, lightSpecular, lightPosition;
	matAmbient = QVector4D(0.8, 0.8, 0.6, 1);
	matDiffuse = QVector4D(0.8, 0.8, 0.6, 1);
	matSpecular = QVector4D(1, 1, 1, 1);
	lightAmbient = QVector4D(0.1, 0.1, 0.1, 1);
	lightDiffuse = QVector4D(1, 1, 1, 1);
	lightSpecular = QVector4D(1, 1, 1, 1);
	lightPosition = QVector4D(0, 0, 0, 1);
	program->setUniformValue("matAmbient", matAmbient);
	program->setUniformValue("matDiffuse", matDiffuse);
	program->setUniformValue("matSpecular", matSpecular);
	program->setUniformValue("lightAmbient", lightAmbient);
	program->setUniformValue("lightDiffuse", lightDiffuse);
	program->setUniformValue("lightSpecular", lightSpecular);
	program->setUniformValue("lightPosition", lightPosition);
	program->setUniformValue("matShininess", float(64.0));
}

void IlluminationFS::postFrame()
{
	program->release();
}
