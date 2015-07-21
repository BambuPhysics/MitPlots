//--------------------------------------------------------------------------------------------------
// PlotResolution
//
// This class Plots the resolution of some variable as a function of some other variable
//
// Authors: D.Abercrombie
//--------------------------------------------------------------------------------------------------
#ifndef MITPLOTS_PLOT_PLOTRESOLUTION_H
#define MITPLOTS_PLOT_PLOTRESOLUTION_H

#include <vector>

#include "TTree.h"
#include "TString.h"
#include "TGraph.h"
#include "TCanvas.h"

#include "MitPlots/Container/interface/LegendContainer.h"

namespace mithep
{
  class PlotResolution
  {
  public:
    PlotResolution();
    virtual ~PlotResolution();

    void                   SetCanvasName            ( TString name )                                { fCanvasName = name;         }

    void                   AddLine                  ( TTree *tree, TString cut, TString expr_res );

    void                   SetExprX                 ( TString expr )                                { fInExprX = expr;            }
    void                   SetDefaultTree           ( TTree *tree )                                 { fDefaultTree = tree;        }
    void                   SetDefaultWeight         ( TString cut )                                 { fDefaultCut = cut;          }
    void                   SetDefaultExprRes        ( TString expr_res )                            { fDefaultExprRes = expr_res; }

    void                   SetTreeList              ( std::vector<TTree*> treelist )                { fInTrees = treelist;        }
    void                   AddTree                  ( TTree *tree )                                 { fInTrees.push_back(tree);   }
    void                   AddWeight                ( TString cut )                                 { fInCuts.push_back(cut);     }
    void                   AddExprRes               ( TString expr )                                { fInExprRes.push_back(expr); }
    void                   ResetExprRes             ()                                              { fInExprRes.resize(0);       }
    void                   AddTreeWeight            ( TTree *tree, TString cut );
    void                   AddTreeExprRes           ( TTree *tree, TString expr_res );
    void                   AddWeightExprRes         ( TString cut, TString expr_res );

    void                   SetLegendLimits          ( Double_t lim1, Double_t lim2, Double_t lim3, Double_t lim4 );

    void                   SetLineWidth             ( Int_t width )                                 { fLineWidth = width;         }
    void                   SetParameterLimits       ( Int_t param, Double_t low, Double_t high );

    std::vector<TGraph*>   GetRatioToPoint          ( std::vector<TGraph*> InGraphs, Double_t RatioPoint );
    std::vector<TGraph*>   GetRatioToLine           ( std::vector<TGraph*> InGraphs, TGraph *RatioGraph );

    std::vector<TGraph*>   MakeFitGraphs            ( Int_t NumXBins, Double_t MinX, Double_t MaxX,
                                                      Int_t NumYBins, Double_t MinY, Double_t MaxY,
                                                      Int_t ParamNumber = 1 );

    // The defaults are set up for resolution, but response can be gotten too
    TCanvas*               MakeCanvas               ( LegendContainer *theLegendContainer,
                                                      std::vector<TGraph*> theGraphs, TString XLabel, TString YLabel,
                                                      Double_t YMin, Double_t YMax, Bool_t logY = false);

  private:

    TString                    fCanvasName;         // The name of the output canvas
    TTree*                     fDefaultTree;        // Default Tree if needed
    TString                    fDefaultCut;         // Default cut if needed
    TString                    fDefaultExprRes;     // Default resolution expression if needed

    TString                    fInExprX;            // X Expression should be constant

    Double_t                   l1;
    Double_t                   l2;
    Double_t                   l3;
    Double_t                   l4;

    std::vector<TTree*>        fInTrees;            // Holds all the trees for each line if needed
    std::vector<TString>       fInCuts;             // Holds the cuts for the trees if needed
    std::vector<TString>       fInExprRes;          // Holds multiple resolution expressions if needed

    std::vector<Int_t>         fParams;
    std::vector<Double_t>      fParamLows;
    std::vector<Double_t>      fParamHighs;

    Int_t                      fLineWidth;

    ClassDef(PlotResolution,1)
  };
}

#endif
