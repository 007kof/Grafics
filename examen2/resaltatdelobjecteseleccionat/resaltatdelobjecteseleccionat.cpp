#include "resaltatdelobjecteseleccionat.h"
#include "glwidget.h"
#include "scene.h"

void Resaltatdelobjecteseleccionat::onPluginLoad()
{
    //shader loard  
    glwidget()->makeCurrent();
    // Carrega shader, compila i munta
    vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vs->compileSourceFile("resaltatdelobjecteseleccionat.vert");

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceFile("resaltatdelobjecteseleccionat.frag");

    program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    // Genera la caixa englobat
    createBox_2();
    createVAO();
    seleccionat = 0;
}

void Resaltatdelobjecteseleccionat::preFrame()
{
	
}

void Resaltatdelobjecteseleccionat::postFrame()
{
	    glwidget()->makeCurrent();
    GLWidget &g = *glwidget();
    program->bind();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    program->setUniformValue("mvp",
                           camera()->projectionMatrix() *
                           camera()->viewMatrix());

    const vector<Object> &obj = scene()->objects();
    seleccionat = scene()->selectedObject();
    if (seleccionat != -1){
        program->setUniformValue("boundingBoxMin",obj[seleccionat].boundingBox().min());
        program->setUniformValue("boundingBoxMax",obj[seleccionat].boundingBox().max());
    
        g.glBindVertexArray(VAO);
        g.glDrawArrays(GL_TRIANGLE_STRIP,0,vertices.size());
        g.glBindVertexArray(0);
     }
   

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    program->release();
}

void Resaltatdelobjecteseleccionat::onObjectAdd()
{
	
}

bool Resaltatdelobjecteseleccionat::drawScene()
{
	return false; // return true only if implemented
}

bool Resaltatdelobjecteseleccionat::drawObject(int)
{
	return false; // return true only if implemented
}

bool Resaltatdelobjecteseleccionat::paintGL()
{
	return false; // return true only if implemented
}

void Resaltatdelobjecteseleccionat::mousePressEvent ( QMouseEvent * ){


}
void Resaltatdelobjecteseleccionat::keyPressEvent(QKeyEvent *)
{

}

void Resaltatdelobjecteseleccionat::mouseMoveEvent(QMouseEvent *)
{
	
}

void Resaltatdelobjecteseleccionat::createVAO(){
    glwidget()->makeCurrent();
    GLWidget &g = *glwidget();
    
    
    g.glGenVertexArrays(1,&VAO);
    
    
    g.glGenBuffers(1,&coordBufferID);
    
    
    
    g.glGenBuffers(1,&indexBufferID);
    
    g.glBindVertexArray(VAO);
    g.glBindBuffer(GL_ARRAY_BUFFER,coordBufferID);
    g.glBufferData(GL_ARRAY_BUFFER,sizeof(float)*vertices.size(),&vertices[0],GL_STATIC_DRAW);
    g.glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
    g.glEnableVertexAttribArray(0);
    
//     g.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,indexBufferID);
//     g.glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(int)*indices.size(),&indices[0],GL_STATIC_DRAW);
    
    g.glBindBuffer(GL_ARRAY_BUFFER,0);
    g.glBindVertexArray(0);

}
void Resaltatdelobjecteseleccionat::createBox_2(){
    vertices.clear();
    
    vertices={
        1, 1, 1,
        0, 1, 1,
        1, 0, 1,
        0, 0, 1,
        1, 0, 0,
        0, 0, 0,
        1, 1, 0,
        0, 1, 0,
        1, 1, 1,
        0, 1, 1,
        0, 1, 1,
        0, 1, 0,
        0, 0, 1,
        0, 0, 0,
        1, 0, 1,
        1, 0, 0,
        1, 1, 1,
        1, 1, 0
        };
    

}


