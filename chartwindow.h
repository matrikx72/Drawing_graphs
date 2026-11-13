#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QWidget>
#include <QChartView>
#include <QLineSeries>
#include <QChart>


class ChartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChartWindow(QWidget *parent = nullptr);
    ~ChartWindow();


    void setSeriesData(const QList<QPointF> &data);

private:

       QLineSeries *m_series;
       QChart *m_chart;
};

#endif // CHARTWINDOW_H
