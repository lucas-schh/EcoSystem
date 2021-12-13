#ifndef Q_CONTROL_BAR_H
#define Q_CONTROL_BAR_H


#include <QWidget>
#include <array>


class QColorBox;
class QPushButton;
class QLabel;

// Documentation incompl�te : surtout, voir les signaux plus bas
//	 started - stopped - paused - resumed - stepped
class QControlBar : public QWidget
{
	Q_OBJECT

public:
	// �num�ration donnant l'�tat du contr�le et � la param�trisation des couleurs � utiliser.
	enum class State { NotReady = 0, Stopped, Running, Paused, _count_ };
	// �num�ration permettant la param�trisation des textes � utiliser.
	enum class Action { Start = 0, Stop, Pause, Resume, Step, _count_ };
	// Permet la d�finition de l'alignement initiale
	enum class Alignment { TowardFirst, TowardLast, Centered };

	// Constructeur
	QControlBar(Qt::Orientation orientation = Qt::Horizontal, Alignment alignment = Alignment::TowardLast, QWidget* parent = nullptr);

	// Accesseur/mutateur pour les textes pr�sents sur les boutons.
	void setActionText(Action action, QString const& text);
	QString actionText(Action action) const;

	// Accesseur/mutateur pour les couleurs repr�sentant l'�tat.
	void setStateColor(State state, QColor const& color);
	QColor stateColor(State state) const;

	// Accesseur retournant l'�tat courant.
	State state() const;

public slots:
	void setReady(bool isReady = true);
	void toggleStartStop();
	void togglePauseResume();
	void start();
	void stop();
	void pause();
	void resume();
	void step();

signals:
	void started();
	void stopped();
	void paused();
	void resumed();
	void stepped();

private:
	std::array<QColor, static_cast<int>(State::_count_)> mStateColor;
	std::array<QString, static_cast<int>(Action::_count_)> mActionText;
	State mState;
	QPushButton* mStartStopButton;
	QPushButton* mPauseButton;
	QPushButton* mStepButton;
	QColorBox* mStateMarkerColorBox;

	void updateGui();

	static std::array<QColor, static_cast<int>(State::_count_)> const mDefaultStateColor;
	static std::array<QString, static_cast<int>(Action::_count_)> const mDefaultActionText;
	static const size_t sDefaultStateMarkerDepth;
};


#endif // Q_CONTROL_BAR_H