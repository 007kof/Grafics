#include "animateVerticesPlugin.h"
#include "glwidget.h"

void AnimateVerticesPlugin::onPluginLoad()
{
	QString vs_src = 
	"#version 330 core\n\n"
	"layout (location = 0) in vec3 vertex;\n"
	"layout (location = 1) in vec3 normal;\n\n"
	"out vec4 frontColor;\n\n"
	"uniform float time;\n"
	"uniform float amplitude = 0.1;\n"
	"uniform float freq = 1;\n"
	"uniform mat4 modelViewProjectionMatrix;\n"
	"uniform mat3 normalMatrix;\n\n"
	"const float PI = 3.141592;\n\n"
	"void main() {\n"
	"   float d = amplitude * sin(2 * PI * freq * time);\n"
	"   vec3 Normal = normalize(normalMatrix * normal);\n"
	"   vec3 N = normalize(normal);\n"
	"   frontColor = vec4(Normal.z);\n"
	"   gl_Position = modelViewProjectionMatrix * vec4(vertex + d * N, 1.0);\n"
	"}";
    //QString vs_path = "./animate-vertices1.vert"; 
	vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
	vs->compileSourceCode(vs_src);
	//vs->compileSourceFile(vs_path);
	cout << "VS log:" << vs->log().toStdString() << endl;
	QString fs_src =
	"#version 330 core\n\n"
	"in vec4 frontColor;\n"
    "out vec4 fragColor;\n\n"
    "void main() {\n"
    "   fragColor = frontColor;\n"
    "}\n";
    //QString fs_path = "./animate-vertices1.frag";
	fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
	fs->compileSourceCode(fs_src);
	//fs->compileSourceFile(fs_path);
	cout << "FS log:" << fs->log().toStdString() << endl;
	program = new QOpenGLShaderProgram(this);
	program->addShader(vs);
	program->addShader(fs);
	program->link();
	cout << "Link log:" << program->log().toStdString() << endl;
	t.start();
}

void AnimateVerticesPlugin::preFrame()
{
	program->bind();
	program->setUniformValue("amplitude", float(0.1));
	program->setUniformValue("freq", float(1));
	program->setUniformValue("time", float(t.elapsed())/1000.0f);
	QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();
	program->setUniformValue("modelViewProjectionMatrix", MVP);
	QMatrix3x3 NM = camera()->viewMatrix().normalMatrix();
	program->setUniformValue("normalMatrix", NM);
}

void AnimateVerticesPlugin::postFrame()
{
	program->release();
}
