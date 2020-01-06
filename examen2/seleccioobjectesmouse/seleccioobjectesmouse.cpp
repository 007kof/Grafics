#include "seleccioobjectesmouse.h"
#include "glwidget.h"
#include "scene.h"

void Seleccioobjectesmouse::onPluginLoad()
{   

    // Carrega shader, compila i munta
    vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vs->compileSourceFile("seleccioobjectesmouse.vert");

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceFile("seleccioobjectesmouse.frag");

    program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    // Genera la caixa englobat
    createBox_2();
    createVAO();
    

    // Carrega shader, compila i munta
    vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vs->compileSourceFile("seleccioobjectesmouse2.vert");

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceFile("seleccioobjectesmouse2.frag");

    program2 = new QOpenGLShaderProgram(this);
    program2->addShader(vs);
    program2->addShader(fs);
    program2->link(); 

    
    
}

void Seleccioobjectesmouse::preFrame()
{
	
}

void Seleccioobjectesmouse::postFrame()
{


    glwidget()->makeCurrent();
    
    GLWidget &g = *glwidget();//la aplicacion
    program->bind();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    program->setUniformValue("mvp",
                           camera()->projectionMatrix() *
                           camera()->viewMatrix());

    const vector<Object> &obj = scene()->objects();
    seleccionat = scene()->selectedObject();
    if (seleccionat >= 0 && seleccionat < obj.size()){
        program->setUniformValue("boundingBoxMin",obj[seleccionat].boundingBox().min());
        program->setUniformValue("boundingBoxMax",obj[seleccionat].boundingBox().max());
    
        g.glBindVertexArray(VAO);
        g.glDrawArrays(GL_TRIANGLE_STRIP,0,vertices.size());
        g.glBindVertexArray(0);
     }
   

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    program->release();
}

void Seleccioobjectesmouse::onObjectAdd()
{
	
}

bool Seleccioobjectesmouse::drawScene()
{
	return false; // return true only if implemented
}

bool Seleccioobjectesmouse::drawObject(int)
{
	return false; // return true only if implemented
}

bool Seleccioobjectesmouse::paintGL()
{
	return false; // return true only if implemented
}

void Seleccioobjectesmouse::mousePressEvent ( QMouseEvent * ){


}
void Seleccioobjectesmouse::keyPressEvent(QKeyEvent *)
{

}

void Seleccioobjectesmouse::mouseMoveEvent(QMouseEvent *)
{
	
}


void Seleccioobjectesmouse::mouseReleaseEvent(QMouseEvent *e){
	if(!(e->button() & Qt::RightButton)) return;
        if(! (e->modifiers() & Qt::ControlModifier)) return;
        
        glClearColor(1, 1, 1, 1);                           // esborrar els buffers amb un color de fons únic (blanc)
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        
    
       
        program2->bind();
        program2->setUniformValue("mvp",
                           camera()->projectionMatrix() *
                           camera()->viewMatrix());
        
        
        for (unsigned int i = 0; i<scene()->objects().size();++i){
         GLubyte color[4];
         color[0]=color[1]=color[2]=i;
         program2->setUniformValue("color",QVector4D(color[0]/255.0,color[1]/255.0,color[2]/255.,1.0));
         drawPlugin()->drawObject(i);
        }
        program->release();
        
        int x = e->x();
        int y = glwidget()->height()-e->y();
        GLubyte read[4];
        glReadPixels(x, y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, read);
        cout << int(read[0]) << endl;
        
        
        scene()->setSelectedObject(int(read[0]*255));
}

void Seleccioobjectesmouse::createVAO(){
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
void Seleccioobjectesmouse::createBox_2(){
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



