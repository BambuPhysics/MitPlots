//--------------------------------------------------------------------------------------------------
// $Id: SimParticle.h,v 1.1 2008/06/30 16:51:48 loizides Exp $
//
// SimParticle
//
// Details to be worked out...
//
// Authors: J.Bendavid...
//--------------------------------------------------------------------------------------------------

#ifndef DATATREE_SIMPARTICLE_H
#define DATATREE_SIMPARTICLE_H
 
#include <TRef.h>
#include "MitAna/DataTree/interface/GenParticle.h"

namespace mithep 
{
  class SimParticle : public GenParticle
  {
    public:
      SimParticle() {}
      SimParticle(Double_t px, Double_t py, Double_t pz, Double_t e, Int_t id) 
        : GenParticle(px,py,pz,e,id,0) {}
      ~SimParticle() {}
      
      const SimParticle   *GetDaughter(UInt_t i) const;
      const GenParticle*   GetGenParticle()      const;
      Bool_t               IsGenerated()         const { return fGenPartRef.IsValid(); }
      void                 SetGenParticle(GenParticle* p) { fGenPartRef = p; }
      
    protected:
      TRef		   fGenPartRef; //reference to generated particle

    ClassDef(SimParticle,1) // Simulated particle class
  };
}

//--------------------------------------------------------------------------------------------------
inline const mithep::SimParticle *mithep::SimParticle::GetDaughter(UInt_t i) const 
{ 
  // Return daughter corresponding to given index.

  return static_cast<const SimParticle*>(fDaughters.At(i)); 
}

//--------------------------------------------------------------------------------------------------
inline const mithep::GenParticle *mithep::SimParticle::GetGenParticle() const 
{ 
  // Return reference to generated particle.

  return static_cast<const GenParticle*>(fGenPartRef.GetObject()); 
}
#endif