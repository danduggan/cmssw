#ifndef EBBeamCaloClient_H
#define EBBeamCaloClient_H

/*
 * \file EBBeamCaloClient.h
 *
 * $Date: 2007/09/07 22:30:03 $
 * $Revision: 1.24 $
 * \author G. Della Ricca
 * \author A. Ghezzi
 *
*/

#include <vector>
#include <string>

#include "TROOT.h"
#include "TProfile2D.h"
#include "TProfile.h"
#include "TH1F.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "OnlineDB/EcalCondDB/interface/EcalCondDBInterface.h"
#include "OnlineDB/EcalCondDB/interface/MonRunIOV.h"

#include "DQMServices/Core/interface/MonitorElement.h"
#include "DQMServices/Core/interface/MonitorUserInterface.h"
#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"

#include "DQM/EcalBarrelMonitorClient/interface/EBClient.h"

class EBBeamCaloClient : public EBClient {

public:

/// Constructor
EBBeamCaloClient(const edm::ParameterSet& ps);

/// Destructor
virtual ~EBBeamCaloClient();

/// Subscribe/Unsubscribe to Monitoring Elements
void subscribe(void);
void subscribeNew(void);
void unsubscribe(void);

/// softReset
void softReset(void);

/// Analyze
void analyze(void);

/// BeginJob
void beginJob(MonitorUserInterface* mui);

/// EndJob
void endJob(void);

/// BeginRun
void beginRun(void);

/// EndRun
void endRun(void);

/// Setup
void setup(void);

/// Cleanup
void cleanup(void);

/// HtmlOutput
void htmlOutput(int run, string htmlDir, string htmlName);

/// WriteDB
bool writeDb(EcalCondDBInterface* econn, RunIOV* runiov, MonRunIOV* moniov);

template<class T> void AdjustRange(T obj);

/// Get Functions
inline int getEvtPerJob() { return ievt_; }
inline int getEvtPerRun() { return jevt_; }

private:

const static int cryInArray_ = 9;

int ievt_;
int jevt_;

bool cloneME_;

bool verbose_;

bool enableMonitorDaemon_;

string prefixME_;

vector<int> superModules_;

MonitorUserInterface* mui_;
DaqMonitorBEInterface* dbe_;

//specific task me
vector<int> checkedSteps_;
float prescaling_;
//specific task me

TH1F* hBGains_[cryInArray_];
TProfile* hBpulse_[cryInArray_];

TH1F* hBEne1_;

//TH1F* hBGainsMoving_[cryInArray_];
//TH1F* hBEne1Moving_;

TH1F* hBAllNeededCry_;

TH1F* hBNumReadCry_;

TH1F* hBE3x3_;

TH1F* hBE3x3Moving_;

TH2F* hBCryOnBeam_;

TH2F* hBMaxEneCry_;

TH1F* hBReadCryErrors_;

TProfile* hBE1vsCry_;

TProfile* hBE3x3vsCry_;

TH1F* hBEntriesvsCry_;

TH1F* hBcryDone_;

TH2F* hBBeamCentered_;

TH1F* hbTBmoving_;

TH1F* hbE1MaxCry_;

TH1F* hbDesync_;

TProfile* pBCriInBeamEvents_;

MonitorElement* meEBBCaloRedGreen_;
MonitorElement* meEBBCaloRedGreenReadCry_;
MonitorElement* meEBBCaloRedGreenSteps_;

// quality check parameters

int minEvtNum_;

float aveEne1_;
float E1Th_;
float aveEne3x3_;
float E3x3Th_;
float RMSEne3x3_;
float ReadCryErrThr_;

};

#endif
