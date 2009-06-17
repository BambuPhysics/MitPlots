// $Id:$

#ifndef MITANA_DATATREE_PFJETCOLLINKDEF_H
#define MITANA_DATATREE_PFJETCOLLINKDEF_H

#include "MitAna/DataCont/interface/Ref.h"
#include "MitAna/DataTree/interface/PFJetCol.h"
#endif

#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;
#pragma link C++ namespace mithep;

#pragma link C++ class mithep::PFJet+;
#pragma link C++ class mithep::Collection<mithep::PFJet>+;
#pragma link C++ class mithep::Array<mithep::PFJet>+;
#pragma link C++ class mithep::ObjArray<mithep::PFJet>+;
#pragma link C++ class mithep::Ref<mithep::PFJet>+;
#pragma link C++ typedef mithep::PFJetCol;
#pragma link C++ typedef mithep::PFJetArr;
#pragma link C++ typedef mithep::PFJetOArr;
#endif