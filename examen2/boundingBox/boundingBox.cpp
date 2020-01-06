#include "boundingBox.h"
#include "glwidget.h"

void BoundingBox::onPluginLoad()
{
    //shader loard  
    glwidget()->makeCurrent();
    // Carrega shader, compila i munta
    vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vs->compileSourceFile("boundingBox.vert");

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceFile("boundingBox.frag");

    program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    // Genera la caixa englobat
    createBox_2();
    createVAO();
    
}

void BoundingBox::preFrame()
{
	
}

void BoundingBox::postFrame()
{
    glwidget()->makeCurrent();
    GLWidget &g = *glwidget();
    program->bind();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //versio amb index
//     g.glBindVertexArray(VAO);
//     g.glDrawElements(GL_TRIANGLES, indices.size(),GL_UNSIGNED_INT, (GLvoid*) 0);
//     g.glBindVertexArray(0);

    
    program->setUniformValue("mvp",
                           camera()->projectionMatrix() *
                           camera()->viewMatrix());

    Scene* scn = scene();
    const vector<Object> &obj = scn->objects();
    for(int i =0; i<(int)obj.size(); ++i){
        program->setUniformValue("boundingBoxMin",obj[i].boundingBox().min());
        program->setUniformValue("boundingBoxMax",obj[i].boundingBox().max());
        
    
    //version nomes amb vertex
        g.glBindVertexArray(VAO);
//     g.glBindBuffer(GL_ARRAY_BUFFER, coordBufferID);
        g.glDrawArrays(GL_TRIANGLE_STRIP,0,vertices.size());
        g.glBindVertexArray(0);
//     g.glDisableVertexAttribArray(0);
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    program->release();
}

void BoundingBox::onObjectAdd()
{
	
}

bool BoundingBox::drawScene()
{
	return false; // return true only if implemented
}

bool BoundingBox::drawObject(int)
{
	return false; // return true only if implemented
}

bool BoundingBox::paintGL()
{
	return false; // return true only if implemented
}

void BoundingBox::keyPressEvent(QKeyEvent *)
{
	
}

void BoundingBox::mouseMoveEvent(QMouseEvent *)
{
	
}
void BoundingBox::drawBoxes(){

    
}
void BoundingBox::createVAO(){
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

void BoundingBox::createBox_2(){
    vertices.clear();
    indices.clear();
    
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
void BoundingBox::createBox_1(){
    vertices.clear();
    indices.clear();
    
    scene()->computeBoundingBox();
    Box bBox = scene()->boundingBox();
    float xmin, xmax, ymin, ymax, zmin, zmax;
    xmin = bBox.min().x();
    xmax = bBox.max().x();
    ymin = bBox.min().y();
    ymax = bBox.max().y();
    zmin = bBox.min().z();
    zmax = bBox.max().z();
    
    // v1
    vertices.push_back(xmin);
    vertices.push_back(ymin);
    vertices.push_back(zmin);
    // v2
    vertices.push_back(xmax);
    vertices.push_back(ymin);
    vertices.push_back(zmin);
    // v3
    vertices.push_back(xmax);
    vertices.push_back(ymax);
    vertices.push_back(zmin);
    // v4
    vertices.push_back(xmin);
    vertices.push_back(ymax);
    vertices.push_back(zmin);
    // v5
    vertices.push_back(xmin);
    vertices.push_back(ymin);
    vertices.push_back(zmax);
    // v6
    vertices.push_back(xmax);
    vertices.push_back(ymin);
    vertices.push_back(zmax);
    // v7
    vertices.push_back(xmax);
    vertices.push_back(ymax);
    vertices.push_back(zmax);
    // v8
    vertices.push_back(xmin);
    vertices.push_back(ymax);
    vertices.push_back(zmax);

    // t1
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);
    // t2
    indices.push_back(0);
    indices.push_back(2);
    indices.push_back(3);
    // t3
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(4);
    // t4
    indices.push_back(1);
    indices.push_back(4);
    indices.push_back(5);
    // t5
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(5);
    // t6
    indices.push_back(2);
    indices.push_back(5);
    indices.push_back(6);
    // t7
    indices.push_back(2);
    indices.push_back(3);
    indices.push_back(6);
    // t8
    indices.push_back(3);
    indices.push_back(6);
    indices.push_back(7);
    // t9
    indices.push_back(3);
    indices.push_back(0);
    indices.push_back(7);
    // t10
    indices.push_back(0);
    indices.push_back(7);
    indices.push_back(4);
    // t11
    indices.push_back(4);
    indices.push_back(5);
    indices.push_back(6);
    // t12
    indices.push_back(4);
    indices.push_back(6);
    indices.push_back(7);
    
}

