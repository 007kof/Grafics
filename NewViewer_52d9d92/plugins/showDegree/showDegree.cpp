#include "showDegree.h"
#include "glwidget.h"

void ShowDegree::onPluginLoad() {
    Scene *sc = scene();
    Object obj = sc->objects()[0];
    vector<Vertex> vert = obj.vertices();
    vector<int> deg(vert.size(), 0);
    vector<Face> fac = obj.faces();
    for (uint i = 0; i < fac.size(); ++i) 
        for (int j = 0; j < fac[i].numVertices(); ++j) 
            ++deg[fac[i].vertexIndex(j)];
    degree = 0.0;
    for (uint i = 0; i < deg.size(); ++i) degree += float(deg[i]);
    degree /= float(deg.size());
}

void ShowDegree::postFrame()
{
    char s[20];
    sprintf(s, "%f", degree);
	QFont font;
	font.setPixelSize(16);
	painter.begin(glwidget());
	painter.setFont(font);
	int x = 15;
	int y = 40;
	painter.drawText(x, y, QString(s));
	painter.end();
}

