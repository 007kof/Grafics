#include "resaltatdelobjectesteclat.h"
#include "glwidget.h"


void Resaltatdelobjectesteclat::onPluginLoad()
{
    //shader loard  
    glwidget()->makeCurrent();
    // Carrega shader, compila i munta
    vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vs->compileSourceFile("resaltatdelobjectesteclat.vert");

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceFile("resaltatdelobjectesteclat.frag");

    program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    // Genera la caixa englobat
    createBox_2();
    createVAO();
    seleccionat = 0;
}

void Resaltatdelobjectesteclat::preFrame()
{
	
}

void Resaltatdelobjectesteclat::postFrame()
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

void Resaltatdelobjectesteclat::onObjectAdd()
{
	
}

bool Resaltatdelobjectesteclat::drawScene()
{
	return false; // return true only if implemented
}

bool Resaltatdelobjectesteclat::drawObject(int)
{
	return false; // return true only if implemented
}

bool Resaltatdelobjectesteclat::paintGL()
{
	return false; // return true only if implemented
}

void Resaltatdelobjectesteclat::mousePressEvent ( QMouseEvent * ){


}
void Resaltatdelobjectesteclat::keyPressEvent(QKeyEvent *e)
{	/*
    switch( e->key() ){
    case Qt::Key_1: 
    seleccionat = 0;
    scene()‐>setSelectedObject(1);
        break;
    case Qt::Key_2:
    seleccionat = 1;
    scene()‐>setSelectedObject(2);
	    break;

    case Qt::Key_3:
        seleccionat = 2;
    scene()‐>setSelectedObject(3);
	break;

    case Qt::Key_4: 
        seleccionat = 3;
    scene()‐>setSelectedObject(4);
        break;        
        
    case Qt::Key_5: 
        seleccionat = 4;
    scene()‐>setSelectedObject(5);
        break;

    case Qt::Key_6: 
        seleccionat = 5;
    scene()‐>setSelectedObject(6);
        break;

    case Qt::Key_7:
        seleccionat = 6;
    scene()‐>setSelectedObject(7);
        break;
    case Qt::Key_8:
        seleccionat = 7;
    scene()‐>setSelectedObject(8);
        break;
    case Qt::Key_9:
        seleccionat = 8;
    scene()‐>setSelectedObject(9);
        break;
    }
    //if (scene()->objects().size()<seleccionat) seleccionat = -1;
   if (scene()->objects().size()<seleccionat) scene()‐>setSelectedObject(-1);
   update();
	*/
	if(e->key()>=Qt::Key_0 && e->key()<=Qt::Key_9) scene()->setSelectedObject(e->key()-Qt::Key_0);
}

void Resaltatdelobjectesteclat::mouseMoveEvent(QMouseEvent *)
{
	
}

void Resaltatdelobjectesteclat::createVAO(){
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
void Resaltatdelobjectesteclat::createBox_2(){
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




