#include "framerate.h"
#include "glwidget.h"

void Framerate::onPluginLoad() {
    fps = 0;
}

void Framerate::preFrame()
{
    if (fps == 0) t.start();
    else cout << "FPS: " << int(fps/(t.elapsed()/1000.0)) << endl;
    ++fps;
}
