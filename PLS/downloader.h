#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QtCore>
#include <QtNetwork>

class downloader : public QObject
{
    Q_OBJECT
public:
    explicit downloader(QObject *parent = nullptr);
    void append(const QUrl &url);
    void append(const QStringList &urls);
    static QString saveFileName(const QUrl &url);
    QString getFileName();

signals:
    void finished(); //emitted when finished
    void data(qint64,qint64); //emitted when downloading ,emits progress of download
    void filename(QString name); //emits a signal for the name of the file

private slots:
    void startNextDownload();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void downloadFinished();
    void downloadReadyRead();

private:
    bool isHttpRedirect() const;
    QNetworkAccessManager manager;
    QUrl link;
    QNetworkReply *currentDownload = nullptr;
    QFile output;
    QString file;
};

#endif // DOWNLOADER_H
