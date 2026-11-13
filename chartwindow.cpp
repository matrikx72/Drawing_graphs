#include "chartwindow.h"
#include <QVBoxLayout>

ChartWindow::ChartWindow(QWidget *parent)
    : QWidget(parent)
{
    // Создаем серию (линию) и сам график
    m_series = new QLineSeries();
    m_chart = new QChart();
    m_chart->addSeries(m_series);
    m_chart->setTitle("Первая секунда данных");
    m_chart->createDefaultAxes(); // Создаем оси X и Y

    // Создаем виджет для отображения графика
    auto *chartView = new QChartView(m_chart);
    chartView->setRenderHint(QPainter::Antialiasing); // Включаем сглаживание

    // Создаем вертикальную компоновку и добавляем туда график
    auto *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);

    // Задаем начальный размер окна
    resize(800, 600);
}
ChartWindow::~ChartWindow()
{

}

void ChartWindow::setSeriesData(const QList<QPointF> &data)
{
    // Заменяем старые данные новыми
    m_series->replace(data);

    // Обновляем оси, чтобы они подстроились под новые значения
    m_chart->createDefaultAxes();
}
