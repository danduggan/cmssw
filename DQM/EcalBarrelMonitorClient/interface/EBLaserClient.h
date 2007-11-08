#ifndef EBLaserClient_H
#define EBLaserClient_H

/*
 * \file EBLaserClient.h
 *
 * $Date: 2007/09/07 22:30:03 $
 * $Revision: 1.61 $
 * \author G. Della Ricca
 *
*/

#include <vector>
#include <string>

#include "TROOT.h"
#include "TProfile2D.h"
#include "TH1F.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "OnlineDB/EcalCondDB/interface/EcalCondDBInterface.h"
#include "OnlineDB/EcalCondDB/interface/MonRunIOV.h"

#include "DQMServices/Core/interface/MonitorElement.h"
#include "DQMServices/Core/interface/MonitorUserInterface.h"
#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"

#include "DQM/EcalBarrelMonitorClient/interface/EBClient.h"

class EBLaserClient : public EBClient {

friend class EBSummaryClient;

public:

/// Constructor
EBLaserClient(const edm::ParameterSet& ps);

/// Destructor
virtual ~EBLaserClient();

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

/// Get Functions
inline int getEvtPerJob() { return ievt_; }
inline int getEvtPerRun() { return jevt_; }

private:

int ievt_;
int jevt_;

bool cloneME_;

bool verbose_;

bool enableMonitorDaemon_;

string prefixME_;

vector<int> superModules_;

MonitorUserInterface* mui_;
DaqMonitorBEInterface* dbe_;

TProfile2D* h01_[36];
TProfile2D* h02_[36];
TProfile2D* h03_[36];
TProfile2D* h04_[36];
TProfile2D* h05_[36];
TProfile2D* h06_[36];
TProfile2D* h07_[36];
TProfile2D* h08_[36];

TProfile2D* h09_[36];
TProfile2D* h10_[36];
TProfile2D* h11_[36];
TProfile2D* h12_[36];

TProfile2D* h13_[36];
TProfile2D* h14_[36];
TProfile2D* h15_[36];
TProfile2D* h16_[36];
TProfile2D* h17_[36];
TProfile2D* h18_[36];
TProfile2D* h19_[36];
TProfile2D* h20_[36];

TProfile2D* h21_[36];
TProfile2D* h22_[36];
TProfile2D* h23_[36];
TProfile2D* h24_[36];

TProfile2D* hs01_[36];
TProfile2D* hs02_[36];
TProfile2D* hs03_[36];
TProfile2D* hs04_[36];

TProfile2D* hs05_[36];
TProfile2D* hs06_[36];
TProfile2D* hs07_[36];
TProfile2D* hs08_[36];

MonitorElement* meg01_[36];
MonitorElement* meg02_[36];
MonitorElement* meg03_[36];
MonitorElement* meg04_[36];

MonitorElement* meg05_[36];
MonitorElement* meg06_[36];
MonitorElement* meg07_[36];
MonitorElement* meg08_[36];
MonitorElement* meg09_[36];
MonitorElement* meg10_[36];
MonitorElement* meg11_[36];
MonitorElement* meg12_[36];

MonitorElement* mea01_[36];
MonitorElement* mea02_[36];
MonitorElement* mea03_[36];
MonitorElement* mea04_[36];
MonitorElement* mea05_[36];
MonitorElement* mea06_[36];
MonitorElement* mea07_[36];
MonitorElement* mea08_[36];

MonitorElement* met01_[36];
MonitorElement* met02_[36];
MonitorElement* met03_[36];
MonitorElement* met04_[36];
MonitorElement* met05_[36];
MonitorElement* met06_[36];
MonitorElement* met07_[36];
MonitorElement* met08_[36];

MonitorElement* metav01_[36];
MonitorElement* metav02_[36];
MonitorElement* metav03_[36];
MonitorElement* metav04_[36];
MonitorElement* metav05_[36];
MonitorElement* metav06_[36];
MonitorElement* metav07_[36];
MonitorElement* metav08_[36];

MonitorElement* metrms01_[36];
MonitorElement* metrms02_[36];
MonitorElement* metrms03_[36];
MonitorElement* metrms04_[36];
MonitorElement* metrms05_[36];
MonitorElement* metrms06_[36];
MonitorElement* metrms07_[36];
MonitorElement* metrms08_[36];

MonitorElement* meaopn01_[36];
MonitorElement* meaopn02_[36];
MonitorElement* meaopn03_[36];
MonitorElement* meaopn04_[36];
MonitorElement* meaopn05_[36];
MonitorElement* meaopn06_[36];
MonitorElement* meaopn07_[36];
MonitorElement* meaopn08_[36];

MonitorElement* mepnprms01_[36];
MonitorElement* mepnprms02_[36];
MonitorElement* mepnprms03_[36];
MonitorElement* mepnprms04_[36];
MonitorElement* mepnprms05_[36];
MonitorElement* mepnprms06_[36];
MonitorElement* mepnprms07_[36];
MonitorElement* mepnprms08_[36];

TProfile2D* i01_[36];
TProfile2D* i02_[36];
TProfile2D* i03_[36];
TProfile2D* i04_[36];
TProfile2D* i05_[36];
TProfile2D* i06_[36];
TProfile2D* i07_[36];
TProfile2D* i08_[36];
TProfile2D* i09_[36];
TProfile2D* i10_[36];
TProfile2D* i11_[36];
TProfile2D* i12_[36];
TProfile2D* i13_[36];
TProfile2D* i14_[36];
TProfile2D* i15_[36];
TProfile2D* i16_[36];

// Quality check on crystals

float percentVariation_;

// Quality check on PNs

float amplitudeThresholdPnG01_;
float amplitudeThresholdPnG16_;
float pedPnExpectedMean_[2];
float pedPnDiscrepancyMean_[2];
float pedPnRMSThreshold_[2];

};

#endif
