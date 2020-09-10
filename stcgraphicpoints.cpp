#include "stcgraphicpoints.h"

#include <QWheelEvent>

StcGraphicPoints::StcGraphicPoints(QWidget *parent) : QGraphicsView(parent) {}

void StcGraphicPoints::wheelEvent(QWheelEvent *event)
{
	QGraphicsView::wheelEvent(event);
	scrollPoint += event->angleDelta().y() / 10;

	auto sceneRect = scene()->sceneRect();
	sceneRect.setRect(sceneRect.x() - scrollPoint,
					  sceneRect.y() - scrollPoint,
					  sceneRect.width() + scrollPoint,
					  sceneRect.height() + scrollPoint);
	fitInView(sceneRect, Qt::KeepAspectRatio);
}

void StcGraphicPoints::paintEvent(QPaintEvent *event)
{
	QGraphicsView::paintEvent(event);
	auto sceneRect = scene()->sceneRect();
	sceneRect.setRect(sceneRect.x() - scrollPoint,
					  sceneRect.y() - scrollPoint,
					  sceneRect.width() + scrollPoint,
					  sceneRect.height() + scrollPoint);
	fitInView(sceneRect, Qt::KeepAspectRatio);
}
