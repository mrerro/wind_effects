#ifndef FORM_H
#define FORM_H

#include "DoubleStarSatelite.hpp"

#include <QtCharts>
#include <QTimer>
#include <QWidget>

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
	QChart *chart;
	QLineSeries *series;
	QScatterSeries *planet1;
	QScatterSeries *planet2;
	DoubleStarSatelite *doubleStarSatelite;
	double totalTime;
	double timerInterval;
	void updateStatus();
	void setDisabledSplinBoxes(bool);

private slots:
	void updateGraph();
	void on_start_clicked();
	void on_stop_clicked();
	void on_L_valueChanged(double arg1);
	void on_x_axis_editingFinished();
	void on_y_axis_editingFinished();
    void on_M1_editingFinished();
    void on_M2_editingFinished();
};

#endif // FORM_H
