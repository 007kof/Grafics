#include "modelInfo1.h"
#include "glwidget.h"

void ModelInfo1::printModelInfo1() {
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
    cout << "Number of objects: " << num_obj << endl;
    cout << "Total number of polygons: " << num_pol << endl;
    cout << "Total number of vertices: " << num_vert << endl;
    cout << "Percentatge of triangles: " << percent_tri << "%" << endl;
}

void ModelInfo1::postFrame()
{
	printModelInfo1();
}
