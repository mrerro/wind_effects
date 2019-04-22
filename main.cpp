#include "form.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	form w;
    w.setWindowTitle("Wind Effects");
	w.show();

	return a.exec();
}
