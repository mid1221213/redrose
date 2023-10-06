#ifndef PLAYERTHREAD_H
#define PLAYERTHREAD_H

#include <fluidsynth.h>
#include <QThread>
#include <QObject>

class PlayerThread : public QThread
{
    Q_OBJECT
public:
    explicit PlayerThread(fluid_synth_t* synth, QObject *parent = nullptr);
    ~PlayerThread();
    void stop();
    bool err();
    int addMIDIFile(const QString& filename);
    int addMIDIBuffer(const QByteArray& buf);

protected:
    void run() override;

private:
    fluid_player_t *fluid_player = nullptr;
    bool m_err;
};

#endif // PLAYERTHREAD_H
