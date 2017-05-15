
#include <QGroupBox>
#include <QDockWidget>
#include <QSettings>

class Controller {
public:
	//Controller(myData * _data,QMainWindow * tab, QComboBox * viewCombo);
	//myData * data;
	//Robot * tmpRobot;
	//void update();
	//void draw(int drawPlugin);
	//void addPlugin(BasePlugin * plugin,QMainWindow * tab,QComboBox * viewCombo);
	//vector<BasePlugin*> plugins;	
	//vector<QDockWidget*> docks;
	void loadSettings(QSettings * settings);
	void saveSettings(QSettings * settings);
};