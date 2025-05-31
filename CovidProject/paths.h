#pragma once
#include <QString>
#include <QDir>
#include <QCoreApplication>
#include <QDebug>

inline QString getPersonsFilePath() {
	QDir exeDir(QCoreApplication::applicationDirPath());
	qDebug() << exeDir;
	exeDir.cdUp();
	//qDebug() << exeDir;
	exeDir.cdUp();
	//qDebug() << exeDir;
	exeDir.cd("Data");
	//qDebug() << exeDir;
	return exeDir.filePath("persons.csv");
}

