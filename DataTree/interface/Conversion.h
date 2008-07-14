//--------------------------------------------------------------------------------------------------
// $Id: Conversion.h,v 1.4 2008/07/08 14:41:01 loizides Exp $
//
// Conversion
//
// Details to be worked out...
//
// Authors: J.Bendavid
//--------------------------------------------------------------------------------------------------

#ifndef DATATREE_CONVERSION_H
#define DATATREE_CONVERSION_H

#include "MitAna/DataTree/interface/CompositeParticle.h"
#include "MitAna/DataTree/interface/FitVertex.h"
#include "MitAna/DataTree/interface/Electron.h"

namespace mithep 
{
  class Conversion : public CompositeParticle
  {
    public:
      Conversion() : CompositeParticle(2), fVertex(0,0,0) {}
      Conversion(Double_t x, Double_t y, Double_t z) : CompositeParticle(2), fVertex(x,y,z) {}
      Conversion(Double_t x, Double_t y, Double_t z, Double_t xErr, Double_t yErr, Double_t zErr) : 
        CompositeParticle(2), fVertex(x,y,z,xErr,yErr,zErr) {}
      ~Conversion() {}
      
      const Electron           *GetDaughter(UInt_t i) const;
      Double_t                  GetDCotTheta()        const { return fDCotTheta; }
      Double_t                  GetEOverP()           const { return fEOverP; }
      Double_t                  GetPairMass()         const { return fPairMass; }
      const ThreeVector        &GetPairMomentum()     const { return fPairMomentum; }
      const FitVertex          &GetVertex()           const { return fVertex; }
      FitVertex                &GetVertex()                 { return fVertex; }
      void                      SetDCotTheta(Double_t dCotTheta) { fDCotTheta = dCotTheta;}
      void                      SetEOverP(Double_t eOverP)       { fEOverP = eOverP;}
      void                      SetPairMass(Double_t pairMass)   { fPairMass = pairMass;}
      void                      SetPairMomentum(Double_t px, Double_t py, Double_t pz);
        
    protected:
      FitVertex                 fVertex;       //reconstructed decay vertex
      Double_t                  fDCotTheta;    //delta cot theta wrt tracks at the conversion point
      Double_t                  fEOverP;       //E over p of conversion tracks
      Double_t                  fPairMass;     //mass of electron-positron pair at conversion point
      ThreeVector               fPairMomentum; //momentum of tracks at conversion point
      
    ClassDef(Conversion,1) // Conversion class
  };
}

//--------------------------------------------------------------------------------------------------
inline const mithep::Electron *mithep::Conversion::GetDaughter(UInt_t i) const 
{ 
  // Return reference to electron daughters.

  return static_cast<const mithep::Electron*>(fDaughters.At(i)); 
}

//--------------------------------------------------------------------------------------------------
inline void mithep::Conversion::SetPairMomentum(Double_t px, Double_t py, Double_t pz)
{ 
  // Set pair momentum.

  fPairMomentum.SetXYZ(px,py,pz);; 
}
#endif