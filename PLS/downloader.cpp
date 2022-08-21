#include "downloader.h"

downloader::downloader(QObject *parent)
    : QObject{parent}
{}


void downloader::append(const QUrl &url)
{
    if (link.isEmpty())
        QTimer::singleShot(0, this, &downloader::startNextDownload);
    link = url;
}

QString downloader::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "download";

    if (QFile::exists(basename)) {
        int i = 1;
        basename = ')' + basename;
        while (QFile::exists('(' + QString::number(i) + basename))
            ++i;

        basename = "(" + QString::number(i) + basename;
    }
    return basename;
}

QString downloader::getFileName()
{
    return file;
}

void downloader::startNextDownload()
{
    if(link.isEmpty())
    {
        emit finished();
        return;
    }

    file = saveFileName(link);
    emit filename(file);
    output.setFileName(file);
    if (!output.open(QIODevice::WriteOnly)) {
        return;
    }

    QNetworkRequest request(link);
    currentDownload = manager.get(request);
    connect(currentDownload, &QNetworkReply::downloadProgress,
            this, &downloader::downloadProgress);
    connect(currentDownload, &QNetworkReply::finished,
            this, &downloader::downloadFinished);
    connect(currentDownload, &QNetworkReply::readyRead,
            this, &downloader::downloadReadyRead);
}

void downloader::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    emit data(bytesReceived,bytesTotal);
}

void downloader::downloadFinished()
{
    output.close();
    emit finished();

    if (currentDownload->error())
    {
        output.remove();
    }
    else
    {
        if (isHttpRedirect())
        {
            output.remove();
        }
    }

    currentDownload->deleteLater();
}

void downloader::downloadReadyRead()
{
    output.write(currentDownload->readAll());
}

bool downloader::isHttpRedirect() const
{
    int statusCode = currentDownload->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    return statusCode == 301 || statusCode == 302 || statusCode == 303
           || statusCode == 305 || statusCode == 307 || statusCode == 308;
}
