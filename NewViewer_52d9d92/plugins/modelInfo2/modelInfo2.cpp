#include "modelInfo2.h"
#include "glwidget.h"

void ModelInfo2::printModelInfo2() {
    Scene* sc = scene();
    vector<Object> obj = sc->objects();
    int num_obj, num_pol, num_vert, num_tri;
    float percent_tri = 0.0;
    num_obj = obj.size();
    num_pol = num_vert = num_tri = percent_tri = 0;
    for (int i = 0; i < num_obj; ++i) {
        vector<Vertex> vert = obj[i].vertices();
        num_vert += vert.size();
        vector<Face> fac = obj[i].faces();
        num_pol += fac.size();
        for (int j = 0; j < num_pol; ++j) num_tri += (fac[j].numVertices() == 3) ? 1 : 0;
    }
    percent_tri = ((float)num_pol/(float)num_tri)*100;
    char s1[50], s2[50], s3[50], s4[50];
    sprintf(s1, "Number of objects: %d", num_obj);
    sprintf(s2, "Total number of polygons: %d", num_pol);
    sprintf(s3, "Total number of vertices: %d", num_vert);
    sprintf(s4, "Percentage of triangles: %.2f%%", percent_tri);
    QFont font;
    font.setPixelSize(16);
    painter.begin(glwidget());
    painter.setFont(font);
    int x = 15;
    int y = 40;
    painter.drawText(x, y, QString(s1));
    painter.drawText(x, y+20, QString(s2));
    painter.drawText(x, y+40, QString(s3));
    painter.drawText(x, y+60, QString(s4));
    painter.end();
}

void ModelInfo2::postFrame()
{
	printModelInfo2();
}
