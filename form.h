#ifndef FORM_H
#define FORM_H

#include "Wind.hpp"

#include <QtCharts>
#include <QTimer>
#include <QWidget>
#include <QFile>

namespace Ui {
	class form;
}

class form : public QWidget
{
	Q_OBJECT

public:
	explicit form(QWidget *parent = nullptr);
	~form();

private:
	Ui::form *ui;
	QTimer *timer;
    QChart *chart1;
    QChart *chart2;
    QLineSeries *seriesYX;
    QLineSeries *seriesZXY;
    QScatterSeries *coreXY;
    QScatterSeries *coreZXY;
    Wind *wind;
	double totalTime;
	double timerInterval;
	void updateStatus();
	void setDisabledSplinBoxes(bool);
    QFile *fileOut = new QFile("data.csv");

private slots:
	void updateGraph();
	void on_start_clicked();
    void on_stop_clicked();
	void on_x_axis_editingFinished();
    void on_y_axis_editingFinished();
    void on_z_axis_editingFinished();
    void on_xy_axis_editingFinished();
};

#endif // FORM_H
