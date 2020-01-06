#include "drawBoundingBox.h"
#include "glwidget.h"

void DrawBoundingBox::generateCube() {
    vertices = {
        0, 0, 0,
        0, 0, 1,
        0, 1, 0,
        0, 1, 1,
        1, 0, 0,
        1, 0, 1,
        1, 1, 0,
        1, 1, 1
    };
    indices = {
        0, 1,
        1, 3,
        3, 2,
        2, 0,
        0, 4,
        4, 5,
        5, 1,
        3, 7,
        7, 5,
        4, 6,
        6, 7,
        2, 6
    };
}

void DrawBoundingBox::generateVAO() {
    GLWidget &g = *glwidget();
    g.makeCurrent();
    g.glGenVertexArrays(1, &VAO);
    g.glGenBuffers(1, &coordBufferID);
    g.glGenBuffers(1, &indexBufferID);
    
    g.glBindVertexArray(VAO);
    g.glBindBuffer(GL_ARRAY_BUFFER, coordBufferID);
    g.glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertices.size(), &vertices[0], GL_STATIC_DRAW);
    g.glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    g.glEnableVertexAttribArray(0);
    
    g.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
    g.glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*indices.size(), &indices[0], GL_STATIC_DRAW);
    
    g.glBindVertexArray(0);
    
}

void DrawBoundingBox::onPluginLoad()
{
	QString vs_path = "./drawBoundingBox.vert";
	vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
	vs->compileSourceFile(vs_path);
	cout << "VS log:" << vs->log().toStdString() << endl;
	QString fs_path = "./drawBoundingBox.frag";
	fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
	fs->compileSourceFile(fs_path);
	cout << "FS log:" << fs->log().toStdString() << endl;
	program = new QOpenGLShaderProgram(this);
	program->addShader(vs);
	program->addShader(fs);
	program->link();
	cout << "Link log:" << program->log().toStdString() << endl;
	generateCube();
	generateVAO();
}

void DrawBoundingBox::postFrame()
{
	GLWidget &g = *glwidget();
	g.makeCurrent();
	program->bind();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();
	program->setUniformValue("modelViewProjectionMatrix", MVP);
	program->setUniformValue("boundingBoxMax", scene()->objects()[0].boundingBox().max());
	program->setUniformValue("boundingBoxMin", scene()->objects()[0].boundingBox().min());
	g.glBindVertexArray(VAO);
	g.glDrawElements(GL_LINES, indices.size(), GL_UNSIGNED_INT, (GLvoid*)0);
	g.glBindVertexArray(0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	program->release();
}
