#ifndef STCGRAPHICPOINTS_H
#define STCGRAPHICPOINTS_H

#include <QGraphicsView>

class StcGraphicPoints : public QGraphicsView
{
	int scrollPoint = 0;

public:
	explicit StcGraphicPoints(QWidget *parent = nullptr);
	void wheelEvent(QWheelEvent *event) override;
	void paintEvent(QPaintEvent *event) override;
};

#endif // STCGRAPHICPOINTS_H
