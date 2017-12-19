#include "TMath.h"
#include "TNtuple.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"
#include <vector>
#include <iostream>
#include <string>
#include "TFile.h"

void pandora_pma_vtx_comparisons() {

  // Read in the sample files
  // pma interaction
  TFile *f_pma = new TFile( "/sbnd/app/users/rsjones/LArSoft_v06_56_00/LArSoft-v06_56_00/srcs/recoperformance/recoperformance/plots/SBN_Workshop/single_plots/sbn_single_interaction_nt.root" );

  //TFile *f_pndr = new TFile( "/sbnd/app/users/rsjones/LArSoft_v06_56_00/LArSoft-v06_56_00/srcs/recoperformance/recoperformance/plots/SBN_Workshop/single_plots/sbn_single_interaction_nt.root" );
  
  TTree *t_pma_ev = (TTree*)f_pma->Get("fNt_ev");

  std::vector< float > dX;
  std::vector< float > dY;
  std::vector< float > dZ;
  std::vector< float > dR;

  int n_entries_ev = t_pma_ev->GetEntries();

  for( unsigned int i = 0; i < n_entries_ev; ++i ){
  
    t_pma_ev->GetEntry(i);

    dX.push_back( t_pma_ev->GetLeaf("dx")->GetValue() );
    dY.push_back( t_pma_ev->GetLeaf("dy")->GetValue() );
    dZ.push_back( t_pma_ev->GetLeaf("dz")->GetValue() );
    dR.push_back( t_pma_ev->GetLeaf("dr")->GetValue() );

  }

  TH1D *h_dR           = new TH1D( "h_dR",           "Distance between true and reconstructed vertices",         200,   0, 20);
  TH1D *h_dX           = new TH1D( "h_dX",           "X distance between true and closest reconstructed vertex", 200, -10, 10);
  TH1D *h_dY           = new TH1D( "h_dY",           "Y distance between true and closest reconstructed vertex", 200, -10, 10);
  TH1D *h_dZ           = new TH1D( "h_dZ",           "Z distance between true and closest reconstructed vertex", 200, -10, 10);

  for( int i = 0; i < n_entries_ev; ++i ){

    h_dR->Fill( dR[i] );
    h_dX->Fill( dX[i] );
    h_dY->Fill( dY[i] );
    h_dZ->Fill( dZ[i] );
  
  }

  gStyle->SetPalette(57);
  gStyle->SetNumberContours(250);

  h_dR->SetLineColor(12);
  h_dR->GetXaxis()->SetTitle( "Distance between the true neutrino vertex and the primary (closest) reconstructed vertex (PMA) [cm]" );
  h_dR->GetXaxis()->SetTitleOffset(1.2);

  h_dX->SetLineColor(12);
  h_dX->GetXaxis()->SetTitle( "X distance between the true neutrino vertex and the primary (closest) reconstructed vertex (PMA) [cm]" );
  h_dX->GetXaxis()->SetTitleOffset(1.2);

  h_dY->SetLineColor(12);
  h_dY->GetXaxis()->SetTitle( "Y distance between the true neutrino vertex and the primary (closest) reconstructed vertex (PMA) [cm]" );
  h_dY->GetXaxis()->SetTitleOffset(1.2);

  h_dZ->SetLineColor(12);
  h_dZ->GetXaxis()->SetTitle( "Z distance between the true neutrino vertex and the primary (closest) reconstructed vertex (PMA) [cm]" );
  h_dZ->GetXaxis()->SetTitleOffset(1.2);

  TCanvas *c  = new TCanvas( "c", "Canvas", 800, 600 );

  h_dR->Draw();
  c->SaveAs( "/sbnd/app/users/rsjones/LArSoft_v06_56_00/LArSoft-v06_56_00/srcs/pandoratesting/pandoratesting/plots/pandora_pma_closest_primary_vtx_comp.root" );
  c->Clear();

  h_dX->Draw();
  c->SaveAs( "/sbnd/app/users/rsjones/LArSoft_v06_56_00/LArSoft-v06_56_00/srcs/pandoratesting/pandoratesting/plots/pandora_pma_closest_primary_vtx_comp_x.root" );
  c->Clear();

  h_dY->Draw();
  c->SaveAs( "/sbnd/app/users/rsjones/LArSoft_v06_56_00/LArSoft-v06_56_00/srcs/pandoratesting/pandoratesting/plots/pandora_pma_closest_primary_vtx_comp_y.root" );
  c->Clear();

  h_dZ->Draw();
  c->SaveAs( "/sbnd/app/users/rsjones/LArSoft_v06_56_00/LArSoft-v06_56_00/srcs/pandoratesting/pandoratesting/plots/pandora_pma_closest_primary_vtx_comp_z.root" );
  c->Clear();

}
