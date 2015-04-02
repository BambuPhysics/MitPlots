// $Id: PFCandidateColLinkDef.h,v 1.1 2009/06/15 15:00:15 loizides Exp $

#ifndef MITANA_DATATREE_PFCANDIDATECOLLINKDEF_H
#define MITANA_DATATREE_PFCANDIDATECOLLINKDEF_H

#include "MitAna/DataCont/interface/RefArray.h"
#include "MitAna/DataCont/interface/Ref.h"
#include "MitAna/DataTree/interface/PFCandidateCol.h"
#endif

#ifndef __CLING__
#   define _R__UNIQUEIDENTIFIER_ PFCandidateCol
#   define _R__JOIN3_(F,X,Y) _NAME3_(F,X,Y)
#   undef _R__UNIQUE_
#   define _R__UNIQUE_(X) _R__JOIN3_( _R__UNIQUEIDENTIFIER_,X,__LINE__)
#endif

#ifdef __CLING__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;
#pragma link C++ namespace mithep;

#pragma link C++ class mithep::Ref<mithep::PFCandidate>+;
#pragma link C++ class mithep::PFCandidate+;
#pragma link C++ class mithep::Collection<mithep::PFCandidate>+;
#pragma link C++ class mithep::Array<mithep::PFCandidate>+;
#pragma link C++ class mithep::ObjArray<mithep::PFCandidate>+;
#pragma link C++ class mithep::RefArray<mithep::PFCandidate>+;
#pragma link C++ typedef mithep::PFCandidateCol;
#pragma link C++ typedef mithep::PFCandidateArr;
#pragma link C++ typedef mithep::PFCandidateOArr;
#endif
