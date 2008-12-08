//--------------------------------------------------------------------------------------------------
// $Id: FullExampleMod.h,v 1.1 2008/11/25 14:30:53 loizides Exp $
//
// FullExampleAnaMod
//
// This TAM module shows how to use TAM. It takes a couple of branches
// and produces a pt and eta distribution.
//
// More information about TAM in general can be found at
// http://www.cmsaf.mit.edu/twiki/bin/view/Software/TAM
//
// Authors: C.Loizides, J.Bendavid
//--------------------------------------------------------------------------------------------------

#ifndef MITANA_PHYSICSMOD_FULLEXAMPLEMOD_H
#define MITANA_PHYSICSMOD_FULLEXAMPLEMOD_H

#include "MitAna/TreeMod/interface/BaseMod.h" 
#include "MitAna/DataTree/interface/Collections.h"

class TH1D;

namespace mithep 
{
  class FullExampleMod : public BaseMod
  {
    public:
      FullExampleMod(const char *name="FullExampleMod", 
                     const char *title="Example analysis module with all branches");
      ~FullExampleMod() {}

    protected:
      void                     Begin();
      void                     Process();
      void                     SlaveBegin();
      void                     SlaveTerminate();
      void                     Terminate();

      TString                  fMCPartName;         //name of particle collection
      TString                  fTrackName;          //name of track collection
      TString                  fMuonName;           //name of muon collection
      TString                  fElectronName;       //name of electron collection
      const MCParticleCol     *fParticles;          //!MCParticle branch
      const TrackCol          *fTracks;	            //!Track branch
      const MuonCol	      *fMuons;              //!Muon branch
      const ElectronCol	      *fElectrons;          //!Electron branch
      TH1D                    *fMCPtHist;           //!MCParticle pt histogram
      TH1D                    *fMCEtaHist;          //!MCParticle eta histogram
      TH1D                    *fTrackPtHist;        //!Track pt histogram
      TH1D                    *fTrackEtaHist;       //!Track eta histogram
      TH1D                    *fMuonPtHist;         //!Muon pt histogram
      TH1D                    *fMuonEtaHist;        //!Muon eta histogram
      TH1D                    *fElectronPtHist;	    //!Electron pt histogram
      TH1D                    *fElectronEtaHist;    //!Electron eta histogram

      ClassDef(FullExampleMod,1) // Full example analysis module
  };
}
#endif